#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "catalog_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ncurses.h>
/**
 * @enum page
 * @brief Represents different pages in the interactive session.
 */
enum page {
  MAIN_MENU,
  EXECUTE_QUERY,
  LOAD_DATASET,
  HELP,
  RESULT_OUTPUT
};

/**
 * @struct Interactive_manager
 * @brief Represents a manager for handling interactive sessions.
 */
typedef struct interactive_manager Interactive_manager;

/**
 * @brief Creates a new interactive manager.
 *
 * @return A pointer to the newly created Interactive_manager.
 */
Interactive_manager* create_interactive_manager();

/**
 * @brief Initiates the interactive session.
 */
void interactive();

/**
 * @brief Changes the current page in the interactive session and clears the window.
 *
 * @param manager A pointer to the Interactive_manager.
 * @param win A pointer to the ncurses WINDOW to be cleared.
 * @param page_id The identifier of the new page to be set.
 */
void change_page_and_clear(Interactive_manager* manager, WINDOW* win, enum page page_id);

/**
 * @brief Handles user input for menu navigation.
 *
 * @param win A pointer to the ncurses WINDOW where the menu is displayed.
 * @param draw_menu A function to draw the menu on the window.
 * @param menu_entries An array of menu entry strings.
 * @param menu_size The size of the menu.
 * @param selected_item A pointer to the variable storing the selected menu item.
 */
void handle_input(WINDOW* win, void (*draw_menu)(WINDOW*, char**, int, int*), char** menu_entries, int menu_size, int* selected_item);

/**
 * @brief Sets the current page of the interactive manager.
 *
 * @param manager A pointer to the Interactive_manager.
 * @param page_id The identifier of the new page to be set.
 */
void set_interactive_manager_page(Interactive_manager* manager, enum page page_id);

/**
 * @brief Enables or disables the interactive dataset mode.
 *
 * @param manager A pointer to the Interactive_manager.
 * @param on_off 1 to enable, 0 to disable.
 */
void set_interactive_dataset_on(Interactive_manager* manager, int on_off);

/**
 * @brief Sets the interactive dataset.
 *
 * @param manager A pointer to the Interactive_manager.
 * @param dataset The name of the dataset to be set.
 */
void set_interactive_dataset(Interactive_manager* manager, char* dataset);

/**
 * @brief Gets the current page of the interactive manager.
 *
 * @param manager A pointer to the Interactive_manager.
 * @return The identifier of the current page.
 */
enum page get_interactive_manager_page(Interactive_manager* manager);

/**
 * @brief Gets the status of the interactive dataset mode.
 *
 * @param manager A pointer to the Interactive_manager.
 * @return 1 if the interactive dataset mode is on, 0 otherwise.
 */
int get_interactive_dataset_on(Interactive_manager* manager);

/**
 * @brief Gets the name of the interactive dataset.
 *
 * @param manager A pointer to the Interactive_manager.
 * @return The name of the current dataset.
 */
char* get_interactive_dataset(Interactive_manager* manager);

/**
 * @brief Gets the CatalogManager associated with the interactive manager.
 *
 * @param manager A pointer to the Interactive_manager.
 * @return A pointer to the CatalogManager.
 */
CatalogManager* get_interactive_catalog_manager(Interactive_manager* manager);

/**
 * @brief Frees the memory allocated for the Interactive_manager.
 *
 * @param manager A pointer to the Interactive_manager to be freed.
 */
void free_interactive(Interactive_manager* manager);

#endif