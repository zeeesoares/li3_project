#ifndef HELP_H
#define HELP_H

#include <ncurses.h>
#include "interactive.h"

/**
 * @brief Displays help information.
 *
 * @param manager A pointer to the Interactive_manager structure providing the necessary information for
 *                managing and displaying help information.
 */
void help(Interactive_manager* manager);

#endif