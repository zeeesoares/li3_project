#include "airport.h"

#define BASE_YEAR 2010
#define MAX_YEARS 2025

typedef struct airport {
    char* id;
    int* flights;
    int* delays;
    int* num_passengers_per_year; 
    int count;
    int num_passengers;
} Airport;


Airport* create_airport() {
    Airport* new = (Airport*)malloc(sizeof(Airport));
    if (new == NULL) {
        return NULL;
    }
    new->flights = NULL;
    new->delays = NULL;
    new->count = 0;
    new->num_passengers = 0;
    new->id = NULL;
    new->num_passengers_per_year = NULL;  // Adição da inicialização para o novo campo
    return new;
}

Airport* build_airport(char* id, int flight, int delay) {
    Airport* airport = create_airport();
    convert_to_uppercase(id);
    set_airport_catalog_id(airport,id);
    set_airport_num_passengers(airport,1);
    set_airport_num_flights(airport,1);
    airport->flights = g_new(int, 1);
    airport->flights[0] = flight;
    airport->delays = g_new(int, 1);
    airport->delays[0] = delay;
    return airport;
}


char* get_airport_catalog_id(Airport* airport) {
    return airport->id;
}

int get_airport_num_flights(Airport* airport) {
    return airport->count;
}

int* get_airport_flights(Airport* airport) {
    return airport->flights;
}

int* get_airport_delays(Airport* airport) {
    return airport->delays;
}

int* get_airport_num_passengers_per_year(Airport* airport) {
    return airport->num_passengers_per_year;
}

int get_airport_num_passengers(Airport* airport) {
    return airport->num_passengers;
}

int get_passengers_by_year(Airport* airport, int year) {
    if (airport && airport->num_passengers_per_year) {
        if (year >= BASE_YEAR && year < BASE_YEAR + MAX_YEARS) {
            return airport->num_passengers_per_year[year - BASE_YEAR];
        } else {
            fprintf(stderr, "Ano fora do intervalo esperado.\n");
            return -1;  
        }
    }
    return 0;  
}

void set_airport_catalog_id(Airport* airport, char* id) {
    airport->id = strdup(id);
}

void set_airport_num_flights(Airport* airport, int count) {
    airport->count = count;
}

void set_airport_flights(Airport* airport, int* flights) {
    airport->flights = flights;
}

void set_airport_delays(Airport* airport, int* delays) {
    airport->delays = delays;
}

void set_airport_num_passengers(Airport* airport, int num_passengers) {
    airport->num_passengers = num_passengers;
}

void set_airport_num_passengers_per_year(Airport* airport, int* new_passengers) {
    airport->num_passengers_per_year = new_passengers;
}
