#ifndef PROGRAMA_TESTE
#define PROGRAMA_TESTE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include "batch.h"
#include "date.h"
#include "parser.h"
#include "output.h"
#include "flights_catalog.h"
#include "queries.h"
#include "passengers_catalog.h"
#include "catalog_manager.h"
#include "user_catalog.h"
#include "reservation_catalog.h"
#include "stats.h"

/*
 * Creates and returns a CatalogManager based on command-line arguments.
 *
 * @param arg An array of command-line arguments.
 * @returns A pointer to the created CatalogManager.
 */
CatalogManager* batch_t(char** arg);

/*
 * Executes a query based on the provided dataset path, output folder, and CatalogManager.
 *
 * @param datasetPath The path to the dataset.
 * @param outputFolder The folder for storing query results.
 * @param catalog_manager A pointer to the CatalogManager.
 * @param queryNumber The number identifying the query to be executed.
 * @returns The exit code of the query execution.
 */
int execute_query(const char* datasetPath, const char* outputFolder, CatalogManager* catalog_manager, int queryNumber);

/*
 * Compares the output of a query with the expected output stored in the specified folder.
 *
 * @param outputFolder The folder containing expected query outputs.
 * @param query_number The number identifying the query to be compared.
 * @returns 0 if the outputs match, or the query number if an incongruence is found.
 */
int compare_query(const char* outputFolder, int query_number);

/*
 * The main function responsible for executing the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @returns The exit code of the program.
 */
int main(int argc, char** argv);

#endif
