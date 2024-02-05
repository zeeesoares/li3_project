#ifndef FLIGHTS_CATALOG_H
#define FLIGHTS_CATALOG_H

#include <glib.h>
#include "flight.h"
#include "stats.h"
#include "airport_catalog.h"




/**
 * @struct FlightCatalog
 * @brief Represents a catalog for managing flights.
 */
typedef struct FlightCatalog FlightCatalog;

/*
 * Creates a new FlightCatalog instance.
 *
 * @returns A pointer to the newly created FlightCatalog instance.
 */
FlightCatalog* create_flight_catalog();

/*
 * Builds a Flight instance from CSV tokens and adds it to the FlightCatalog.
 *
 * @param tokens An array of CSV tokens representing flight information.
 * @param catalog A pointer to the FlightCatalog instance.
 */
void build_and_add_flight(char** tokens, FlightCatalog* catalog, AirportCatalog* a_catalog, MetricsTable* m_table);

/*
 * Destroys a FlightCatalog instance and frees the associated memory.
 *
 * @param catalog A pointer to the FlightCatalog instance to be destroyed.
 */
void destroy_flight_catalog(FlightCatalog* catalog);

/*
 * Adds a Flight instance to the FlightCatalog.
 *
 * @param catalog A pointer to the FlightCatalog instance.
 * @param flight A pointer to the Flight instance to be added.
 */
void add_flight(FlightCatalog* catalog, Flight* flight);

/*
 * Gets a Flight instance from the FlightCatalog based on the flight ID.
 *
 * @param catalog A pointer to the FlightCatalog instance.
 * @param flight_id The ID of the flight to retrieve.
 * @returns A pointer to the retrieved Flight instance, or NULL if not found.
 */
Flight* get_flight(FlightCatalog* catalog, int flight_id);

/*
 * Removes a Flight instance from the FlightCatalog based on the flight ID.
 *
 * @param catalog A pointer to the FlightCatalog instance.
 * @param flight_id The ID of the flight to be removed.
 */
void remove_flight(FlightCatalog* catalog, int flight_id);

/*
 * Prints the details of a FlightCatalog or a specific Flight within the catalog.
 *
 * @param id If not NULL, prints the details of the Flight with the specified ID.
 *            If NULL, prints the details of the entire FlightCatalog.
 * @param catalog A pointer to the FlightCatalog instance.
 */
void print_flight_catalog(int id, FlightCatalog* catalog);

/*
 * Validates a line of CSV data representing a flight.
 *
 * @param line A line of CSV data.
 * @returns 1 if the line is valid, 0 otherwise.
 */
int validate_flight(char** line);

/*
 * Validates a line of CSV data representing origin and destination airports.
 *
 * @param line A line of CSV data.
 * @returns 1 if the line is valid, 0 otherwise.
 */
int validate_org_des(char* line);

/*
 * Gets an array of valid flight IDs from the FlightCatalog.
 *
 * @param catalog A pointer to the FlightCatalog instance.
 * @returns An array of valid flight IDs.
 */
int* get_valid_flight_ids(FlightCatalog* catalog);

/*
 * Gets the count of valid flight IDs from the FlightCatalog.
 *
 * @param catalog A pointer to the FlightCatalog instance.
 * @returns The count of valid flight IDs.
 */
int get_valid_flight_ids_count(FlightCatalog* catalog);


#endif