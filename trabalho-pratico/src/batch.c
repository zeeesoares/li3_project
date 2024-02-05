#include "batch.h"

typedef enum {
    USERS,
    FLIGHTS,
    PASSENGERS,
    RESERVATIONS
} CatalogType;


int batch(char** arg) {
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
    if (catalog_manager== NULL) {
        perror("Error creating catalog_manager");
        exit(1);
    }

    setup_catalog(catalog_manager, arg[1]);

    FILE *queries_file = fopen(arg[2], "r");
    if (queries_file == NULL) {
        perror("Error opening queries file");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t line_size = 0;
    int queries_counter = 1;
    ssize_t bytesRead;
    while ((bytesRead = getline(&line, &line_size, queries_file)) != -1) {
        line[strlen(line) - 1] = '\0';

        FILE *output_file = create_output_query_file(queries_counter);
        if (output_file == NULL) {
            perror("Error opening queries file");
            exit(1);
        }

        execute_command(line, catalog_manager, output_file);

        fclose(output_file);
        queries_counter++;
    }
    free(line);
    fclose(queries_file);


    destroy_user_catalog(get_user_catalog(catalog_manager)); 
    destroy_flight_catalog(get_flight_catalog(catalog_manager)); 
    destroy_reservation_catalog(get_reservation_catalog(catalog_manager));
    destroy_hotel_catalog(get_hotel_catalog(catalog_manager));
    destroy_airport_catalog(get_airport_catalog(catalog_manager));
    destroy_metrics_table(get_metrics_table(catalog_manager));

    free(catalog_manager);

    return 0;
}

int setup_catalog(CatalogManager* catalog, char *folder) {
    //USERS
    char *users_filename = create_filename(folder, "/users.csv");
    char *users_error_filename = "Resultados/users_errors.csv";
    FILE *users_file = fopen(users_filename, "r");
    FILE *users_error_file = fopen(users_error_filename, "a");
    if (users_file == NULL) {
      return 1;
    }
    free(users_filename);

    parse_csv_file(users_file, (void*)catalog, build_and_add_user_manager, validate_user, users_error_file, 12);

    fclose(users_error_file);
    
    //FLIGHTS
    char *flights_filename = create_filename(folder, "/flights.csv");
    char *flights_error_filename = "Resultados/flights_errors.csv";
    FILE *flights_error_file = fopen(flights_error_filename, "a");
    FILE *flights_file = fopen(flights_filename, "r");
    if (flights_file == NULL) {
      return 1;
    }
    free(flights_filename);

    parse_csv_file(flights_file, (void*)catalog, build_and_add_flight_manager, validate_flight, flights_error_file, 13);

    fclose(flights_error_file);
    //PASSENGERS
    char *passengers_filename = create_filename(folder, "/passengers.csv");
    char *passengers_error_filename = "Resultados/passengers_errors.csv";
    FILE *passengers_error_file = fopen(passengers_error_filename, "a");
    FILE *passengers_file = fopen(passengers_filename, "r");
    if (passengers_file == NULL) {
      return 1;
    }
    free(passengers_filename);

    parse_csv_file(passengers_file, (void*)catalog, build_and_add_passenger_manager, validate_passenger,passengers_error_file,2);
    
    fclose(passengers_error_file);
    //RESERVATIONS
    char *reservations_filename = create_filename(folder, "/reservations.csv");
    char *reservations_error_filename = "Resultados/reservations_errors.csv";
    FILE *reservations_error_file = fopen(reservations_error_filename, "a");
    FILE *reservations_file = fopen(reservations_filename, "r");
    if (reservations_file == NULL) {
      return 1;
    }
    free(reservations_filename);
    
    parse_csv_file(reservations_file, (void*)catalog, build_and_add_reservation_manager, validate_reservations, reservations_error_file, 14);

    fclose(reservations_error_file);




    fclose(users_file);
    fclose(flights_file);
    fclose(passengers_file);
    fclose(reservations_file);

    return 0;
}
    