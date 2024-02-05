#include "load_dataset.h"
#include "batch.h"
#include "menu.h"
#include "draw.h"

#define LOAD_ENTRIES 2

void load_dataset(Interactive_manager *manager)
{
    initscr();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = draw_window(yMax, xMax, 0.50, "Load Dataset");
    char *input = draw_input_box(win);

    char *menu_entries[2] = {"Confirm", "Exit"};

    int selected_item = 0;

    draw_menu(win, menu_entries, LOAD_ENTRIES, &selected_item);

    handle_input(win, draw_menu, menu_entries, LOAD_ENTRIES, &selected_item);

    switch (selected_item)
    {
    case 0:
        if (input)
        {
            CatalogManager *catalog = get_interactive_catalog_manager(manager);
            draw_upload(win);
            int ret = setup_catalog(catalog, input);
            if (!ret)
            {
                char *warning_dataset[] = {"Dataset is loaded!!", "You can now execute queries!"};
                win = draw_window(yMax, xMax, 0.3, "Load Dataset");
                draw_warning(win, warning_dataset, 2);
                set_interactive_dataset_on(manager, 1);
                set_interactive_dataset(manager, input);
                wgetch(win);
                change_page_and_clear(manager, win, MAIN_MENU);
                main_menu(manager);
            }
            else
            {
                char *warning_dataset[] = {"Dataset is invalid!!", "Please insert a new path!"};
                win = draw_window(yMax, xMax, 0.3, "Load Dataset");
                draw_warning(win, warning_dataset, 2);
                wgetch(win);
                change_page_and_clear(manager, win, LOAD_DATASET);
                load_dataset(manager);
            }
        }
        break;
    case 1:
        change_page_and_clear(manager, win, MAIN_MENU);
        main_menu(manager);
        break;
    default:
        break;
    }
}