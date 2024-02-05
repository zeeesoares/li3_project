#ifndef USER_CATALOG_H
#define USER_CATALOG_H

#include <glib.h>
#include "user.h"
#include "stats.h"


typedef struct UserCatalog UserCatalog;

/*
 * Creates a new UserCatalog instance.
 *
 * @returns A pointer to the newly created UserCatalog instance.
 */
UserCatalog* create_user_catalog();

/*
 * Builds and adds a User instance to the UserCatalog.
 *
 * @param tokens An array of CSV tokens representing user information.
 * @param catalog A pointer to the UserCatalog instance.
 */
void build_and_add_user(char** tokens, UserCatalog* catalog, MetricsTable* m_table);

/*
 * Destroys a UserCatalog instance and frees the associated memory.
 *
 * @param catalog A pointer to the UserCatalog instance to be destroyed.
 */
void destroy_user_catalog(UserCatalog* catalog);

/*
 * Adds a User instance to the UserCatalog.
 *
 * @param catalog A pointer to the UserCatalog instance.
 * @param user A pointer to the User instance to be added.
 */
void add_user(UserCatalog* catalog, User* user);

/*
 * Retrieves a User instance from the UserCatalog based on the user ID.
 *
 * @param catalog A pointer to the UserCatalog instance.
 * @param user_id The ID of the user to retrieve.
 * @returns A pointer to the retrieved User instance, or NULL if not found.
 */
User* get_user(UserCatalog* catalog, const char* user_id);

/*
 * Retrieves a User code from the UserCatalog based on the user ID.
 *
 * @param catalog A pointer to the UserCatalog instance.
 * @param user_id The ID of the user to retrieve.
 * @returns A pointer to the retrieved User code.
 */
int get_user_code(UserCatalog* catalog, const char* user_id);

/**
 * @brief Gets a user from the user catalog based on the user code.
 *
 * @param catalog A pointer to the UserCatalog.
 * @param user_code The code identifying the user.
 * @return A pointer to the User structure.
 */
User* get_user_from_code(UserCatalog* catalog, int user_code);

/**
 * @brief Gets a list of users whose names start with a specific letter.
 *
 * @param catalog A pointer to the UserCatalog.
 * @param letter The ASCII value of the letter used for filtering users.
 * @return A GList containing pointers to User structures that match the criteria.
 */
GList* get_user_list_for_letter(UserCatalog* catalog, int letter);

/*
 * Retrieves an array of valid user IDs from the UserCatalog.
 *
 * @param catalog A pointer to the UserCatalog instance.
 * @returns An array of valid user IDs.
 */
char** get_valid_user_ids(UserCatalog* catalog);

/*
 * Retrieves the count of valid user IDs from the UserCatalog.
 *
 * @param catalog A pointer to the UserCatalog instance.
 * @returns The count of valid user IDs.
 */
int get_valid_user_ids_count(UserCatalog* catalog);

/*
 * Removes a User instance from the UserCatalog based on the user ID.
 *
 * @param catalog A pointer to the UserCatalog instance.
 * @param user_id The ID of the user to be removed.
 */
void remove_user(UserCatalog* catalog, const char* user_id);

/*
 * Validates the format of a date.
 *
 * @param token An array of tokens representing a date.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int isValidDate(char** token);

/*
 * Validates the format of a date and time.
 *
 * @param token An array of tokens representing a date and time.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int isValidDateTime(char** token);

/*
 * Validates the format of an email address.
 *
 * @param token An array of tokens representing an email address.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int isValidEmail(char** token);

/*
 * Validates the format of a country code.
 *
 * @param token An array of tokens representing a country code.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int isValidCountryCode(char** token);

/*
 * Validates the format of an account status.
 *
 * @param token An array of tokens representing an account status.
 * @returns 1 if the format is valid, 0 otherwise.
 */
int isValidAccountStatus(char** token);

/*
 * Validates a line of CSV data representing a user.
 *
 * @param token A line of CSV data.
 * @returns 1 if the line is valid, 0 otherwise.
 */
int validate_user(char** token);




#endif