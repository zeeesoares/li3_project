#include "help.h"
#include "menu.h"
#include "draw.h"


void help(Interactive_manager* manager) {
    initscr();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);


    char *entries[10] = {
        "1 <ID> [user|flight|reservation] - Shows the information about the id given",
        "2 <ID> [flights|reservations] - Lists the flights/reservations in ascending order",
        "3 <ID> [hotel] - Show the average rating of a hotel",
        "4 <ID> [hotel] - List hotel reservations, sorted by start date",
        "5 <Name> <Begin_date> <End_date> - List flights originating from a given airport, between two dates",
        "6 <Year> <N> - List the top N airports with the most passengers, for a given year",
        "7 <N> - List the top N airports with the highest median delays",
        "8 <Id> <Begin_date> <End_date> - Display total revenue for a hotel between two dates",
        "9 <Prefix> - List all users whose name starts with the prefix passed by argument",
        "10 <[year [month]]> - Display various general application metrics"
    };

    char *title = "Help";
    WINDOW *win = draw_window(yMax, xMax, 1, title);

    draw_help(win,entries,10);
    refresh();
    wrefresh(win);

    getch();

    change_page_and_clear(manager,win,MAIN_MENU);
    main_menu(manager);   
}