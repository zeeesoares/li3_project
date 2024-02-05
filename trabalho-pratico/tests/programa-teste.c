#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include "batch.h"
#include "date.h"
#include "parser.h"
#include "output.h"
#include "flights_catalog.h"
#include "queries.h"
#include "passengers_catalog.h"
#include "catalog_manager.h"
#include "user_catalog.h"
#include "reservation_catalog.h"
#include "stats.h"

// novo batch

CatalogManager* batch_t(char** arg) {
    setlocale(LC_COLLATE, "en_US.UTF-8");

    UserCatalog* user_catalog = create_user_catalog();
    if (user_catalog == NULL) {
        perror("Error creating user_catalog");
        exit(1);
    }
    
    FlightCatalog* flight_catalog = create_flight_catalog();
    if (flight_catalog == NULL) {
        perror("Error creating flight_catalog");
        exit(1);
    }

    ReservationCatalog* reservation_catalog = create_reservation_catalog();
    if (reservation_catalog == NULL) {
        perror("Error creating reservation_catalog");
        exit(1);
    }

    HotelCatalog* hotel_catalog = create_hotel_catalog();
    if (hotel_catalog == NULL) {
        perror("Error creating hotel_catalog");
        exit(1);
    }

    AirportCatalog* airport_catalog = create_airport_catalog();
    if (airport_catalog == NULL) {
        perror("Error creating airport_catalog");
        exit(1);
    }

    MetricsTable* metrics_table = create_metrics_table();
    if (metrics_table == NULL) {
        perror("Error creating metrics_table");
        exit(1);
    }

    CatalogManager* catalog_manager = create_catalog_manager(user_catalog, flight_catalog, reservation_catalog, hotel_catalog, airport_catalog, metrics_table);
    if (catalog_manager == NULL) {
        perror("Error creating catalog_manager");
        exit(1);
    }

    setup_catalog(catalog_manager, arg[1]);

    FILE *queries_file = fopen(arg[2], "r");
    if (queries_file == NULL) {
        perror("Error opening queries file");
        exit(EXIT_FAILURE);
    }

    return catalog_manager;
}

int compare_query(const char* outputFolder, int query_number) {
    int ret = 0;
    char query_result_filename[256];
    char expected_result_filename[256];

    snprintf(query_result_filename, sizeof(query_result_filename), "%s/command%d_output.txt", "Resultados", query_number);
    snprintf(expected_result_filename, sizeof(expected_result_filename), "%s/command%d_output.txt", outputFolder, query_number);

    struct timespec start, end;
    double elapsed;

    clock_gettime(CLOCK_REALTIME, &start);

    FILE* query_result_file = fopen(query_result_filename, "r");
    FILE* expected_result_file = fopen(expected_result_filename, "r");

    if (query_result_file == NULL || expected_result_file == NULL) {
        perror("Error opening files");
        exit(0);
    }

    char query_line[256];
    char expected_line[256];
    int line_number = 1;

    while (1) {
        // Ler as linhas dos arquivos
        char* query_read = fgets(query_line, sizeof(query_line), query_result_file);
        char* expected_read = fgets(expected_line, sizeof(expected_line), expected_result_file);

        // Verificar se ambos os arquivos atingiram o final
        if (query_read == NULL && expected_read == NULL) {
            break;  // Ambos os arquivos atingiram o final, a comparação está completa
        }

        // Verificar se um dos arquivos atingiu o final antes do outro
        if ((query_read == NULL && expected_read != NULL) || (query_read != NULL && expected_read == NULL)) {
            printf("Incongruence found in Query %d at line %d\n", query_number, line_number);
            ret = query_number;
            break;
        }

        // Comparar as linhas
        if (strcmp(query_line, expected_line) != 0) {
            printf("Incongruence found in Query %d at line %d\n", query_number, line_number);
            ret = query_number;
            break;
        }

        line_number++;
    }

    clock_gettime(CLOCK_REALTIME, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Comparison for Query %d - Elapsed time: %.6f seconds\n", query_number, elapsed);

    printf("\n");

    fclose(query_result_file);
    fclose(expected_result_file);
    
    return ret;
}



int execute_query(const char* commandFile, const char* outputFolder, CatalogManager* catalog_manager) {
    int ret = 0;
    int res = 0;


    FILE* query_file = fopen(commandFile, "r");
    if (query_file == NULL) {
        perror("Error opening query file");
        exit(EXIT_FAILURE);
    }

    // Medição do tempo de execução
    struct timespec start, end;
    double elapsed;


    char *line = NULL;
    size_t line_size = 0;
    ssize_t bytesRead;
    int line_number = 1;
    while ((bytesRead = getline(&line, &line_size, query_file)) != -1) {
        line[strlen(line) - 1] = '\0';

        clock_gettime(CLOCK_REALTIME, &start);
        FILE* output_file = create_output_query_file(line_number);
        if (output_file == NULL) {
           perror("Error opening output file");
           exit(EXIT_FAILURE);
        }
        // Executa a consulta
        execute_command(line, catalog_manager, output_file);

        clock_gettime(CLOCK_REALTIME, &end);
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        fclose(output_file);

        printf("Query %d - Elapsed execution time: %.6f seconds\n", line_number, elapsed);
        
        res = compare_query(outputFolder,line_number);
        if (ret == 0 && res > ret)
            ret = res;

        line_number++;
    }




    // Fecha os arquivos
    fclose(query_file);

    free(line);

    return ret;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <dataset_path> <command_file> <output_folder>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* commandFile = argv[2];
    const char* outputFolder = argv[3];
    
    CatalogManager* catalog_manager = NULL;
    
    FILE* queries_file = fopen(commandFile, "r");
    if (queries_file == NULL) {
        perror("Error opening queries file");
        exit(EXIT_FAILURE);
    }


    // Medição do tempo de execução geral
    struct timespec start_all, end_all;
    double elapsed_all;

    clock_gettime(CLOCK_REALTIME, &start_all);

    catalog_manager = batch_t(argv);

    int ret = execute_query(commandFile, outputFolder, catalog_manager);

    if (ret == 0) {
        printf("==========================================\n");
        printf("  All the tests passed, well done folks!\n");
        printf("==========================================\n\n");
    }
    else {
        printf("==================================================================\n");
        printf("  Some tests have failed, the first incongruence is at Query %d!\n", ret);
        printf("==================================================================\n\n");
    }

    clock_gettime(CLOCK_REALTIME, &end_all);
    elapsed_all = (end_all.tv_sec - start_all.tv_sec) + (end_all.tv_nsec - start_all.tv_nsec) / 1e9;

    printf("Total Elapsed Time: %.6f seconds\n", elapsed_all);

    // Medição da memória utilizada
    struct rusage r_usage;
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Total Memory usage: %ld KB\n", r_usage.ru_maxrss);

    // Liberar recursos
    destroy_user_catalog(get_user_catalog(catalog_manager));
    destroy_flight_catalog(get_flight_catalog(catalog_manager));
    destroy_reservation_catalog(get_reservation_catalog(catalog_manager));
    destroy_hotel_catalog(get_hotel_catalog(catalog_manager));
    destroy_airport_catalog(get_airport_catalog(catalog_manager));
    destroy_metrics_table(get_metrics_table(catalog_manager));
    free(catalog_manager);

    fclose(queries_file);


    return 0;
}
