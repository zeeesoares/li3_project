#ifndef AIRPORT_CATALOG_H
#define AIRPORT_CATALOG_H

#include "airport.h"


/**
 * @struct AirportCatalog
 * @brief Represents a catalog to store and manage airports.
 */
typedef struct AirportCatalog AirportCatalog;

/**
 * @brief Creates a new airport catalog.
 *
 * @return A pointer to the newly created AirportCatalog.
 */
AirportCatalog* create_airport_catalog();

/**
 * @brief Adds an airport to the catalog.
 *
 * @param catalog The airport catalog to which the airport will be added.
 * @param airport The airport to add to the catalog.
 */
void add_airport(AirportCatalog* catalog, Airport* airport);

/**
 * @brief Adds a passenger to the airport catalog for a specific year.
 *
 * @param id The passenger ID to be added.
 * @param catalog The airport catalog to which the passenger will be added.
 * @param year The year in which the passenger is added.
 */
void add_passenger_to_airport(char* id, AirportCatalog* catalog, int year);

/**
 * @brief Destroys the airport catalog and releases associated resources.
 *
 * @param catalog The airport catalog to be destroyed.
 */
void destroy_airport_catalog(AirportCatalog* catalog);

/**
 * @brief Gets the count of valid airport IDs in the catalog.
 *
 * @param airportCatalog The airport catalog.
 * @return The count of valid airport IDs.
 */
int get_valid_airport_ids_count(AirportCatalog* airportCatalog);

/**
 * @brief Gets an element oh the array of valid airport IDs from the catalog.
 *
 * @param airportCatalog The airport catalog.
 * @return An valid airport ID.
 */
char* get_valid_airport_ids(AirportCatalog* airportCatalog, int index) ;

/**
 * @brief Gets the airport associated with the provided airport ID.
 *
 * @param catalog The airport catalog.
 * @param airport_id The ID of the airport to retrieve.
 * @return The Airport object associated with the given ID, or NULL if not found.
 */
Airport* get_airport(AirportCatalog* catalog, char* airport_id);

#endif