#include "output.h"
#include "queries.h"
#include "parser.h"
#include "user_catalog.h"
#include "flights_catalog.h"
#include "reservation_catalog.h"
#include "passengers_catalog.h"
#include "string.h"
#include "date.h"
#include "utils.h"
#include <ctype.h>
#include "airport_catalog.h"
#include "hotel_catalog.h"
#include "query_services.h"



typedef struct command {
    int type;
    int flag;
    int num_args;
    char ** args;
} command;


int get_cmd_type (command* cmd) {
    return cmd->type;
}

int get_cmd_flag (command* cmd) {
    return cmd->flag;
}

int get_cmd_num_args (command* cmd) {
    return cmd->num_args;
}

char* get_cmd_args (command* cmd, int index) {
    return cmd->args[index];
}


command* build_command(char** tokens, int num_tokens) {
    command* cmd = malloc(sizeof(command));
    if (cmd == NULL) {
        perror("Failed to allocate memory for command");
        exit(EXIT_FAILURE);
    }

    cmd->type = atoi(tokens[0]);

    if (cmd->type < 10) {
        if (strlen(tokens[0]) != 1)
            cmd->flag = 1;
        else 
            cmd->flag = 0;
    }
    else {
        if (strlen(tokens[0]) != 2)
            cmd->flag = 1;
        else 
            cmd->flag = 0;
    }


    int count = 0;
    for (int i = 1; i < num_tokens; i++) {
        if (tokens[i] != NULL)
            count++;
    }
    cmd->num_args = count;

    cmd->args = malloc(sizeof(char*) * count);
    if (cmd->args == NULL) {
        perror("Failed to allocate memory for arguments");
        exit(EXIT_FAILURE);
    }

    int args_index = 0;
    for (int i = 1; i < num_tokens; i++) {
        if (tokens[i] != NULL) {
            cmd->args[args_index] = strdup(tokens[i]);
            args_index++;
        }
    }

    return cmd;
}

int get_query_command(command* cmd) {
    return cmd->type;
}

void execute_command (char* line, CatalogManager* catalog, FILE* output_file) {
    char** tokens = parse_query_line(line,10);
    command* cmd = build_command(tokens, 6);
    free_tokens(tokens,6);

    void* result = NULL;
    switch (cmd->type)
    {
    case 1:
        result = query1(cmd, catalog);
        break;
    case 2:
        result = query2(cmd, catalog);
        break;
    case 3:
        result = query3(cmd,catalog);
        break;
    case 4:
        result = query4(cmd, catalog);
        break;
    case 5:
        result = query5(cmd, catalog);
        break;
    case 6:
        result = query6(cmd, catalog);
        break;
    case 7:
        result = query7(cmd, catalog);
        break;
    case 8:
        result = query8(cmd,catalog);
        break;
    case 9:
        result = query9(cmd,catalog);
        break;
    case 10:
        result = query10(cmd,catalog);
        break;     
    default:
        break;
    }

    if (result)
        write_output_queries_file(result,cmd->type,output_file);
    
    free_command(cmd);
}

void* execute_command_interactive(command* cmd, CatalogManager* catalog) {
    void* result = NULL;
    switch (cmd->type)
    {
    case 1:
        result = query1(cmd, catalog);
        break;
    case 2:
        result = query2(cmd, catalog);
        break;
    case 3:
        result = query3(cmd,catalog);
        break;
    case 4:
        result = query4(cmd, catalog);
        break;
    case 5:
        result = query5(cmd, catalog);
        break;
    case 6:
        result = query6(cmd, catalog);
        break;
    case 7:
        result = query7(cmd, catalog);
        break;
    case 8:
        result = query8(cmd,catalog);
        break;
    case 9:
        result = query9(cmd,catalog);
        break;
    case 10:
        result = query10(cmd,catalog);
        break;     
    default:
        break;
    }

    return result;
}


int validate_command(command* cmd) {
    int num_args = cmd->num_args;
    int query = cmd->type;
    int res = 1;

    if (query > 10 || query < 1) return 0;

    switch (query)
    {
    case 1:
        if (num_args != 1) res = 0;
        break;
    case 2:
        if (num_args != 1 && num_args != 2) res = 0;
        break;
    case 3:
        if (num_args != 1) res = 0;
        break;
    case 4:
        if (num_args != 1) res = 0;
        break;
    case 5:
        if (num_args != 5) res = 0;
        break;
    case 6:
        if (num_args != 2) res = 0;
        break;
    case 7:
        if (num_args != 1) res = 0;
        break;
    case 8:
        if (num_args != 3) res = 0;
        break;
    case 9:
        if (num_args == 0) res = 0;
        break;
    case 10:
        if (num_args > 2 ) res = 0;
    default:
        break;
    }
    return res;
}


char** parse_query_line(char* line, int num_tokens) {
    char **tokens = malloc(sizeof(char *) * (num_tokens));

    if (tokens == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_tokens; i++) {
        tokens[i] = NULL;
    }

    int token_counter = 0;
    int in_quotes = 0; 

    while (token_counter < num_tokens) {
        char* token = strsep(&line, " ");

        if (token == NULL) {
            break;
        } else {
            if (token[0] == '"') {
                in_quotes = 1;
                token++;
            }

            if (token[strlen(token) - 1] == '"') {
                in_quotes = 0;
                token[strlen(token) - 1] = '\0';
            }

            if (in_quotes && tokens[token_counter] != NULL) {
                tokens[token_counter] = realloc(tokens[token_counter], strlen(tokens[token_counter]) + strlen(token) + 2);
                strcat(tokens[token_counter], " ");
                strcat(tokens[token_counter], token);
            } else {
                tokens[token_counter++] = strdup(token);
            }   
        }
    }

    num_tokens = token_counter;
    return tokens;
}



void* query1(command* cmd, CatalogManager* catalog) {
    char* id = cmd->args[0];
    int flag_user_id = compare_ids(id);

    Q1_results* results = NULL;

    switch (flag_user_id)
    {
    case 0:
        results = get_query1_user_results(cmd,get_user_catalog(catalog));
        return (void*)results;
        break;

    case 1:
        results = get_query1_flight_results(cmd,get_flight_catalog(catalog));
        return (void*)results;
        break;

    case 2:
        results = get_query1_reservation_results(cmd,get_reservation_catalog(catalog));
        return (void*)results;
        break;
    default:
        return NULL;
        break;
    }
    return NULL;
}

//QUERY2


void* query2(command* cmd, CatalogManager* catalog_manager) {
    char* id = cmd->args[0];

    int data_type = 0;
    if (cmd->num_args > 1) {  
        if (strstr(cmd->args[1], "res") != NULL)
            data_type = 2;
        else 
            data_type = 1;
    }

    User* user = get_user(get_user_catalog(catalog_manager), id);

    int user_status;
    if (user)
        user_status = get_user_account_status(user);

    if (user != NULL && user_status) {
        Q2_results* result = NULL;

        switch (data_type)
        {
        case 0:
            result = get_query2_flighs_and_reservations(cmd,user,catalog_manager);
            break;
        case 1:
            result = get_query2_flighs(cmd,user, catalog_manager);
            break;
        case 2:
            result = get_query2_reservations(cmd,user, catalog_manager);
            break;
        default:
            break;
        }
        return (void*)result;
    }
    return NULL;
}

//QUERY3

void* query3(command* cmd, CatalogManager* catalog_manager){
    char* hotel_id= cmd->args[0];

    HotelCatalog* hotel_catalog = get_hotel_catalog(catalog_manager);
    Hotel* hotel = get_hotel(hotel_catalog, atoi(hotel_id+3));

    Q3_results* result = get_query3_rating(cmd,hotel);
    return (void*)result;

}

//QUERIE 4

void* query4(command* cmd, CatalogManager* catalog_manager){
    int hotel_id= atoi(cmd->args[0]+3);

    HotelCatalog* catalog = get_hotel_catalog(catalog_manager);
    Hotel* hotel = get_hotel(catalog,hotel_id);

    Q4_results* result = get_query4_result(cmd, hotel, get_reservation_catalog(catalog_manager));
    return result;
}


//QUERY5

void* query5(command* cmd, CatalogManager* catalog_manager) {
    char** args = cmd->args;

    AirportCatalog* airports = get_airport_catalog(catalog_manager);
    Airport* airport = get_airport(airports, args[0]);
    
    Q5_results* result = get_query5_results(cmd,airport,get_flight_catalog(catalog_manager));
    return result;
}


//QUERY 6

void* query6(command* cmd, CatalogManager* catalog_manager) {
    Q6_results* result = get_query6_results(cmd, get_airport_catalog(catalog_manager));
    return (void*)result;
}

//QUERY7

void* query7(command* cmd, CatalogManager* catalog_manager) {
    AirportCatalog* airport_catalog = get_airport_catalog(catalog_manager);
    Q7_results* results = get_query7_results(cmd,airport_catalog);
    return results; 
}

//QUERY8

void* query8(command* cmd, CatalogManager* catalog_manager) {
    int hotel_id= atoi(cmd->args[0]+3);
    HotelCatalog* catalog = get_hotel_catalog(catalog_manager);
    Hotel* hotel = get_hotel(catalog,hotel_id);
    Q8_results* results = get_query8_results(cmd,hotel,get_reservation_catalog(catalog_manager));
    return (void*)results;
}

//QUERY9

void* query9(command* cmd, CatalogManager* catalog_manager) {
    UserCatalog* catalog = get_user_catalog(catalog_manager);

    char prefixo[1024] = "";  // Tamanho máximo para prefixo (ajuste conforme necessário)

    for (int i = 0; i < cmd->num_args; i++) {
        strcat(prefixo, cmd->args[i]);
        if (i < cmd->num_args - 1) {
            strcat(prefixo, " ");
        }
    }

    Q9_results* results = get_query9_results(cmd, catalog,prefixo);
    return (void*)results;
}


//QUERY10

void* query10(command* cmd, CatalogManager* catalog_manager) {
    int num_args = cmd->num_args;

    MetricsTable* table = get_metrics_table(catalog_manager);

    Q10_results* results;
    if (cmd->args) {
        switch (num_args)
        {
        case 0:
            results = get_query10_results_year(cmd,table);
            break;

        case 1:
            results = get_query10_results_month(cmd,table);
            break;

        case 2:
            results = get_query10_results_day(cmd,table);
            break;
        default:
            results = NULL;
            break;
        }
        return (void*)results;
    }
    else return NULL;
}

void free_command(command* cmd) {
    if (cmd == NULL) {
        return;
    }
    for (int i = 0; i < cmd->num_args; i++) {
        free(cmd->args[i]);
    }
    free(cmd->args);
    free(cmd);
}