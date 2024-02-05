#include "flights_catalog.h"
#include "flight.h"
#include "catalog_manager.h"
#include "stats.h"
#include "utils.h"
#include <stdlib.h>


/*
 * Structure to represent a catalog of flights.
 */
struct FlightCatalog {
    GHashTable* flight_table;        /* Hash table to store Flight instances */
};


FlightCatalog* create_flight_catalog() {
    FlightCatalog* catalog = g_new(FlightCatalog, 1);
    catalog->flight_table = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)freeFlight);
    
    return catalog;
}


void build_and_add_flight(char** tokens, FlightCatalog* catalog, AirportCatalog* a_catalog, MetricsTable* m_table) {
    Flight* flight = build_flight(tokens);
    if (flight != NULL) {
        add_flight(catalog, flight);
        Airport* new = build_airport(tokens[4],get_flight_id(flight),get_flight_delay(flight));
        add_airport(a_catalog,new);

        char* date = (tokens[6]);
        int day = get_day(date);
        int month = get_month(date);
        int year = get_year(date);

        update_metrics_table(m_table,year,month,day,0,1,0,-1,0);
    }
}

void destroy_flight_catalog(FlightCatalog* catalog) {

    g_hash_table_destroy(catalog->flight_table);
    g_free(catalog);
}

void add_flight(FlightCatalog* catalog, Flight* flight) {
    int flight_id = get_flight_id(flight);

    g_hash_table_insert(catalog->flight_table, GINT_TO_POINTER(flight_id), flight);
}


Flight* get_flight(FlightCatalog* catalog, int flight_id) {
    return (Flight*)g_hash_table_lookup(catalog->flight_table, GINT_TO_POINTER(flight_id));
}


int validate_org_des(char* line) {
    return (strlen(line) == 3);
}

int validate_flight(char** line) {
    int res = 1;

    for (int i = 0; i < flights_fields - 1; i++) {
        if (line[i] == NULL) return 0;
    }

    if (!validate_org_des(line[4]) || !validate_org_des(line[5])) return 0;

    if (is_num(line[3]) == 0) return 0;

    int flag = 1;
    for (int j = 6; j < 10; j++) {
        if (line[j] == NULL) {
            flag = 0;
        }
    }
    if (flag) {
        Date* date1 = parse_date(line[6]); 
        Date* date2 = parse_date(line[7]); 
        Date* date3 = parse_date(line[8]); 
        Date* date4 = parse_date(line[9]); 
        if (validate_num(date1) == false || validate_num(date2) == false || validate_num(date3) == false || validate_num(date4) == false) res = 0;
        if (compare_dates(date1,date2) == false) res =  0;
        if (compare_dates(date3,date4) == false) res = 0;
        freeDate(date1);
        freeDate(date2);
        freeDate(date3);
        freeDate(date4);
        }
    else return 0;

    return res;
}   