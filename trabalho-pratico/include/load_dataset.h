#ifndef LOAD_DATASET_H
#define LOAD_DATASET_H

#include <ncurses.h>
#include "interactive.h"


/**
 * @brief Initiates the process of loading a dataset within an interactive manager.
 *
 * @param manager A pointer to the Interactive_manager structure providing the necessary information for
 *                managing the interactive session and loading datasets.
 */
void load_dataset(Interactive_manager* manager);

#endif