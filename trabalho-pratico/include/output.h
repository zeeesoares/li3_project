#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdlib.h>
#include <stdio.h>

/*
 * Creates an output file in the specified project path.
 *
 * @param project_path A pointer to the project path where the output file will be created.
 */
void create_output_file(char* project_path);

/*
 * Creates a filename based on a folder and a string.
 *
 * @param folder A pointer to the folder where the filename will be created.
 * @param string A pointer to the string used in the filename.
 * @returns A pointer to the created filename.
 */
char* create_filename(char* folder, const char* string);

/*
 * Creates an output file for query results based on a counter.
 *
 * @param queries_counter The counter used in the filename.
 * @returns A pointer to the created output file.
 */
FILE* create_output_query_file(int queries_counter);

/*
 * Writes output data to the specified output filename.
 *
 * @param tokens An array of output data tokens.
 * @param output_filename A pointer to the output filename.
 * @param max_tokens The maximum number of tokens.
 */
void write_output_file(char** tokens,FILE* output_file, int max_tokens);

/*
 * Writes query results to the specified output file.
 *
 * @param result A pointer to the string containing the query results.
 * @param output_file A pointer to the output file.
 */
void write_output_queries_file(void* result, int query, FILE* output_file);


/**
 * @brief Writes the results of Query 1 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 1.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query1_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 2 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 2.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query2_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 3 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 3.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query3_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 4 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 4.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query4_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 5 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 5.
 * @param output_file A pointer to the FILE where the results will be written.
 */

void write_query5_results(void* result, FILE* output_file);
/**
 * @brief Writes the results of Query 6 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 6.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query6_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 7 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 7.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query7_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 8 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 8.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query8_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 9 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 9.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query9_results(void* result, FILE* output_file);

/**
 * @brief Writes the results of Query 10 to a specified output file.
 *
 * @param result A pointer to the query results data structure for Query 10.
 * @param output_file A pointer to the FILE where the results will be written.
 */
void write_query10_results(void* result, FILE* output_file);

#endif
