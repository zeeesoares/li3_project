#ifndef QUERIES_H
#define QUERIES_H

#include <stdio.h>
#include <stdlib.h>
#include "catalog_manager.h"
#include <string.h>
#include "batch.h"


/**
 * @struct command
 * @brief Represents a command with its type, flag, and arguments.
 */
typedef struct command command;

/**
 * @brief Gets the type of the command.
 *
 * @param cmd A pointer to the command structure.
 * @return An integer representing the type of the command.
 */
int get_cmd_type(command* cmd);

/**
 * @brief Gets the flag of the command.
 *
 * @param cmd A pointer to the command structure.
 * @return An integer representing the flag of the command.
 */
int get_cmd_flag(command* cmd);

/**
 * @brief Gets the number of arguments in the command.
 *
 * @param cmd A pointer to the command structure.
 * @return An integer representing the number of arguments in the command.
 */
int get_cmd_num_args(command* cmd);

/**
 * @brief Gets the arguments at the specified index in the command.
 *
 * @param cmd A pointer to the command structure.
 * @param index The index of the argument to retrieve.
 * @return A pointer to the argument at the specified index in the command.
 */
char* get_cmd_args(command* cmd, int index);



/*
 * Builds a command structure from an array of tokens and the number of tokens.
 *
 * @param tokens An array of tokens representing the command.
 * @param num_tokens The number of tokens in the array.
 * @returns A pointer to the built command structure.
 */
command* build_command(char** tokens, int num_tokens);

/**
 * @brief Gets the query command from the command structure.
 *
 * @param cmd A pointer to the command structure.
 * @return An integer representing the query command.
 */
int get_query_command(command* cmd);


/*
 * Executes a command based on the input line and the CatalogManager.
 *
 * @param line A pointer to the input line containing the command.
 * @param catalog A pointer to the CatalogManager instance.
 * @returns A pointer to the result string of the executed command.
 */
void execute_command (char* line, CatalogManager* catalog, FILE* output_file);

/**
 * @brief Executes an interactive command on the CatalogManager and returns the result.
 *
 * @param cmd A pointer to the command structure.
 * @param catalog A pointer to the CatalogManager.
 * @return A pointer to the result of the command execution. The type of the result may vary based on the command.
 */
void* execute_command_interactive(command* cmd, CatalogManager* catalog);

/**
 * @brief Validates the given command for correctness.
 *
 * @param cmd A pointer to the command structure.
 * @return An integer representing the validation result:
 */
int validate_command(command* cmd);


/*
 * Parses a query file and executes the queries using the CatalogManager.
 *
 * @param filename A pointer to the query file.
 * @param max_tokens The maximum number of tokens expected in a line.
 * @param catalog_manager A pointer to the CatalogManager instance.
 */
void parse_query_file(FILE* filename, int max_tokens, CatalogManager* catalog_manager);

/*
 * Parses a line of the query file into an array of tokens.
 *
 * @param line A pointer to the line of the query file.
 * @param num_tokens The number of tokens expected in the line.
 * @returns An array of parsed tokens.
 */
char** parse_query_line(char* line, int num_tokens);

/*
 * Frees the memory allocated for a command structure.
 *
 * @param cmd A pointer to the command structure.
 */
void free_command(command* cmd);

/*
 * Executes Query 1 based on the command and the CatalogManager.
 *
 * @param cmd A pointer to the command structure.
 * @param catalog A pointer to the CatalogManager instance.
 * @returns A pointer to the result string of Query 1.
 */

void* query1(command* cmd, CatalogManager* catalog);


/*
 * Executes Query 2 based on the command and the CatalogManager.
 *
 * @param cmd A pointer to the command structure.
 * @param catalog_manager A pointer to the CatalogManager instance.
 * @returns A pointer to the result string of Query 2.
 */
void* query2(command* cmd, CatalogManager* catalog_manager);


/*
 * Executes Query 3 based on the command and the CatalogManager.
 *
 * @param cmd A pointer to the command structure.
 * @param catalog_manager A pointer to the CatalogManager instance.
 * @returns A pointer to the result string of Query 3.
 */
void* query3(command* cmd, CatalogManager* catalog_manager);


/**
 * @brief Executes Query 4 based on the given command and CatalogManager.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog_manager A pointer to the CatalogManager.
 * @return A pointer to the result of Query 4 execution. The type of the result may vary based on the query.
 */
void* query4(command* cmd, CatalogManager* catalog_manager);

/**
 * @brief Executes Query 5 based on the given command and CatalogManager.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog_manager A pointer to the CatalogManager.
 * @return A pointer to the result of Query 5 execution. The type of the result may vary based on the query.
 */
void* query5(command* cmd, CatalogManager* catalog_manager);

/**
 * @brief Executes Query 6 based on the given command and CatalogManager.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog_manager A pointer to the CatalogManager.
 * @return A pointer to the result of Query 6 execution. The type of the result may vary based on the query.
 */
void* query6(command* cmd, CatalogManager* catalog_manager);

/**
 * @brief Executes Query 7 based on the given command and CatalogManager.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog_manager A pointer to the CatalogManager.
 * @return A pointer to the result of Query 7 execution. The type of the result may vary based on the query.
 */
void* query7(command* cmd, CatalogManager* catalog_manager);

/**
 * @brief Executes Query 8 based on the given command and CatalogManager.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog_manager A pointer to the CatalogManager.
 * @return A pointer to the result of Query 8 execution. The type of the result may vary based on the query.
 */
void* query8(command* cmd, CatalogManager* catalog_manager);

/**
 * @brief Executes Query 9 based on the given command and CatalogManager.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog_manager A pointer to the CatalogManager.
 * @return A pointer to the result of Query 9 execution. The type of the result may vary based on the query.
 */
void* query9(command* cmd, CatalogManager* catalog_manager);

/**
 * @brief Executes Query 10 based on the given command and CatalogManager.
 *
 * @param cmd A pointer to the command structure containing query parameters.
 * @param catalog_manager A pointer to the CatalogManager.
 * @return A pointer to the result of Query 10 execution. The type of the result may vary based on the query.
 */
void* query10(command* cmd, CatalogManager* catalog_manager);


#endif
