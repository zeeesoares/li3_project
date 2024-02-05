#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CURRENT_YEAR 2023;
#define CURRENT_MONTH 10;
#define CURRENT_DAY 1;

/*
 * Structure to represent a date and time with day, month, year, hour, and minute.
 */
typedef struct date Date;

/*
 * Structure to represent a date with day, month, and year.
 */
typedef struct date_res Date_res;


/**
 * @brief Gets the year from a date-related token.
 *
 * @param token The date-related token from which to extract the year.
 * @return The year extracted from the token.
 */
int get_year(char* token);

/**
 * @brief Gets the month from a date-related token.
 *
 * @param token The date-related token from which to extract the month.
 * @return The month extracted from the token.
 */
int get_month(char* token);

/**
 * @brief Gets the day from a date-related token.
 *
 * @param token The date-related token from which to extract the day.
 * @return The day extracted from the token.
 */
int get_day(char* token);

/**
 * @brief Gets the year from a Date structure.
 *
 * @param date A pointer to the Date structure from which to extract the year.
 * @return The year extracted from the Date structure.
 */
int get_year_from_date(Date* date);

/**
 * @brief Gets the month from a Date structure.
 *
 * @param date A pointer to the Date structure from which to extract the month.
 * @return The month extracted from the Date structure.
 */
int get_month_from_date(Date* date);

/**
 * @brief Gets the day from a Date structure.
 *
 * @param date A pointer to the Date structure from which to extract the day.
 * @return The day extracted from the Date structure.
 */
int get_day_from_date(Date* date);

/**
 * @brief Gets the year from a Date_res structure.
 *
 * @param date A pointer to the Date_res structure from which to extract the year.
 * @return The year extracted from the Date_res structure.
 */
int get_year_from_date_res(Date_res* date);

/**
 * @brief Gets the month from a Date_res structure.
 *
 * @param date A pointer to the Date_res structure from which to extract the month.
 * @return The month extracted from the Date_res structure.
 */
int get_month_from_date_res(Date_res* date);

/**
 * @brief Gets the day from a Date_res structure.
 *
 * @param date A pointer to the Date_res structure from which to extract the day.
 * @return The day extracted from the Date_res structure.
 */
int get_day_from_date_res(Date_res* date);

/*
 * Validates the format of the date string.
 *
 * @param date_str A pointer to the date string.
 * @returns true if the date format is valid, false otherwise.
 */
bool is_valid_date_format(char* date_str);

/*
 * Validates the format of the date string for reservations.
 *
 * @param date_str A pointer to the date string.
 * @returns 1 if the date format is valid, 0 otherwise.
 */
int is_valid_date_res_format(char* date_str);

/*
 * Validates that the fields of a Date contain valid numeric values.
 *
 * @param date A pointer to the Date.
 * @returns true if the fields are valid, false otherwise.
 */
bool validate_num(Date* date);

/*
 * Validates that the fields of a Date_res contain valid numeric values.
 *
 * @param date A pointer to the Date_res.
 * @returns 1 if the fields are valid, 0 otherwise.
 */
bool validate_num_res(Date_res* date);

/*
 * Compares two Date to check if they represent the same date.
 *
 * @param dateDep A pointer to the first Date.
 * @param dateArr A pointer to the second Date.
 * @returns true if the dates are the same, false otherwise.
 */
bool compare_dates(Date* dateDep, Date* dateArr);

/*
 * Compares two Date for queries, considering only the date part.
 *
 * @param date1 A pointer to the first Date.
 * @param date2 A pointer to the second Date.
 * @returns 0 if the dates are equal, 1 if date1 > date2, -1 if date1 < date2.
 */
int compare_dates_query(Date* date1, Date* date2);

/*
 * Converts a Date_res to a Date.
 *
 * @param date_res A pointer to the Date_res.
 * @returns A pointer to the corresponding Date.
 */
Date* convert_date_res_to_date(const Date_res* date_res);

/*
 * Compares two Date_res for queries, considering only the date part.
 *
 * @param date1 A pointer to the first Date_res.
 * @param date2 A pointer to the second Date_res.
 * @returns 0 if the dates are equal, 1 if date1 > date2, -1 if date1 < date2.
 */
int compare_dates_query_res(Date_res* date1, Date_res* date2);

/*
 * Compares two Date_res to check if the first is before the second.
 *
 * @param begin_date A pointer to the first Date_res.
 * @param end_date A pointer to the second Date_res.
 * @returns 1 if begin_date is before end_date, 0 otherwise.
 */
int compare_dates_res(Date_res* begin_date, Date_res* end_date);

/*
 * Parses a date string into a Date.
 *
 * @param date_str A pointer to the date string.
 * @returns A pointer to the parsed Date.
 */
Date* parse_date(char* date_str);

/**
 * @brief Parses date strings and creates a Date structure for Query 5.
 *
 * @param date_begin The starting date string.
 * @param date_end The ending date string.
 * @return A pointer to the newly created Date structure representing the date range.
 */
Date* parse_date_query5(char* date_begin, char* date_end);

/**
 * @brief Compares two Date structures for Query 5.
 *
 * @param date1 The first Date structure.
 * @param date2 The second Date structure.
 * @return An integer less than, equal to, or greater than zero if date1 is found to be less than, equal to, or greater than date2.
 */
int compare_dates_query5(Date* date1, Date* date2);

/**
 * @brief Compares two dates for Query 7, considering only the day and month.
 *
 * @param dateDep The departure date.
 * @param dateArr The arrival date.
 * @return True if the day and month of dateDep are equal to or come before those of dateArr; false otherwise.
 */
bool compare_datesQ7(Date* dateDep, Date* dateArr);

/**
 * @brief Checks if a given date is between two other dates (inclusive).
 *
 * @param date The date to check.
 * @param date_begin The starting date of the range.
 * @param date_end The ending date of the range.
 * @return True if the given date is between the specified range; false otherwise.
 */
int is_date_between(Date* date, Date* date_begin, Date* date_end);

/*
 * Parses a date string into a Date_res.
 *
 * @param date_str A pointer to the date string.
 * @returns A pointer to the parsed Date_res.
 */
Date_res* parse_date_res(char* date_str);

/*
 * Frees the memory allocated for a Date.
 *
 * @param date A pointer to the Date.
 */
void freeDate(Date* date);

/*
 * Prints the details of a Date.
 *
 * @param date A pointer to the Date.
 */
void printDate(Date* date);

/*
 * Converts a Date to a formatted date string.
 *
 * @param date A pointer to the Date.
 * @returns A pointer to the formatted date string.
 */
char* makeDate(Date* date);

/*
 * Converts a Date to a formatted date string without time information.
 *
 * @param date A pointer to the Date.
 * @returns A pointer to the formatted date string without time information.
 */
char* makeDateOnlyDate(Date* date);

/*
 * Prints the details of a Date_res.
 *
 * @param date A pointer to the Date_res.
 */
void printDateRes(Date_res* date);

/*
 * Converts a Date_res to a formatted date string.
 *
 * @param date A pointer to the Date_res.
 * @returns A pointer to the formatted date string.
 */
char* makeDateRes(Date_res* date);

/*
 * Calculates the delay between scheduled and real dates.
 *
 * @param schedule A pointer to the scheduled Date.
 * @param real A pointer to the real Date.
 * @returns The delay in minutes.
 */
int calculate_delay(Date* schedule, Date* real);

/*
 * Calculates the number of days between two Date_res.
 *
 * @param begin A pointer to the begin Date_res.
 * @param end A pointer to the end Date_res.
 * @returns The number of days between the two dates.
 */
int calculate_day(Date_res* begin, Date_res* end);


/**
 * @brief Calculates the total number of days between two Date_res structures.
 *
 * @param begin The starting date.
 * @param end The ending date.
 * @return The total number of days between the two dates (inclusive).
 */
int calculate_all_days(Date_res* begin, Date_res* end);

/**
 * @brief Determines the number of days in a given month of a specified year.
 *
 * @param month The month (1-12) for which to determine the number of days.
 * @param year The year in which the month falls.
 * @return The number of days in the specified month.
 */
int days_in_month(int month, int year);

/**
 * @brief Checks if a given year is a leap year.
 *
 * @param year The year to check for leapness.
 * @return 1 if the year is a leap year, 0 otherwise.
 */
int is_leap_year(int year);

/*
 * Calculates the age based on a Date_res.
 *
 * @param date A pointer to the Date_res representing birthdate.
 * @returns The calculated age.
 */
int calculate_age(Date_res* date);


#endif
