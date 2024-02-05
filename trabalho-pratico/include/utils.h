#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Converts a string representation of an integer to an actual integer.
 *
 * @param string A pointer to the string representation of an integer.
 * @returns The integer value.
 */
int string_to_int(char* string);

/*
 * Checks if a string represents a numeric value.
 *
 * @param string A pointer to the string to be checked.
 * @returns 1 if the string is numeric, 0 otherwise.
 */
int is_num(char* string);

/**
 * @brief Converts the characters in a string to uppercase.
 *
 * @param str A pointer to the null-terminated string to be converted to uppercase.
 */
void convert_to_uppercase(char* str);

/**
 * @brief Compares a string to check if it represents an identifier in uppercase.
 *
 * @param id A pointer to the null-terminated string representing an identifier.
 * @return An integer representing the result of the comparison:
 */
int compare_ids(char *id);

#endif