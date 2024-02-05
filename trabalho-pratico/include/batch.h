#ifndef BATCH_H
#define BATCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "parser.h"
#include "output.h"
#include "flights_catalog.h"
#include "queries.h"
#include "passengers_catalog.h"
#include "catalog_manager.h"
#include "user_catalog.h"
#include "reservation_catalog.h"
#include "hotel_catalog.h"
#include "airport_catalog.h"
#include "stats.h"


/*
 * Executes a batch process based on command-line arguments.
 *
 * @param argv An array of command-line arguments.
 * @returns The exit code of the batch process.
 */
int batch(char** argv);

/*
 * Parses datasets within a specified folder and adds them to the CatalogManager.
 *
 * @param folder_path The path to the folder containing datasets.
 * @param catalog A pointer to the CatalogManager.
 */
void parse_datasets(const char* folder_path, CatalogManager* catalog);

/*
 * Sets up a CatalogManager by parsing datasets from a specified folder.
 *
 * @param catalog A pointer to the CatalogManager to be set up.
 * @param folder The path to the folder containing datasets.
 * @returns 1 if setup is successful, 0 otherwise.
 */
int setup_catalog(CatalogManager* catalog, char* folder);


#endif
