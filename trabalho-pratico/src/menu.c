#include "menu.h"
#include "interactive.h"
#include "draw.h"
#include "help.h"
#include "execute_query.h"
#include "load_dataset.h"


#define MENU_ENTRIES 4

void main_menu(Interactive_manager* manager) {
    initscr();
    curs_set(0);
    noecho();

    keypad(stdscr, TRUE);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    char *menu_entries[4] = {"Execute query", "Load dataset","Help", "Leave"};

    const char *title = "42 airline & booking";
    WINDOW *win = draw_window(yMax,xMax,1,title);
    mvwprintw(win,3,2,"Loaded from: %s", get_interactive_dataset(manager));

    int dataset_is_on = get_interactive_dataset_on(manager);
    if (!dataset_is_on) {
        wattron(win, A_BLINK);
        mvwprintw(win,yMax/6,xMax/2-12,"<Dataset is not loaded!>");
        wattroff(win, A_BLINK);
    } else {
        wattron(win, A_REVERSE);
        mvwprintw(win,yMax/6,xMax/2-10,"<Dataset is loaded!>");
        wattroff(win, A_REVERSE);
    }


    int selected_item = 0;

    draw_menu(win, menu_entries, MENU_ENTRIES, &selected_item);

    handle_input(win, draw_menu, menu_entries, MENU_ENTRIES, &selected_item);

    switch (selected_item) {   
        case 0:
            if (dataset_is_on) {
                change_page_and_clear(manager,win,EXECUTE_QUERY);
                execute_query(manager);
            } else {
                char* warning_dataset[] = {"Dataset is not loaded!!", "Load the dataset in the option below!"};
                win = draw_window(yMax, xMax, 0.3, title);
                draw_warning(win,warning_dataset,2);
                wrefresh(win);
                getch();
                change_page_and_clear(manager,win, MAIN_MENU);
                main_menu(manager);
            }
            break;
        case 1:
            change_page_and_clear(manager,win,LOAD_DATASET);
            load_dataset(manager);
            break; 
        case 2:
            change_page_and_clear(manager,win,HELP);
            help(manager);
            break;
        case 3:
            echo();
            free_interactive(manager);
            delwin(win);
            endwin();
            exit(1);
            break;
        default:
            main_menu(manager);
            change_page_and_clear(manager,win,MAIN_MENU);
            break;
    }
    return;
}