#ifndef DRAW_H
#define DRAW_H

#include <ncurses.h>
#include <string.h>

/**
 * @brief Draws a new window with specified dimensions and a title.
 *
 * @param yMax The maximum height of the window.
 * @param xMax The maximum width of the window.
 * @param multiplier The multiplier for adjusting the window size.
 * @param title The title to be displayed at the top of the window.
 * @return A pointer to the newly created window.
 */
WINDOW *draw_window(int yMax, int xMax, float multiplier, const char *title);

/**
 * @brief Draws a menu within a specified window.
 *
 * @param win A pointer to the window where the menu will be drawn.
 * @param menu_entries An array of menu entries to be displayed.
 * @param menu_size The size of the menu_entries array.
 * @param selected_item A pointer to the selected menu item (output parameter).
 */
void draw_menu(WINDOW *win, char **menu_entries, int menu_size, int *selected_item);

/**
 * @brief Draws the main menu.
 */
void draw_main_menu();

/**
 * @brief Draws the execute query menu.
 */
void draw_execute_query();

/**
 * @brief Draws the load dataset menu.
 */
void draw_load_dataset();

/**
 * @brief Draws the help menu with specified entries.
 *
 * @param win A pointer to the window where the help menu will be drawn.
 * @param entries An array of help menu entries to be displayed.
 * @param entries_size The size of the entries array.
 */
void draw_help(WINDOW* win, char* entries[], int entries_size);

/**
 * @brief Draws the results screen.
 */
void draw_results();

/**
 * @brief Draws a warning message within a specified window.
 *
 * @param win A pointer to the window where the warning will be drawn.
 * @param entries An array of warning message entries to be displayed.
 * @param num_entries The number of entries in the warning message.
 */
void draw_warning(WINDOW* win, char* entries[], int num_entries);

/**
 * @brief Draws an input box within a specified window and returns user input.
 *
 * @param win A pointer to the window where the input box will be drawn.
 * @return A dynamically allocated string containing the user input.
 */
char* draw_input_box(WINDOW *win);

/**
 * @brief Draws the results output within a specified window.
 *
 * @param win A pointer to the window where the results output will be drawn.
 * @param results A pointer to the results data.
 * @param query The query number associated with the results.
 */
void draw_results_output(WINDOW* win, void* results, int query);

/**
 * @brief Draws the upload screen within a specified window.
 *
 * @param win A pointer to the window where the upload screen will be drawn.
 */
void draw_upload(WINDOW* win);

#endif