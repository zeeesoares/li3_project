#ifndef RESERVATIONS_H
#define RESERVATIONS_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define reservation_camps 14


typedef struct reservation Reservation;
typedef struct date_res Date_res;

Reservation* create_reservation();

Reservation* build_reservation(char** token);

/*
 * Creates a new Reservation.
 *
 * @returns A pointer to the newly created Reservation.
 */
Reservation* create_reservation();

/*
 * Builds a Reservation from CSV tokens.
 *
 * @param token An array of CSV tokens representing reservation information.
 * @returns A pointer to the built Reservation.
 */
Reservation* build_reservation(char** token);

/*
 * Sets the ID for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the ID.
 */
void set_id(Reservation* reservation, char* token);

/*
 * Sets the user ID for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the user ID.
 */
void set_user_id(Reservation* reservation, char* token);

/*
 * Sets the hotel ID for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the hotel ID.
 */
void set_hotel_id(Reservation* reservation, char* token);

/*
 * Sets the hotel name for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the hotel name.
 */
void set_hotel_name(Reservation* reservation, char* token);

/*
 * Sets the hotel stars for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the hotel stars.
 */
void set_hotel_stars(Reservation* reservation, char* token);

/*
 * Sets the tax for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the tax.
 */
void set_tax(Reservation* reservation, char* token);

/*
 * Sets the address for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the address.
 */
void set_adress(Reservation* reservation, char* token);

/*
 * Sets the beginning date for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the beginning date.
 */
void set_begin_date(Reservation* reservation, char* token);

/*
 * Sets the end date for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the end date.
 */
void set_end_date(Reservation* reservation, char* token);

/*
 * Sets the price per night for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the price per night.
 */
void set_price_per_night(Reservation* reservation, char* token);

/*
 * Sets the breakfast information for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the breakfast information.
 */
void set_breakfast(Reservation* reservation, char* token);

/*
 * Sets the rating for a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @param token A pointer to the token containing the rating.
 */
void set_rating(Reservation* reservation, char* token);

/*
 * Gets the ID of a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns The Reservation ID.
 */
int get_id(Reservation* reservation);

/*
 * Gets the user ID associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns A pointer to the user ID.
 */
char* get_reservation_user_id(Reservation* reservation);

/*
 * Gets the hotel name associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns A pointer to the hotel name.
 */
char* get_hotel_name(Reservation* reservation);

/*
 * Gets the hotel ID associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns The hotel ID.
 */
int get_hotel_id(Reservation* reservation);

/*
 * Gets the hotel stars associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns The hotel stars.
 */
int get_hotel_stars(Reservation* reservation);

/*
 * Gets the tax associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns The tax.
 */
int get_tax(Reservation* reservation);

/*
 * Gets the address associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns A pointer to the address.
 */
char* get_adress(Reservation* reservation);

/*
 * Gets the beginning date associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns A pointer to the beginning date.
 */
Date_res* get_begin_date(Reservation* reservation);

/*
 * Gets the end date associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns A pointer to the end date.
 */
Date_res* get_end_date(Reservation* reservation);

/*
 * Gets the price per night associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns The price per night.
 */
int get_price_per_night(Reservation* reservation);

/*
 * Gets the breakfast information associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @return The breakfast information.
 */
int get_breakfast(Reservation* reservation);


/*
 * Gets the rating associated with a Reservation.
 *
 * @param reservation A pointer to the Reservation.
 * @returns The rating.
 */
int get_rating(Reservation* reservation);

/*
 * Frees the memory allocated for a Reservation.
 *
 * @param reservation A pointer to the Reservation to be freed.
 */
void free_reservation(Reservation* reservation);


#endif