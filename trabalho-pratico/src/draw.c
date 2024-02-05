#include "draw.h"
#include "string.h"
#include <stdlib.h>
#include "queries.h"
#include "draw_outputs.h"


WINDOW *draw_window(int yMax, int xMax, float multiplier,const char *title) {
  int new_y = (int)(multiplier * yMax);
  int new_x = (int)(multiplier * xMax);

  WINDOW *win = newwin(new_y, new_x, (yMax - new_y) / 2, (xMax - new_x) / 2);

  // Draw the box and the title
  box(win, 0, 0);
  mvwprintw(win, 1, 2,"%s", title);

  return win;
}

void draw_menu(WINDOW *win, char **menu_entries, int menu_size, int *selected_item) {
    int yMax, xMax;
    getmaxyx(win, yMax, xMax);

    box(win, 0, 0);

    int centerX = xMax / 2;
    int centerY = yMax / 2;

    int verticalSpacing = 4;

    for (int i = 0; i < menu_size; i++) {
        int yPos = centerY - (menu_size * verticalSpacing) / 2 + i * verticalSpacing;

        int textLength = strlen(menu_entries[i]);
        int xPos = centerX - textLength / 2;

        if (i == *selected_item) {
            wattron(win, A_REVERSE);
            mvwprintw(win, yPos, xPos, "%s", menu_entries[i]);
            wattroff(win, A_REVERSE);
        } else {
            mvwprintw(win, yPos, xPos, "%s", menu_entries[i]);
        }
    }

    refresh();
}


void draw_execute_query() {

}

void draw_load_dataset() {

}


void draw_results_output(WINDOW* win, void* results, int query) {
    int yMax, xMax;
    getmaxyx(win, yMax, xMax);

    // Defina as dimensões do novo display
    int displayWidth = xMax/2; // Ajuste conforme necessário
    int displayHeight = yMax - 10; // Ajuste conforme necessário

    // Calcule as coordenadas para centralizar o novo display na janela principal
    int startX = (xMax - displayWidth) / 2;
    int startY = (yMax - displayHeight) / 2;

    // Crie o novo display como uma sub-janela
    WINDOW* display = subwin(win, displayHeight, displayWidth, startY, startX);
    wrefresh(win);

    // Desenhe uma caixa ao redor do novo display
    box(display, 0, 0);
    switch (query)
    {
    case 1:
        draw_query1_results(results,display);
        break;
    case 2:
        draw_query2_results(results,display);
        break;
    case 3:
        draw_query3_results(results,display);
        break;
    case 4:
        draw_query4_results(results,display);
        break;
    case 5:
        draw_query5_results(results,display);
        break;
    case 6:
        draw_query6_results(results,display);
        break;
    case 7:
        draw_query7_results(results,display);
        break;
    case 8:
        draw_query8_results(results,display);
        break;
    case 9:
        draw_query9_results(results,display);
        break;
    case 10:
        draw_query10_results(results,display);
        break;
    default:
        break;
    }

    wrefresh(display);
    wrefresh(win);

}

void draw_help(WINDOW* win, char* entries[], int entries_size) {
    int yMax, xMax;
    getmaxyx(win, yMax, xMax);

    box(win, 0, 0);

    int centerX = xMax / 2;
    int centerY = yMax / 2;

    int verticalSpacing = 2;

    for (int i = 0; i < entries_size; i++) {
        int yPos = centerY - (entries_size * verticalSpacing) / 2 + i * verticalSpacing;

        int xPos = centerX/2;

        mvwprintw(win, yPos, xPos, "%s", entries[i]);
    }

    mvwprintw(win,yMax-2,centerX-13,"Press any button to return!");

}


void draw_results() {

}

void draw_warning(WINDOW* win,char* entries[],int num_entries) {
    int yMax, xMax;
    getmaxyx(win, yMax, xMax);
    box(win, 0, 0);
    int centerX = xMax / 2;
    int centerY = yMax / 2;

    int verticalSpacing = 2;

    for (int i = 0; i < num_entries; i++) {
        int yPos = centerY - (num_entries * verticalSpacing) / 2 + i * verticalSpacing;

        int xPos = centerX/2- 10;

        mvwprintw(win, yPos, xPos, "%s", entries[i]);
    }

    mvwprintw(win,yMax-1,centerX-13,"Press any button to return!");
    refresh();
}

char *draw_input_box(WINDOW *win) {
    int yMax, xMax;
    getmaxyx(win, yMax, xMax);
    echo();
    
    box(win, 0, 0);
    wrefresh(win);

    mvwprintw(win,yMax-1,xMax/2-13,"Press ENTER to continue!");
    mvwprintw(win, 3, 2, "> ");
    wrefresh(win); 

    keypad(win, TRUE);
    curs_set(1);

    // Allocate memory for input with a reasonable maximum length
    char *input = malloc(sizeof(char) * 128);

    if (input != NULL) {
        wgetnstr(win, input, 127);
    }

    curs_set(0);  // Hide cursor after input

    noecho();
    return input;
}

void draw_upload(WINDOW* win) {
    wclear(win);
    int yMax, xMax;
    getmaxyx(win, yMax, xMax);
    box(win, 0, 0);

    int centerX = xMax / 2;
    int centerY = yMax / 2;

    wattron(win, A_BLINK);
    mvwprintw(win,centerY,centerX - 3,"Loading");
    wattroff(win, A_BLINK);

    wrefresh(win);
}