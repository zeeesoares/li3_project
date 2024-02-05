#ifndef PASSENGERS_CATALOG_H
#define PASSENGERS_CATALOG_H


#include "flights_catalog.h"
#include "user_catalog.h"
#include "stats.h"
#include "airport_catalog.h"
#include <glib.h>

/*
 * Builds and adds a Passenger to the PassengerCatalog.
 *
 * @param tokens An array of CSV tokens representing passenger information.
 * @param catalog A pointer to the PassengerCatalog.
 * @param f_catalog A pointer to the FlightCatalog.
 * @param u_catalog A pointer to the UserCatalog.
 */
void build_and_add_passenger(char** tokens, FlightCatalog* f_catalog, UserCatalog* u_catalog,  AirportCatalog* a_catalog, MetricsTable* m_table, FILE* file);

/*
 * Checks if a flight ID is present in the FlightCatalog.
 *
 * @param flight_catalog A pointer to the FlightCatalog.
 * @param flight_id The ID of the flight to check.
 * @returns 1 if the flight ID is present, 0 otherwise.
 */
int is_flight_id_in_catalog(FlightCatalog* flight_catalog, int flight_id);

/*
 * Checks if a user ID is present in the UserCatalog.
 *
 * @param user_catalog A pointer to the UserCatalog.
 * @param user_id The ID of the user to check.
 * @returns 1 if the user ID is present, 0 otherwise.
 */
int is_user_id_in_f_catalog(UserCatalog* user_catalog, const char* user_id);

/*
 * Validates a line of CSV data representing a passenger.
 *
 * @param tokens A line of CSV data.
 * @returns 1 if the line is valid, 0 otherwise.
 */
int validate_passenger(char** tokens);

#endif