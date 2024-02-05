#ifndef EXEC_QUERY_H
#define EXEC_QUERY_H

#include <ncurses.h>
#include "interactive.h"

/**
 * @brief Executes a query within an interactive manager.
 *
 * @param manager A pointer to the Interactive_manager structure containing the necessary information
 *                for managing and executing queries interactively.
 */
void execute_query(Interactive_manager* manager);

#endif