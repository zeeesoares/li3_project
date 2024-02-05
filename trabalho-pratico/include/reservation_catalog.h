#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H

#include "reservation.h"
#include "user_catalog.h"
#include "stats.h"
#include "hotel_catalog.h"
#include <glib.h>


typedef struct ReservationCatalog ReservationCatalog;

/*
 * Creates a new ReservationCatalog.
 *
 * @returns A pointer to the newly created ReservationCatalog.
 */
ReservationCatalog* create_reservation_catalog();

/*
 * Builds and adds a Reservation to the ReservationCatalog.
 *
 * @param token An array of CSV tokens representing reservation information.
 * @param catalog A pointer to the ReservationCatalog.
 * @param user_catalog A pointer to the UserCatalog.
 */
void build_and_add_reservation(char** token, ReservationCatalog* catalog, UserCatalog* user_catalog, HotelCatalog* hotel_catalog, MetricsTable* m_table, FILE* file);

/*
 * Checks if a user ID is present in the UserCatalog for reservations.
 *
 * @param user_catalog A pointer to the UserCatalog.
 * @param user_id The ID of the user to check.
 * @returns 1 if the user ID is present, 0 otherwise.
 */
int is_user_id_in_catalog_reservation(UserCatalog* user_catalog, const char* user_id);

/*
 * Destroys a ReservationCatalog and frees the associated memory.
 *
 * @param catalog A pointer to the ReservationCatalog to be destroyed.
 */
void destroy_reservation_catalog(ReservationCatalog* catalog);

/*
 * Cleans up memory allocated for a ReservationCatalog.
 *
 * @param catalog A pointer to the ReservationCatalog.
 */
void cleanup_reservation_catalog(ReservationCatalog* catalog);

/*
 * Adds a Reservation to the ReservationCatalog.
 *
 * @param catalog A pointer to the ReservationCatalog.
 * @param reservation A pointer to the Reservation to be added.
 */
void add_reservation(ReservationCatalog* catalog, Reservation* reservation);

/*
 * Retrieves a Reservation from the ReservationCatalog based on the reservation ID.
 *
 * @param catalog A pointer to the ReservationCatalog.
 * @param id The ID of the reservation to retrieve.
 * @returns A pointer to the retrieved Reservation, or NULL if not found.
 */
Reservation* get_reservation_id(ReservationCatalog* catalog, int id);

/*
 * Removes a Reservation from the ReservationCatalog based on the user ID.
 *
 * @param catalog A pointer to the ReservationCatalog.
 * @param user_id The ID of the user associated with the reservation to be removed.
 */
void remove_reservation(ReservationCatalog* catalog, const char* user_id);


/*
 * Validates the date range for a reservation.
 *
 * @param begin_date A pointer to the beginning date of the reservation.
 * @param end_date A pointer to the end date of the reservation.
 * @returns 1 if the date range is valid, 0 otherwise.
 */
int validate_dates(Date_res* begin_date, Date_res* end_date);

/*
 * Validates the format of the breakfast information.
 *
 * @param breakfast A pointer to the breakfast information.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int validate_breakfast(char* breakfast);

/*
 * Validates the format of the price per night information.
 *
 * @param price A pointer to the price per night information.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int validate_price_per_night(char* price);

/*
 * Validates the format of the tax information.
 *
 * @param tax A pointer to the tax information.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int validate_tax(char* tax);

/*
 * Validates the format of the rating stars information.
 *
 * @param rating A pointer to the rating stars information.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int validate_rating_stars(char* rating);

/*
 * Validates a line of CSV data representing a reservation.
 *
 * @param token A line of CSV data.
 * @returns 1 if the line is valid, 0 otherwise.
 */
int validate_reservations(char** token);

/*
 * Calculates the total amount spent for a reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns The total amount spent.
 */
double total_spent(Reservation* reservation);


#endif