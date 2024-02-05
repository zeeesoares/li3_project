#ifndef USERS_H
#define USERS_H

#include "date.h"

typedef struct User User;
typedef struct date Date;

/*
 * Parses a line of CSV data representing a user and returns an array of tokens.
 *
 * @param line A line of CSV data representing a user.
 * @returns An array of tokens.
 */
char** parseUser(char* line);

/*
 * Frees the memory allocated for an array of tokens.
 *
 * @param tokens An array of tokens to be freed.
 */
void freeTokens(char** tokens);

/*
 * Creates a User from an array of tokens.
 *
 * @param tokens An array of tokens representing user information.
 * @returns A pointer to the created User.
 */
User* createUserFromTokens(char** tokens);

/*
 * Frees the memory allocated for a User.
 *
 * @param user A pointer to the User to be freed.
 */
void freeUser(User* user);

/*
 * Gets the ID associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user ID.
 */
char* get_user_id(User* user);

/*
 * Gets the name associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user name.
 */
char* get_user_name(User* user);

/*
 * Gets the email associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user email.
 */
char* get_user_email(User* user);

/*
 * Gets the phone number associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user phone number.
 */
char* get_user_phone_number(User* user);

/*
 * Gets the birth date associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user birth date.
 */
Date_res* get_user_birth_date(User* user);

/*
 * Gets the sex associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user sex.
 */
char* get_user_sex(User* user);

/*
 * Gets the passport associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user passport.
 */
char* get_user_passport(User* user);

/*
 * Gets the country code associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user country code.
 */
char* get_user_country_code(User* user);

/*
 * Gets the address associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user address.
 */
char* get_user_address(User* user);

/*
 * Gets the account creation date associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user account creation date.
 */
Date* get_user_account_creation(User *user);

/*
 * Gets the payment method associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user payment method.
 */
char* get_user_pay_method(User* user);

/*
 * Gets the account status associated with a User.
 *
 * @param user A pointer to the User.
 * @returns A pointer to the user account status.
 */
int get_user_account_status(User* user);


/*
 * Gets the total amount spent by a User.
 *
 * @param user A pointer to the User.
 * @returns The total amount spent.
 */
double get_user_total_spent(User* user);

/*
 * Gets the number of flights associated with a User.
 *
 * @param user A pointer to the User.
 * @returns The number of flights.
 */
int get_user_number_of_flights(User* user);

/*
 * Sets the account status associated with a User.
 *
 * @param user A pointer to the User.
 * @param value The value to set.
 */
void set_user_account_status(User* user, char* token);

/*
 * Sets the total amount spent for a User.
 *
 * @param user A pointer to the User.
 * @param value The value to set.
 */
void set_user_total_spent(User* user, double value);

/*
 * Sets the number of flights for a User.
 *
 * @param user A pointer to the User.
 * @param value The value to set.
 */
void set_user_number_of_flights(User* user, int value);

/*
 * Gets the number of reservations associated with a User.
 *
 * @param user A pointer to the User.
 * @returns The number of reservations.
 */
int get_user_number_of_reservations(User* user);

/*
 * Sets the number of reservations for a User.
 *
 * @param user A pointer to the User.
 * @param value The value to set.
 */
void set_user_number_of_reservations(User* user, int value);

/*
 * Gets the birth date as a Date structure associated with a User.
 *
 * @param user A pointer to the User.
 * @returns The birth date as a Date structure.
 */
Date get_user_birth_date_struct(User* user);

/*
 * Gets the list of flights associated with a User.
 *
 * @param user A pointer to the User.
 * @returns The list of flights.
 */
int* get_user_flights(User* user);

/**
 * @brief Gets the array of reservation IDs associated with a user.
 *
 * @param user A pointer to the User structure.
 * @return A pointer to an array of reservation IDs. Note: The array is dynamically allocated and should be freed after use.
 */
int* get_user_reservations(User* user);

/**
 * @brief Adds a flight ID to the list of flights associated with a user.
 *
 * @param user A pointer to the User structure.
 * @param flight_id The ID of the flight to be added.
 */
void add_flight_to_user(User* user, int flight_id);

/**
 * @brief Adds a reservation ID to the list of reservations associated with a user.
 *
 * @param user A pointer to the User structure.
 * @param reservation_id The ID of the reservation to be added.
 */
void add_reservation_to_user(User* user, int reservation_id);

#endif
