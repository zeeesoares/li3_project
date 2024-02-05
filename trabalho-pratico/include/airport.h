#ifndef AIRPORT_H
#define AIRPORT_H

#define BASE_YEAR 2010
#define MAX_YEARS 2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "utils.h"

/**
 * @struct Airport
 * @brief Represents information about an airport.
 */
typedef struct airport Airport;

/**
 * @brief Creates a new airport.
 *
 * @return A pointer to the newly created Airport.
 */
Airport* create_airport();

/**
 * @brief Builds an airport with the specified parameters.
 *
 * @param id The identifier for the airport.
 * @param flight The number of flights associated with the airport.
 * @param delay The delay associated with the airport.
 * @return A pointer to the newly created Airport.
 */
Airport* build_airport(char* id, int flight, int delay);

/**
 * @brief Retrieves the catalog ID associated with the airport.
 *
 * @param airport The Airport for which to retrieve the catalog ID.
 * @return The catalog ID of the airport.
 */
char* get_airport_catalog_id(Airport* airport);

/**
 * @brief Retrieves the number of flights associated with the airport.
 *
 * @param airport The Airport for which to retrieve the number of flights.
 * @return The number of flights at the airport.
 */
int get_airport_num_flights(Airport* airport);

/**
 * @brief Retrieves an array of flight numbers associated with the airport.
 *
 * @param airport The Airport for which to retrieve the flight numbers.
 * @return An array of flight numbers.
 */
int* get_airport_flights(Airport* airport);

/**
 * @brief Retrieves an array of delays associated with the airport.
 *
 * @param airport The Airport for which to retrieve the delays.
 * @return An array of delays.
 */
int* get_airport_delays(Airport* airport);

/**
 * @brief Retrieves the total number of passengers at the airport.
 *
 * @param airport The Airport for which to retrieve the total number of passengers.
 * @return The total number of passengers at the airport.
 */
int get_airport_num_passengers(Airport* airport);

/**
 * @brief Retrieves the number of passengers at the airport for a specific year.
 *
 * @param airport The Airport for which to retrieve the number of passengers.
 * @param year The specific year for which to retrieve passenger information.
 * @return The number of passengers at the airport for the specified year.
 */
int get_passengers_by_year(Airport* airport, int year);

/**
 * @brief Retrieves an array of the number of passengers at the airport for each year.
 *
 * @param airport The Airport for which to retrieve the number of passengers per year.
 * @return An array containing the number of passengers for each year.
 */
int* get_airport_num_passengers_per_year(Airport* airport);

/**
 * @brief Sets the catalog ID for the airport.
 *
 * @param airport The Airport for which to set the catalog ID.
 * @param id The new catalog ID to be set.
 */
void set_airport_catalog_id(Airport* airport, char* id);

/**
 * @brief Sets the number of flights for the airport.
 *
 * @param airport The Airport for which to set the number of flights.
 * @param count The new number of flights to be set.
 */
void set_airport_num_flights(Airport* airport, int count);

/**
 * @brief Sets the array of flight numbers for the airport.
 *
 * @param airport The Airport for which to set the flight numbers.
 * @param flights The new array of flight numbers to be set.
 */
void set_airport_flights(Airport* airport, int* flights);

/**
 * @brief Sets the array of delays for the airport.
 *
 * @param airport The Airport for which to set the delays.
 * @param delays The new array of delays to be set.
 */
void set_airport_delays(Airport* airport, int* delays);

/**
 * @brief Sets the total number of passengers for the airport.
 *
 * @param airport The Airport for which to set the total number of passengers.
 * @param num_passengers The new total number of passengers to be set.
 */
void set_airport_num_passengers(Airport* airport, int num_passengers);

/**
 * @brief Sets the array of the number of passengers at the airport for each year.
 *
 * @param airport The Airport for which to set the number of passengers per year.
 * @param new_passengers The new array of the number of passengers for each year to be set.
 */
void set_airport_num_passengers_per_year(Airport* airport, int* new_passengers);
#endif