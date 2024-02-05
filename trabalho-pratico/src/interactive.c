#include "interactive.h"
#include "menu.h"

struct interactive_manager {
    enum page page_id;
    char* dataset;
    int dataset_on;
    CatalogManager* catalog_manager;
};

void interactive() {
    setlocale(LC_COLLATE, "en_US.UTF-8");

    Interactive_manager* manager = create_interactive_manager();

    main_menu(manager);

}


Interactive_manager* create_interactive_manager() {
    Interactive_manager* manager = malloc(sizeof(Interactive_manager));

    manager->dataset = NULL;
    manager->dataset_on = 0;
    manager->page_id = MAIN_MENU;
    UserCatalog* u_catalog = create_user_catalog();
    FlightCatalog*  f_catalog = create_flight_catalog();
    ReservationCatalog* r_catalog = create_reservation_catalog();
    HotelCatalog* h_catalog = create_hotel_catalog();
    AirportCatalog* a_catalog = create_airport_catalog();
    MetricsTable* m_table = create_metrics_table();
    manager->catalog_manager = create_catalog_manager(u_catalog,f_catalog,r_catalog,h_catalog,a_catalog,m_table);

    return manager;
}
    

void change_page_and_clear(Interactive_manager* manager, WINDOW* win, enum page page_id) {
    wclear(win);
    wrefresh(win);
    delwin(win);
    set_interactive_manager_page(manager, page_id);
}

void handle_input(WINDOW *win, void (*draw_menu)(WINDOW *, char **, int, int *), char **menu_entries, int menu_size, int *selected_item) {
    int ch;

    while (1) {
        draw_menu(win, menu_entries, menu_size, selected_item);

        wrefresh(win);

        ch = getch(); 

        switch (ch) {
            case KEY_UP:
                *selected_item = (*selected_item - 1 + menu_size) % menu_size;
                break;
            case KEY_DOWN:
                *selected_item = (*selected_item + 1) % menu_size;
                break;
            case 10:
                return;
        }

        clear();
    }
}

void set_interactive_manager_page(Interactive_manager* manager, enum page page_id) {
    manager->page_id = page_id;
}

void set_interactive_dataset_on(Interactive_manager* manager, int on_off) {
    manager->dataset_on = on_off;
}

void set_interactive_dataset(Interactive_manager* manager, char* dataset) {
    manager->dataset = dataset;
}

enum page get_interactive_manager_page(Interactive_manager* manager) {
    return manager->page_id;
}

int get_interactive_dataset_on(Interactive_manager* manager) {
    return manager->dataset_on;
}

char* get_interactive_dataset(Interactive_manager* manager) {
    return manager->dataset;
}

CatalogManager* get_interactive_catalog_manager(Interactive_manager* manager) {
    return manager->catalog_manager;
}

void free_interactive(Interactive_manager* manager) {
    free(manager->dataset);
    CatalogManager* catalog = get_interactive_catalog_manager(manager);
    UserCatalog* u_catalog = get_user_catalog(catalog);
    FlightCatalog*  f_catalog = get_flight_catalog(catalog);
    ReservationCatalog* r_catalog = get_reservation_catalog(catalog);
    HotelCatalog* h_catalog = get_hotel_catalog(catalog);
    AirportCatalog* a_catalog = get_airport_catalog(catalog);
    MetricsTable* m_table = get_metrics_table(catalog);


    destroy_user_catalog(u_catalog); 
    destroy_flight_catalog(f_catalog); 
    destroy_reservation_catalog(r_catalog);
    destroy_hotel_catalog(h_catalog);
    destroy_airport_catalog(a_catalog);
    destroy_metrics_table(m_table);

    free(catalog);
    free(manager);
}