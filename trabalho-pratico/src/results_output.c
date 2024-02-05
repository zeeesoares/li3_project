#include "results_output.h"
#include "menu.h"
#include "draw.h"

void results_output(Interactive_manager* manager, void* results, int query) {
    initscr();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    char *title = "Query Output";
    WINDOW *win = draw_window(yMax, xMax, 1, title);


    draw_results_output(win,results,query);

    getch();

    change_page_and_clear(manager, win, MAIN_MENU);
    main_menu(manager);

    endwin();
}