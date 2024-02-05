#ifndef QUERIES__SERVICES_H
#define QUERIES__SERVICES_H

#include "queries.h"

//QUERY1

/**
 * @struct query1_results
 * @brief Represents the results of Query 1.
 */
typedef struct query1_results Q1_results;

/**
 * @brief Gets the Query 1 results for a user from a given UserCatalog.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog A pointer to the UserCatalog containing user information.
 * @return A pointer to the Query 1 results structure for users.
 */
Q1_results* get_query1_user_results(command* cmd, UserCatalog* catalog);

/**
 * @brief Gets the Query 1 results for a flight from a given FlightCatalog.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog A pointer to the FlightCatalog containing flight information.
 * @return A pointer to the Query 1 results structure for flights.
 */
Q1_results* get_query1_flight_results(command* cmd, FlightCatalog* catalog);

/**
 * @brief Gets the Query 1 results for a reservation from a given ReservationCatalog.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog A pointer to the ReservationCatalog containing reservation information.
 * @return A pointer to the Query 1 results structure for reservations.
 */
Q1_results* get_query1_reservation_results(command* cmd, ReservationCatalog* catalog);

/**
 * @brief Gets the type of Query 1 results.
 *
 * @param res A pointer to the Query 1 results structure.
 * @return The type of Query 1 results (user, flight, or reservation).
 */
int get_q1_type(Q1_results* res);

/**
 * @brief Gets the flag indicating the type of Query 1 results.
 *
 * @param res A pointer to the Query 1 results structure.
 * @return The flag indicating the type of Query 1 results (0 for users, 1 for flights, 2 for reservations).
 */
int get_q1_flag(Q1_results* res);

/**
 * @brief Gets the User structure from Query 1 results.
 *
 * @param res A pointer to the Query 1 results structure.
 * @return A pointer to the User structure if the type is user; otherwise, NULL.
 */
User* get_q1_user(Q1_results* res);

/**
 * @brief Gets the Flight structure from Query 1 results.
 *
 * @param res A pointer to the Query 1 results structure.
 * @return A pointer to the Flight structure if the type is flight; otherwise, NULL.
 */
Flight* get_q1_flight(Q1_results* res);

/**
 * @brief Gets the Reservation structure from Query 1 results.
 *
 * @param res A pointer to the Query 1 results structure.
 * @return A pointer to the Reservation structure if the type is reservation; otherwise, NULL.
 */
Reservation* get_q1_reservation(Q1_results* res);


//QUERY2

/**
 * @struct query2_results
 * @brief Represents the results of Query 2.
 */
typedef struct query2_results Q2_results;

/**
 * @struct info2
 * @brief Represents additional information associated with Query 2 results.
 */
typedef struct info2 Info2;

/**
 * @brief Gets the Query 2 results for flights and reservations for a given user.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param user A pointer to the User structure for whom flights and reservations are queried.
 * @param catalog A pointer to the CatalogManager containing flight and reservation information.
 * @return A pointer to the Query 2 results structure containing flights and reservations.
 */
Q2_results* get_query2_flighs_and_reservations(command* cmd, User* user, CatalogManager* catalog);

/**
 * @brief Gets the Query 2 results for flights for a given user.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param user A pointer to the User structure for whom flights are queried.
 * @param catalog A pointer to the CatalogManager containing flight information.
 * @return A pointer to the Query 2 results structure containing flights.
 */
Q2_results* get_query2_flighs(command* cmd, User* user, CatalogManager* catalog);

/**
 * @brief Gets the Query 2 results for reservations for a given user.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param user A pointer to the User structure for whom reservations are queried.
 * @param catalog A pointer to the CatalogManager containing reservation information.
 * @return A pointer to the Query 2 results structure containing reservations.
 */
Q2_results* get_query2_reservations(command* cmd, User* user, CatalogManager* catalog);
/*
 * Compares dates for sorting.
 *
 * @param a A pointer to the first element.
 * @param b A pointer to the second element.
 * @returns An integer representing the comparison result.
 */
int compareDates(const void* a, const void* b);


/**
 * @brief Gets the total count of Query 2 results.
 *
 * @param infos A pointer to the Query 2 results structure.
 * @return The total count of Query 2 results.
 */
int get_q2_count(Q2_results* infos);

/**
 * @brief Gets the ID at the specified index in Query 2 results.
 *
 * @param info A pointer to the Query 2 results structure.
 * @param index The index of the result to retrieve.
 * @return The ID at the specified index in Query 2 results.
 */
int get_q2_id(Q2_results* info, int index);

/**
 * @brief Gets the type at the specified index in Query 2 results.
 *
 * @param info A pointer to the Query 2 results structure.
 * @param index The index of the result to retrieve.
 * @return The type at the specified index in Query 2 results.
 */
int get_q2_type(Q2_results* info, int index);

/**
 * @brief Gets the date at the specified index in Query 2 results.
 *
 * @param info A pointer to the Query 2 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the Date structure representing the date at the specified index in Query 2 results.
 */
Date* get_q2_date(Q2_results* info, int index);

/**
 * @brief Gets the flag indicating the type of Query 2 results.
 *
 * @param info A pointer to the Query 2 results structure.
 * @return The flag indicating the type of Query 2 results (0 for flights, 1 for reservations).
 */
int get_q2_flag(Q2_results* info);

/**
 * @brief Gets the data type of Query 2 results.
 *
 * @param info A pointer to the Query 2 results structure.
 * @return The data type of Query 2 results (0 for integer IDs, 1 for dates).
 */
int get_q2_datatype(Q2_results* info);

/**
 * @brief Frees the memory allocated for Query 2 results.
 *
 * @param info A pointer to the Query 2 results structure.
 */
void freeInfos2(Q2_results* info);


//QUERY3


/**
 * @struct query3_results
 * @brief Represents the results of Query 3.
 */
typedef struct query3_results Q3_results;

/**
 * @brief Gets the Query 3 results for the rating of a specific hotel.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param hotel A pointer to the Hotel structure for which the rating is queried.
 * @return A pointer to the Query 3 results structure containing the hotel rating.
 */
Q3_results* get_query3_rating(command* cmd, Hotel* hotel);

/**
 * @brief Gets the median rating from Query 3 results.
 *
 * @param info A pointer to the Query 3 results structure.
 * @return The median rating from Query 3 results.
 */
double get_q3_median(Q3_results* info);

/**
 * @brief Gets the flag indicating the type of Query 3 results.
 *
 * @param info A pointer to the Query 3 results structure.
 * @return The flag indicating the type of Query 3 results (0 for integer ratings, 1 for median rating).
 */
int get_q3_flag(Q3_results* info);



//QUERY4


/**
 * @struct query4_results
 * @brief Represents the results of Query 4.
 */
typedef struct query4_results Q4_results;

/**
 * @struct info4
 * @brief Represents additional information associated with Query 4 results.
 */
typedef struct info4 Info4;

/**
 * @brief Gets the Query 4 results for a specific hotel and reservation catalog.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param hotel A pointer to the Hotel structure for which reservations are queried.
 * @param reservation_catalog A pointer to the ReservationCatalog containing reservation information.
 * @return A pointer to the Query 4 results structure containing reservation details.
 */
Q4_results* get_query4_result(command* cmd, Hotel* hotel, ReservationCatalog* reservation_catalog);

/**
 * @brief Frees the memory allocated for Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 */
void free_q4infos(Q4_results* info);

/**
 * @brief Gets the total count of Query 4 results.
 *
 * @param infos A pointer to the Query 4 results structure.
 * @return The total count of Query 4 results.
 */
int get_q4_count(Q4_results* infos);

/**
 * @brief Gets the user ID at the specified index in Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the user ID at the specified index in Query 4 results.
 */
char* get_q4_user_id(Q4_results* info, int index);

/**
 * @brief Gets the reservation ID at the specified index in Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 * @param index The index of the result to retrieve.
 * @return The reservation ID at the specified index in Query 4 results.
 */
int get_q4_reservation_id(Q4_results* info, int index);

/**
 * @brief Gets the total price at the specified index in Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 * @param index The index of the result to retrieve.
 * @return The total price at the specified index in Query 4 results.
 */
double get_q4_total_price(Q4_results* info, int index);

/**
 * @brief Gets the begin date at the specified index in Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the begin date at the specified index in Query 4 results.
 */
char* get_q4_begin_date(Q4_results* info, int index);

/**
 * @brief Gets the end date at the specified index in Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the end date at the specified index in Query 4 results.
 */
char* get_q4_end_date(Q4_results* info, int index);

/**
 * @brief Gets the rating at the specified index in Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 * @param index The index of the result to retrieve.
 * @return The rating at the specified index in Query 4 results.
 */
int get_q4_rating(Q4_results* info, int index);

/**
 * @brief Gets the flag indicating the type of Query 4 results.
 *
 * @param info A pointer to the Query 4 results structure.
 * @return The flag indicating the type of Query 4 results (0 for integer IDs, 1 for dates).
 */
int get_q4_flag(Q4_results* info);

/*
 * Compares Date_res instances for sorting.
 *
 * @param a A pointer to the first element.
 * @param b A pointer to the
 */
int compareDatesRes(const void* a, const void* b);


//QUERY5

/**
 * @struct query5_results
 * @brief Represents the results of Query 5.
 */
typedef struct query5_results Q5_results;

/**
 * @struct info5
 * @brief Represents additional information associated with Query 5 results.
 */
typedef struct info5 Info5;

/**
 * @brief Gets the Query 5 results for a specific airport and flight catalog.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param airport A pointer to the Airport structure for which flights are queried.
 * @param flight_catalog A pointer to the FlightCatalog containing flight information.
 * @return A pointer to the Query 5 results structure containing flight details.
 */
Q5_results* get_query5_results(command* cmd, Airport* airport, FlightCatalog* flight_catalog);

/**
 * @brief Frees the memory allocated for Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 */
void free_q5_info(Q5_results* info);

/**
 * @brief Gets the total count of Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 * @return The total count of Query 5 results.
 */
int get_q5_count(Q5_results* info);

/**
 * @brief Gets the flag indicating the type of Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 * @return The flag indicating the type of Query 5 results.
 */
int get_q5_flag(Q5_results* info);

/**
 * @brief Gets the flight ID at the specified index in Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 * @param index The index of the result to retrieve.
 * @return The flight ID at the specified index in Query 5 results.
 */
int get_q5_flight_id(Q5_results* info, int index);

/**
 * @brief Gets the departure date at the specified index in Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the departure date at the specified index in Query 5 results.
 */
char* get_q5_dep_date(Q5_results* info, int index);

/**
 * @brief Gets the airline at the specified index in Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the airline at the specified index in Query 5 results.
 */
char* get_q5_airline(Q5_results* info, int index);

/**
 * @brief Gets the destination at the specified index in Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the destination at the specified index in Query 5 results.
 */
char* get_q5_destination(Q5_results* info, int index);

/**
 * @brief Gets the plane model at the specified index in Query 5 results.
 *
 * @param info A pointer to the Query 5 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the plane model at the specified index in Query 5 results.
 */
char* get_q5_planemodel(Q5_results* info, int index);


//QUERY6


/**
 * @struct query6_results
 * @brief Represents the results of Query 6.
 */
typedef struct query6_results Q6_results;

/**
 * @struct info6
 * @brief Represents additional information associated with Query 6 results.
 */
typedef struct info6 Info6;

/**
 * @brief Gets the Query 6 results for the number of passengers at each airport.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog A pointer to the AirportCatalog containing airport information.
 * @return A pointer to the Query 6 results structure containing airport details.
 */
Q6_results* get_query6_results(command* cmd, AirportCatalog* catalog);

/**
 * @brief Compares the number of passengers between two airports for sorting purposes.
 *
 * @param a A pointer to the first info6 structure.
 * @param b A pointer to the second info6 structure.
 * @return An integer representing the comparison result.
 */
int compare_num_passengers(const void* a, const void* b);

/**
 * @brief Frees the memory allocated for Query 6 results.
 *
 * @param info A pointer to the Query 6 results structure.
 */
void free_q6_info(Q6_results* info);

/**
 * @brief Gets the total count of Query 6 results.
 *
 * @param info A pointer to the Query 6 results structure.
 * @return The total count of Query 6 results.
 */
int get_q6_count(Q6_results* info);

/**
 * @brief Gets the flag indicating the type of Query 6 results.
 *
 * @param info A pointer to the Query 6 results structure.
 * @return The flag indicating the type of Query 6 results.
 */
int get_q6_flag(Q6_results* info);

/**
 * @brief Gets the airport ID at the specified index in Query 6 results.
 *
 * @param info A pointer to the Query 6 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the airport ID at the specified index in Query 6 results.
 */
char* get_q6_id(Q6_results* info, int index);

/**
 * @brief Gets the number of passengers at the specified index in Query 6 results.
 *
 * @param info A pointer to the Query 6 results structure.
 * @param index The index of the result to retrieve.
 * @return The number of passengers at the specified index in Query 6 results.
 */
int get_q6_num_passengers(Q6_results* info, int index);


//QUERY7


/**
 * @struct query7_results
 * @brief Represents the results of Query 7.
 */
typedef struct query7_results Q7_results;

/**
 * @struct info7
 * @brief Represents additional information associated with Query 7 results.
 */
typedef struct info7 Info7;

/**
 * @brief Gets the Query 7 results for airline information and delays.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog A pointer to the AirportCatalog containing airport information.
 * @return A pointer to the Query 7 results structure containing airline details and median delays.
 */
Q7_results* get_query7_results(command* cmd, AirportCatalog* catalog);

/**
 * @brief Compares airline information for sorting purposes.
 *
 * @param a A pointer to the first info7 structure.
 * @param b A pointer to the second info7 structure.
 * @return An integer representing the comparison result.
 */
int compare_airline_info(const void* a, const void* b);

/**
 * @brief Compares integers for sorting purposes.
 *
 * @param a A pointer to the first integer.
 * @param b A pointer to the second integer.
 * @return An integer representing the comparison result.
 */
int compare_int(const void* a, const void* b);

/**
 * @brief Calculates the median of an array of integers.
 *
 * @param delays An array of integers.
 * @param num_delays The number of elements in the array.
 * @return The calculated median value of delays.
 */
int calculate_median(int* delays, int num_delays);

/**
 * @brief Gets the total number of Query 7 results.
 *
 * @param info A pointer to the Query 7 results structure.
 * @return The total number of Query 7 results.
 */
int get_q7_num_infos(Q7_results* info);

/**
 * @brief Gets the flag indicating the type of Query 7 results.
 *
 * @param info A pointer to the Query 7 results structure.
 * @return The flag indicating the type of Query 7 results.
 */
int get_q7_flag(Q7_results* info);

/**
 * @brief Gets the airline name at the specified index in Query 7 results.
 *
 * @param info A pointer to the Query 7 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the airline name at the specified index in Query 7 results.
 */
char* get_q7_name(Q7_results* info, int index);

/**
 * @brief Gets the median delay at the specified index in Query 7 results.
 *
 * @param info A pointer to the Query 7 results structure.
 * @param index The index of the result to retrieve.
 * @return The median delay at the specified index in Query 7 results.
 */
int get_q7_median(Q7_results* info, int index);

/**
 * @brief Frees the memory allocated for Query 7 results.
 *
 * @param info A pointer to the Query 7 results structure.
 */
void free_q7infos(Q7_results* info);


//QUERY8


/**
 * @struct query8_results
 * @brief Represents the results of Query 8.
 */
typedef struct query8_results Q8_results;

/**
 * @brief Gets the Query 8 results for a specific hotel and reservation catalog.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param hotel A pointer to the Hotel structure for which reservations are queried.
 * @param catalog A pointer to the ReservationCatalog containing reservation information.
 * @return A pointer to the Query 8 results structure containing the result of the query.
 */
Q8_results* get_query8_results(command* cmd, Hotel* hotel, ReservationCatalog* catalog);

/**
 * @brief Gets the flag indicating the type of Query 8 results.
 *
 * @param info A pointer to the Query 8 results structure.
 * @return The flag indicating the type of Query 8 results.
 */
int get_q8_flag(Q8_results* info);

/**
 * @brief Gets the result of Query 8.
 *
 * @param info A pointer to the Query 8 results structure.
 * @return The result of Query 8.
 */
int get_q8_result(Q8_results* info);

//QUERY9


/**
 * @struct query9_results
 * @brief Represents the results of Query 9.
 */
typedef struct query9_results Q9_results;

/**
 * @struct info9
 * @brief Represents additional information associated with Query 9 results.
 */
typedef struct info9 Info9;

/**
 * @brief Gets the Query 9 results for users with a specific ID prefix.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog A pointer to the UserCatalog containing user information.
 * @param prefixo The prefix used for filtering user IDs.
 * @return A pointer to the Query 9 results structure containing user details.
 */
Q9_results* get_query9_results(command* cmd, UserCatalog* catalog, const char* prefixo);

/**
 * @brief Compares user information for sorting purposes.
 *
 * @param a A pointer to the first info9 structure.
 * @param b A pointer to the second info9 structure.
 * @return An integer representing the comparison result.
 */
int compare_info_q9(const void* a, const void* b);

/**
 * @brief Frees the memory allocated for Query 9 results.
 *
 * @param info A pointer to the Query 9 results structure.
 */
void free_q9_info(Q9_results* info);

/**
 * @brief Gets the total number of Query 9 results.
 *
 * @param info A pointer to the Query 9 results structure.
 * @return The total number of Query 9 results.
 */
int get_q9_num_infos(Q9_results* info);

/**
 * @brief Gets the flag indicating the type of Query 9 results.
 *
 * @param info A pointer to the Query 9 results structure.
 * @return The flag indicating the type of Query 9 results.
 */
int get_q9_flag(Q9_results* info);

/**
 * @brief Gets the user name at the specified index in Query 9 results.
 *
 * @param info A pointer to the Query 9 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the user name at the specified index in Query 9 results.
 */
char* get_q9_user_name_info(Q9_results* info, int index);

/**
 * @brief Gets the user ID at the specified index in Query 9 results.
 *
 * @param info A pointer to the Query 9 results structure.
 * @param index The index of the result to retrieve.
 * @return A pointer to the user ID at the specified index in Query 9 results.
 */
char* get_q9_user_id_info(Q9_results* info, int index);


//QUERY10


/**
 * @struct query10_results
 * @brief Represents the results of Query 10.
 */
typedef struct query10_results Q10_results;

/**
 * @struct info10
 * @brief Represents additional information associated with Query 10 results.
 */
typedef struct info10 Info10;

/**
 * @brief Gets the Query 10 results for a specific time period (year, month, or day).
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param table A pointer to the MetricsTable containing metrics information.
 * @return A pointer to the Query 10 results structure containing metrics details.
 */
Q10_results* get_query10_results_year(command* cmd, MetricsTable* table);
Q10_results* get_query10_results_month(command* cmd, MetricsTable* table);
Q10_results* get_query10_results_day(command* cmd, MetricsTable* table);

/**
 * @brief Compares integers for sorting purposes.
 *
 * @param a A pointer to the first integer.
 * @param b A pointer to the second integer.
 * @return An integer representing the comparison result.
 */
int compare_integer(const void *a, const void *b);

/**
 * @brief Gets the total number of Query 10 results.
 *
 * @param result A pointer to the Query 10 results structure.
 * @return The total number of Query 10 results.
 */
int get_query10_num_infos(Q10_results* result);

/**
 * @brief Gets the flag indicating the type of Query 10 results.
 *
 * @param result A pointer to the Query 10 results structure.
 * @return The flag indicating the type of Query 10 results.
 */
int get_query10_flag(Q10_results* result);

/**
 * @brief Gets the type of Query 10 results (year, month, or day).
 *
 * @param result A pointer to the Query 10 results structure.
 * @return The type of Query 10 results.
 */
int get_query10_type(Q10_results* result);

/**
 * @brief Gets the number of users at the specified index in Query 10 results.
 *
 * @param info A pointer to the Query 10 results structure.
 * @param index The index of the result to retrieve.
 * @return The number of users at the specified index in Query 10 results.
 */
int get_q10_num_users(Q10_results* info, int index);

/**
 * @brief Gets the number of flights at the specified index in Query 10 results.
 *
 * @param info A pointer to the Query 10 results structure.
 * @param index The index of the result to retrieve.
 * @return The number of flights at the specified index in Query 10 results.
 */
int get_q10_num_flights(Q10_results* info, int index);

/**
 * @brief Gets the number of passengers at the specified index in Query 10 results.
 *
 * @param info A pointer to the Query 10 results structure.
 * @param index The index of the result to retrieve.
 * @return The number of passengers at the specified index in Query 10 results.
 */
int get_q10_num_passengers(Q10_results* info, int index);

/**
 * @brief Gets the number of single passengers at the specified index in Query 10 results.
 *
 * @param info A pointer to the Query 10 results structure.
 * @param index The index of the result to retrieve.
 * @return The number of single passengers at the specified index in Query 10 results.
 */
int get_q10_num_single_passengers(Q10_results* info, int index);

/**
 * @brief Gets the number of reservations at the specified index in Query 10 results.
 *
 * @param info A pointer to the Query 10 results structure.
 * @param index The index of the result to retrieve.
 * @return The number of reservations at the specified index in Query 10 results.
 */
int get_q10_num_reservations(Q10_results* info, int index);

/**
 * @brief Gets the ID at the specified index in Query 10 results.
 *
 * @param info A pointer to the Query 10 results structure.
 * @param index The index of the result to retrieve.
 * @return The ID at the specified index in Query 10 results.
 */
int get_q10_id(Q10_results* info, int index);

/**
 * @brief Frees the memory allocated for Query 10 results.
 *
 * @param info A pointer to the Query 10 results structure.
 */
void free_q10infos(Q10_results* info);

#endif
