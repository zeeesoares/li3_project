#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


/**
 * @struct Metrics
 * @brief Represents metrics information for a specific time period.
 */
typedef struct metrics Metrics;

/**
 * @struct YearNode
 * @brief Represents a node for a specific year in the MetricsTable.
 * @details This structure is likely used to organize metrics information by year.
 */
typedef struct yearNode YearNode;

/**
 * @struct MonthNode
 * @brief Represents a node for a specific month in the MetricsTable.
 * @details This structure is likely used to organize metrics information by month.
 */
typedef struct monthNode MonthNode;

/**
 * @struct DayNode
 * @brief Represents a node for a specific day in the MetricsTable.
 * @details This structure is likely used to organize metrics information by day.
 */
typedef struct dayNode DayNode;

/**
 * @struct MetricsTable
 * @brief Represents a table to store metrics information organized by year, month, and day.
 * @details This structure may include pointers to YearNode structures for different years.
 */
typedef struct MetricsTable MetricsTable;

/**
 * @brief Creates a new MetricsTable.
 *
 * @return A pointer to the newly created MetricsTable.
 */
MetricsTable* create_metrics_table();

/**
 * @brief Creates a new YearNode for a specific year.
 *
 * @param year The year for which to create the YearNode.
 * @return A pointer to the newly created YearNode.
 */
YearNode* create_year_node(int year);

/**
 * @brief Creates a new MonthNode for a specific month.
 *
 * @param month The month for which to create the MonthNode.
 * @return A pointer to the newly created MonthNode.
 */
MonthNode* create_month_node(int month);

/**
 * @brief Creates a new DayNode for a specific day.
 *
 * @param day The day for which to create the DayNode.
 * @return A pointer to the newly created DayNode.
 */
DayNode* create_day_node(int day);

/**
 * @brief Updates the metrics information for a specific time period.
 *
 * @param metrics A pointer to the Metrics structure to be updated.
 * @param new_users The number of new users during the period.
 * @param flights The number of flights during the period.
 * @param passengers The total number of passengers during the period.
 * @param unique_passengers The number of unique passengers during the period.
 * @param reservations The number of reservations during the period.
 */
void update_metrics(Metrics* metrics, int new_users, int flights, int passengers, int unique_passengers, int reservations);

/**
 * @brief Updates the metrics information in the MetricsTable for a specific date.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year of the update.
 * @param month The month of the update.
 * @param day The day of the update.
 * @param new_users The number of new users during the period.
 * @param flights The number of flights during the period.
 * @param passengers The total number of passengers during the period.
 * @param unique_passengers The number of unique passengers during the period.
 * @param reservations The number of reservations during the period.
 */
void update_metrics_table(MetricsTable* table, int year, int month, int day, int new_users, int flights, int passengers, int unique_passengers, int reservations);

/**
 * @brief Updates the Metrics structure for a specific year.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year to update.
 * @param month The month of the update.
 * @param day The day of the update.
 * @param new_users The number of new users during the period.
 * @param flights The number of flights during the period.
 * @param passengers The total number of passengers during the period.
 * @param unique_passengers The number of unique passengers during the period.
 * @param reservations The number of reservations during the period.
 */
void update_metrics_year(MetricsTable* table, int year, int month, int day, int new_users, int flights, int passengers, int unique_passengers, int reservations);

/**
 * @brief Updates the Metrics structure for a specific month.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year of the update.
 * @param month The month to update.
 * @param day The day of the update.
 * @param new_users The number of new users during the period.
 * @param flights The number of flights during the period.
 * @param passengers The total number of passengers during the period.
 * @param unique_passengers The number of unique passengers during the period.
 * @param reservations The number of reservations during the period.
 */
void update_metrics_month(MetricsTable* table, int year, int month, int day, int new_users, int flights, int passengers, int unique_passengers, int reservations);

/**
 * @brief Updates the Metrics structure for a specific day.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year of the update.
 * @param month The month of the update.
 * @param day The day to update.
 * @param new_users The number of new users during the period.
 * @param flights The number of flights during the period.
 * @param passengers The total number of passengers during the period.
 * @param unique_passengers The number of unique passengers during the period.
 * @param reservations The number of reservations during the period.
 */
void update_metrics_day(MetricsTable* table, int year, int month, int day, int new_users, int flights, int passengers, int unique_passengers, int reservations);
/**
 * @brief Gets the YearNode for a specific year from the MetricsTable.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year for which to get the YearNode.
 * @return A pointer to the YearNode for the specified year.
 */
YearNode* get_year_node(MetricsTable* table, int year);


/**
 * @brief Gets an array of valid years in the MetricsTable.
 *
 * @param table A pointer to the MetricsTable.
 * @return An array of valid years in the MetricsTable.
 */
int* get_valid_years_ids(MetricsTable* table);

/**
 * @brief Gets the count of valid years in the MetricsTable.
 *
 * @param table A pointer to the MetricsTable.
 * @return The count of valid years in the MetricsTable.
 */
int get_valid_years_ids_count(MetricsTable* table);

/**
 * @brief Gets an array of valid months in a YearNode.
 *
 * @param yearNode A pointer to the YearNode.
 * @return An array of valid months in the YearNode.
 */
int* get_valid_months_ids(YearNode* yearNode);

/**
 * @brief Gets the count of valid months in a YearNode.
 *
 * @param yearNode A pointer to the YearNode.
 * @return The count of valid months in the YearNode.
 */
int get_valid_months_ids_count(YearNode* yearNode);

/**
 * @brief Gets an array of valid days in a MonthNode.
 *
 * @param monthNode A pointer to the MonthNode.
 * @return An array of valid days in the MonthNode.
 */
int* get_valid_days_ids(MonthNode* monthNode);

/**
 * @brief Gets the count of valid days in a MonthNode.
 *
 * @param monthNode A pointer to the MonthNode.
 * @return The count of valid days in the MonthNode.
 */
int get_valid_days_ids_count(MonthNode* monthNode);

/**
 * @brief Gets the YearNode for a specific year from the MetricsTable.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year for which to get the YearNode.
 * @return A pointer to the YearNode for the specified year.
 */
YearNode* get_year_node(MetricsTable* table, int year);

/**
 * @brief Gets the MonthNode for a specific month within a YearNode.
 *
 * @param yearNode A pointer to the YearNode.
 * @param month The month for which to get the MonthNode.
 * @return A pointer to the MonthNode for the specified month within the YearNode.
 */
MonthNode* get_month_node(YearNode* yearNode, int month);

/**
 * @brief Gets the DayNode for a specific day within a MonthNode.
 *
 * @param monthNode A pointer to the MonthNode.
 * @param day The day for which to get the DayNode.
 * @return A pointer to the DayNode for the specified day within the MonthNode.
 */
DayNode* get_day_node(MonthNode* monthNode, int day);

/**
 * @brief Gets the Metrics structure for a specific year from the MetricsTable.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year for which to get the Metrics structure.
 * @return A pointer to the Metrics structure for the specified year.
 */
Metrics* get_year_metrics(MetricsTable* table, int year);

/**
 * @brief Gets the Metrics structure for a specific month within a YearNode.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year of the Metrics structure.
 * @param month The month for which to get the Metrics structure.
 * @return A pointer to the Metrics structure for the specified month within the YearNode.
 */
Metrics* get_month_metrics(MetricsTable* table, int year, int month);

/**
 * @brief Gets the Metrics structure for a specific day within a MonthNode.
 *
 * @param table A pointer to the MetricsTable.
 * @param year The year of the Metrics structure.
 * @param month The month of the Metrics structure.
 * @param day The day for which to get the Metrics structure.
 * @return A pointer to the Metrics structure for the specified day within the MonthNode.
 */
Metrics* get_day_metrics(MetricsTable* table, int year, int month, int day);

/**
 * @brief Gets the number of new users from the Metrics structure.
 *
 * @param metrics A pointer to the Metrics structure.
 * @return The number of new users recorded in the Metrics structure.
 */
int get_num_new_users(Metrics* metrics);

/**
 * @brief Gets the number of flights from the Metrics structure.
 *
 * @param metrics A pointer to the Metrics structure.
 * @return The number of flights recorded in the Metrics structure.
 */
int get_num_flights(Metrics* metrics);

/**
 * @brief Gets the total number of passengers from the Metrics structure.
 *
 * @param metrics A pointer to the Metrics structure.
 * @return The total number of passengers recorded in the Metrics structure.
 */
int get_num_passengers(Metrics* metrics);

/**
 * @brief Gets the number of unique passengers from the Metrics structure.
 *
 * @param metrics A pointer to the Metrics structure.
 * @return The number of unique passengers recorded in the Metrics structure.
 */
int get_num_unique_passengers(Metrics* metrics);

/**
 * @brief Gets the number of reservations from the Metrics structure.
 *
 * @param metrics A pointer to the Metrics structure.
 * @return The number of reservations recorded in the Metrics structure.
 */
int get_num_reservations(Metrics* metrics);


/**
 * @brief Prints the metrics information in the MetricsTable.
 *
 * @param table A pointer to the MetricsTable.
 */
void print_metrics_table(MetricsTable* table);

/**
 * @brief Destroys the MetricsTable and frees associated memory.
 *
 * @param table A pointer to the MetricsTable to be destroyed.
 */
void destroy_metrics_table(MetricsTable* table);
#endif
