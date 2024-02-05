#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalog_manager.h"


/*
 * Parses a CSV file, invoking a callback function for each line.
 * 
 * @param filename     A pointer to the CSV file to be parsed.
 * @param catalog      A pointer to the catalog used during parsing.
 * @param f            A callback function applied to each line of the CSV file, used to build an entitie.
 * @param g            A callback function applied to each line of the CSV file, user to validate the line.
 * @param errors_file  The name of the output_erros file.
 * @param max_tokens   The maximum number of tokens expected in a line.
 */
void parse_csv_file(FILE* filename, void * catalog, void(*f)(char**, void*, FILE*), int(*g) (char**), FILE* errors_file, int max_tokens);


/*
 * Parses a line of the CSV.
 * 
 * @param line         A line of the CSV file to be parsed.
 * @param delimiter    The number of necessary tokens.
 * @return             A list of separated tokens (an array of strings).
 */
char** parse_csv_line(char* line, int delimiter);


/*
 * Frees the memory allocated for an array of tokens.
 *
 * @param tokens       An array of strings representing tokens.
 * @param num_tokens   The number of tokens in the array.
 */
void free_tokens(char** tokens, int num_tokens);


#endif



