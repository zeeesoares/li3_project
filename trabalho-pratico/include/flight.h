#ifndef FLIGHTS_H
#define FLIGHTS_H

#define flights_fields 13

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"


typedef struct flight Flight;


/*
 * Creates a new Flight (entity).
 *
 * @returns A pointer to the newly created Flight.
 */
Flight* create_flight(); 

/*
 * Builds a Flight instance from a CSV line.
 *
 * @param line A line of CSV data.
 * @returns A pointer to the created Flight instance.
 */
Flight* build_flight(char** line);

/*
 * Gets the flight ID.
 *
 * @param flight A pointer to the Flight.
 * @returns The flight ID.
 */
int get_flight_id(Flight* flight);

/*
 * Gets the airline of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The airline of the flight.
 */
char* get_flight_airline(Flight* flight);

/*
 * Gets the plane model of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The plane model of the flight.
 */
char* get_flight_planemodel(Flight* flight);

/*
 * Gets the total number of seats in the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The total number of seats in the flight.
 */
int get_flight_totalseats(Flight* flight);

/*
 * Gets the origin of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The origin of the flight.
 */
char* get_flight_origin(Flight* flight);

/*
 * Gets the destination of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The destination of the flight.
 */
char* get_flight_destination(Flight* flight);

/*
 * Gets the scheduled departure date of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The scheduled departure date of the flight.
 */
Date* get_flight_schedule_departure_date(Flight* flight);

/*
 * Gets the scheduled arrival date of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The scheduled arrival date of the flight.
 */
Date* get_flight_schedule_arrival_date(Flight* flight);

/*
 * Gets the real departure date of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The real departure date of the flight.
 */
Date* get_flight_real_departure_date(Flight* flight);

/*
 * Gets the real arrival date of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The real arrival date of the flight.
 */
Date* get_flight_real_arrival_date(Flight* flight);


/*
 * Gets the delay time of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The delay time of the flight.
 */
int get_flight_delay(Flight* flight);

/*
 * Gets the users list of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The users list of the flight.
 */
char** get_flight_users(Flight* flight);

/*
 * Gets the number of users of the Flight.
 *
 * @param flight A pointer to the Flight instance.
 * @returns The number of users of the flight.
 */
int get_flight_num_users(Flight* flight);




/*
 * Sets the flight ID.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The flight ID to be set.
 */
void set_flight_id(Flight* flight, int token);

/*
 * Sets the airline of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The airline of the flight to be set.
 */
void set_flight_airline(Flight* flight, char* token);

/*
 * Sets the plane model of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The plane model of the flight to be set.
 */
void set_flight_planemodel(Flight* flight, char* token);

/*
 * Sets the total number of seats in the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param num The total number of seats in the flight to be set.
 */
void set_flight_totalseats(Flight* flight, int num);

/*
 * Sets the origin airport of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The origin airport of the flight to be set.
 */
void set_flight_origin(Flight* flight, char* token);

/*
 * Sets the destination airport of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The destination airport of the flight to be set.
 */
void set_flight_destination(Flight* flight, char* token);

/*
 * Sets the scheduled departure date of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The scheduled departure date of the flight to be set.
 */
void set_flight_schedule_departure_date(Flight* flight, char* token);

/*
 * Sets the scheduled arrival date of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The scheduled arrival date of the flight to be set.
 */
void set_flight_schedule_arrival_date(Flight* flight, char* token);

/*
 * Sets the real departure date of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The real departure date of the flight to be set.
 */
void set_flight_real_departure_date(Flight* flight, char* token);

/*
 * Sets the real arrival date of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param token The real arrival date of the flight to be set.
 */
void set_flight_real_arrival_date(Flight* flight, char* token);

/*
 * Sets the delay time of the flight.
 *
 * @param flight A pointer to the Flight instance.
 */
void set_flight_delay(Flight* flight);

/*
 * Sets the users of the flight.
 *
 * @param flight A pointer to the Flight instance.
 */
void set_flight_users(Flight* flight);

/*
 * Sets the number of users of the flight.
 *
 * @param flight A pointer to the Flight instance.
 * @param num Number of users
 */
void set_flight_num_users(Flight* flight, int num);

/*
 * Prints the details of a Flight.
 *
 * @param flight A pointer to the Flight instance.
 */
void print_flight(Flight* flight);

/*
 * Frees the memory allocated for a Flight instance.
 *
 * @param flight A pointer to the Flight instance.
 */
void freeFlight(Flight* flight);


/**
 * @brief Adds a user to the list of passengers for a given Flight.
 *
 * @param flight A pointer to the Flight structure to which the user will be added.
 * @param user The username or identifier of the user to be added.
 */
void add_user_to_flight(Flight* flight, char* user);

/**
 * @brief Gets the departure date of a Flight.
 *
 * @param flight A pointer to the Flight structure from which to retrieve the departure date.
 * @return The departure date of the Flight.
 */
int get_departure_date(Flight* flight);

/**
 * @brief Sets the departure date of a Flight based on a given date string token.
 *
 * @param flight A pointer to the Flight structure for which to set the departure date.
 * @param token The date string token representing the new departure date.
 */
void set_departure_date(Flight* flight, char* token);

#endif
