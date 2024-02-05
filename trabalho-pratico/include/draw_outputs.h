#ifndef DRAW__OUTPUTS_H
#define DRAW__OUTPUTS_H

#include <ncurses.h>
#include <string.h>

/**
 * @brief Draws the results of Query 1 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 1.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query1_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 2 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 2.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query2_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 3 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 3.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query3_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 4 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 4.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query4_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 5 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 5.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query5_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 6 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 6.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query6_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 7 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 7.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query7_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 8 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 8.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query8_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 9 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 9.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query9_results(void* result, WINDOW* win);

/**
 * @brief Draws the results of Query 10 in a specified window.
 *
 * @param result A pointer to the query results data structure for Query 10.
 * @param win A pointer to the ncurses WINDOW where the results will be drawn.
 */
void draw_query10_results(void* result, WINDOW* win);

#endif