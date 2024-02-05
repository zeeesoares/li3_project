#include "flight.h"
#include "utils.h"
#include "flights_catalog.h"

typedef struct flight {
    int id;                             
    char* airline;                        
    char* plane_model;                    
    int total_seats;                      
    char* origin;                         
    char* destination;                 
    Date* schedule_departure_date;        
    Date* schedule_arrival_date;         
    Date* real_departure_date;                              
    int delay;

} Flight;

Flight* create_flight() {
    Flight* new = (Flight*)malloc(sizeof(Flight));
    if (new == NULL) {
        return NULL;
    }
    return new;
}

Flight* build_flight(char** tokens) {
    if (!validate_flight(tokens)) return NULL;

    Flight* flight = create_flight();
    
    set_flight_id(flight, atoi(tokens[0]));
    set_flight_airline(flight,tokens[1]);
    set_flight_planemodel(flight,tokens[2]);
    set_flight_totalseats(flight,0);
    set_flight_origin(flight,tokens[4]);
    set_flight_destination(flight,tokens[5]);
    set_flight_schedule_departure_date(flight,tokens[6]);
    set_flight_schedule_arrival_date(flight,tokens[7]);
    set_flight_real_departure_date(flight,tokens[8]);
    set_flight_delay(flight);

    return flight;
}

//SETS

void set_flight_id(Flight* flight, int token) {
    flight->id = token;
}

void set_flight_airline(Flight* flight, char* token) {
    flight->airline = strdup(token);
}

void set_flight_planemodel(Flight* flight, char* token) {
    flight->plane_model = strdup(token);
}

void set_flight_totalseats(Flight* flight, int num) {
    flight->total_seats = num;
}

void set_flight_origin(Flight* flight, char* token) {
    convert_to_uppercase(token);
    flight->origin = strdup(token);
}

void set_flight_destination(Flight* flight, char* token) {
    convert_to_uppercase(token);
    flight->destination = strdup(token);
}

void set_flight_schedule_departure_date(Flight* flight, char* token)  {
    flight->schedule_departure_date = parse_date(token);
}

void set_flight_schedule_arrival_date(Flight* flight, char* token) {
    flight->schedule_arrival_date = parse_date(token);
}

void set_flight_real_departure_date(Flight* flight, char* token) {
    flight->real_departure_date = parse_date(token);
}

void  set_flight_delay(Flight* flight) {
    flight->delay = calculate_delay(flight->schedule_departure_date, flight->real_departure_date);
}

//GETS

int get_flight_id(Flight* flight) {
    return flight->id;
}

char* get_flight_airline(Flight* flight) {
    return strdup(flight->airline);
}

char* get_flight_planemodel(Flight* flight) {
    return strdup(flight->plane_model);
}

int get_flight_totalseats(Flight* flight) {
    return flight->total_seats;
}

char* get_flight_origin(Flight* flight) {
    return strdup(flight->origin);
}

char* get_flight_destination(Flight* flight) {
    return strdup(flight->destination);
}

Date* get_flight_schedule_departure_date(Flight* flight) {
    return flight->schedule_departure_date;
}

Date* get_flight_schedule_arrival_date(Flight* flight) {
    return flight->schedule_arrival_date;
}

Date* get_flight_real_departure_date(Flight* flight) {
    return flight->real_departure_date;
}

int get_flight_delay(Flight* flight) {
    return flight->delay;
}



void freeFlight(Flight* flight) {
    if (flight) {
        free(flight->airline);
        free(flight->plane_model);
        free(flight->origin);
        free(flight->destination);
        free(flight->schedule_departure_date);
        free(flight->schedule_arrival_date);
        free(flight->real_departure_date);
    }
    free(flight);
}