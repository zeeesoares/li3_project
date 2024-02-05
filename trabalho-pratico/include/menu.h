#ifndef MENU_H
#define MENU_H

#include <ncurses.h>
#include "interactive.h"

#define MENU_ENTRIES 4


/**
 * @brief Displays and handles the main menu within an interactive manager.
 *
 * @param manager A pointer to the Interactive_manager structure providing the necessary information for
 *                managing the interactive session and main menu.
 */
void main_menu(Interactive_manager* manager);

#endif