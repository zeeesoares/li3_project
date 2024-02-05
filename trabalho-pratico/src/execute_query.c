#include "execute_query.h"
#include "draw.h"
#include "menu.h"
#include "queries.h"
#include "results_output.h"

void execute_query(Interactive_manager* manager) {
    initscr();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    char *title = "Execute Query";
    WINDOW *win = draw_window(yMax, xMax, 0.3, title);


    char* input = draw_input_box(win);

    wrefresh(win);

    char** tokens = parse_query_line(input,10);
    command* cmd = build_command(tokens, 6);
    free_tokens(tokens,6);
    free(input);
    int query = get_query_command(cmd);

    void* results = NULL;

    if (validate_command(cmd)) {
        results = execute_command_interactive(cmd,get_interactive_catalog_manager(manager));
        free_command(cmd);
        change_page_and_clear(manager,win,RESULT_OUTPUT);
        results_output(manager,results,query);
    }
    else {
        free_command(cmd);
        char* warning_dataset[] = {"Query not valid!", "Please insert a valid format, or 'q to exist!"};
        win = draw_window(yMax, xMax, 0.3, title);
        draw_warning(win,warning_dataset,2);
        wrefresh(win);
        int ch = getch();

        if (ch == 'q') {
            change_page_and_clear(manager,win,MAIN_MENU);
            main_menu(manager);
        }
        change_page_and_clear(manager,win, EXECUTE_QUERY);
        execute_query(manager);
    }


    getch();

    change_page_and_clear(manager,win,MAIN_MENU);
    main_menu(manager);   
}
