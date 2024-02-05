#ifndef RESULTS_OUTPUT_H
#define RESULTS_OUTPUT_H

#include <ncurses.h>
#include "interactive.h"


/**
 * @brief Outputs the results of a query in the interactive mode.
 *
 * @param manager A pointer to the Interactive_manager.
 * @param results A pointer to the results of a query. The type of the results may vary based on the query.
 * @param query An integer representing the query number or type.
 */
void results_output(Interactive_manager* manager, void* results, int query);


#endif