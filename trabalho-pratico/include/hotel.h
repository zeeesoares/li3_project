#ifndef HOTEL_H
#define HOTEL_H

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

/**
 * @struct Hotel
 * @brief Represents information about a hotel.
 */
typedef struct hotel Hotel;

/**
 * @brief Creates a new hotel.
 *
 * @return A pointer to the newly created Hotel.
 */
Hotel* create_hotel();

/**
 * @brief Builds a hotel with the specified ID and rating.
 *
 * @param id The unique identifier for the hotel.
 * @param rating The initial rating for the hotel.
 * @return A pointer to the newly created Hotel.
 */
Hotel* build_hotel(int id, int rating);

/**
 * @brief Adds a reservation ID to the list of reservations for a given hotel.
 *
 * @param hotel A pointer to the Hotel structure to which the reservation ID will be added.
 * @param reservation_id The ID of the reservation to be added.
 */
void add_reservation_to_hotel(Hotel* hotel, int reservation_id);

/**
 * @brief Gets the catalog ID of a hotel.
 *
 * @param hotel A pointer to the Hotel structure from which to retrieve the catalog ID.
 * @return The catalog ID of the hotel.
 */
int get_hotel_catalog_id(Hotel* hotel);

/**
 * @brief Gets the rating of a hotel.
 *
 * @param hotel A pointer to the Hotel structure from which to retrieve the rating.
 * @return The rating of the hotel.
 */
int get_hotel_ratings(Hotel* hotel);

/**
 * @brief Gets the number of reservations associated with a hotel.
 *
 * @param hotel A pointer to the Hotel structure from which to retrieve the number of reservations.
 * @return The number of reservations at the hotel.
 */
int get_hotel_num_reservations(Hotel* hotel);

/**
 * @brief Gets an array of reservation IDs associated with a hotel.
 *
 * @param hotel A pointer to the Hotel structure from which to retrieve the reservation IDs.
 * @return An array of reservation IDs.
 */
int* get_hotel_reservations(Hotel* hotel);

/**
 * @brief Gets the number of ratings received by a hotel.
 *
 * @param hotel A pointer to the Hotel structure from which to retrieve the number of ratings.
 * @return The number of ratings received by the hotel.
 */
int get_hotel_num_rates(Hotel* hotel);

/**
 * @brief Sets the catalog ID for a hotel.
 *
 * @param hotel A pointer to the Hotel structure for which to set the catalog ID.
 * @param new_id The new catalog ID to be set.
 */
void set_hotel_catalog_id(Hotel* hotel, int new_id);

/**
 * @brief Sets the rating for a hotel.
 *
 * @param hotel A pointer to the Hotel structure for which to set the rating.
 * @param new_sum_rating The new total rating to be set.
 */
void set_hotel_ratings(Hotel* hotel, int new_sum_rating);

/**
 * @brief Sets the number of ratings for a hotel.
 *
 * @param hotel A pointer to the Hotel structure for which to set the number of ratings.
 * @param new_num_rates The new number of ratings to be set.
 */
void set_hotel_num_rates(Hotel* hotel, int new_num_rates);



/**
 * @brief Frees the hotel struct.
 */
void freeHotel(Hotel* hotel);

#endif