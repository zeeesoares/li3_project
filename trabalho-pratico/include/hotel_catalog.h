#ifndef HOTEL_CATALOG_H
#define HOTEL_CATALOG_H

#include "hotel.h"

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

/**
 * @struct HotelCatalog
 * @brief Represents a catalog to store and manage hotels.
 */
typedef struct HotelCatalog HotelCatalog;

/**
 * @brief Creates a new hotel catalog.
 *
 * @return A pointer to the newly created HotelCatalog.
 */
HotelCatalog* create_hotel_catalog();

/**
 * @brief Adds a hotel to the catalog.
 *
 * @param catalog The hotel catalog to which the hotel will be added.
 * @param hotel The hotel to add to the catalog.
 */
void add_hotel(HotelCatalog* catalog, Hotel* hotel);

/**
 * @brief Destroys the hotel catalog and releases associated resources.
 *
 * @param catalog The hotel catalog to be destroyed.
 */
void destroy_hotel_catalog(HotelCatalog* catalog);

/**
 * @brief Gets the hotel associated with the provided hotel ID.
 *
 * @param catalog The hotel catalog.
 * @param hotel_id The ID of the hotel to retrieve.
 * @return The Hotel object associated with the given ID, or NULL if not found.
 */
Hotel* get_hotel(HotelCatalog* catalog, int hotel_id);


#endif