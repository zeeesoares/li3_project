#include "airport_catalog.h"


typedef struct AirportCatalog {
    GHashTable* airport_table;
    char** valid_airport_ids;
    int valid_airport_ids_count;
} AirportCatalog;

AirportCatalog* create_airport_catalog() {
    AirportCatalog* catalog = g_new(AirportCatalog, 1);
    catalog->airport_table = g_hash_table_new(g_str_hash, g_str_equal);
    catalog->valid_airport_ids = g_new(char*, 0);
    catalog->valid_airport_ids_count = 0;

    return catalog;
}

void add_airport(AirportCatalog* catalog, Airport* airport) {
    char* airport_id = get_airport_catalog_id(airport);

    Airport* existing = get_airport(catalog, airport_id);
    if (existing) {
        int num_passengers = get_airport_num_passengers(existing)+1;
        int count = get_airport_num_flights(existing)+1;
 
        set_airport_num_passengers(existing,num_passengers);
        set_airport_num_flights(existing, count);
        int* flights = get_airport_flights(existing);
        int* delays = get_airport_delays(existing);
        int* new_flights = get_airport_flights(airport);
        int* new_delays = get_airport_delays(airport);
        flights = realloc(flights, count * sizeof(int));
        delays = realloc(delays, count * sizeof(int));
        flights[count - 1] = new_flights[0];
        delays[count - 1] = new_delays[0];
        set_airport_flights(existing, flights);
        set_airport_delays(existing,delays);

        free(airport_id);
        free(new_flights);
        free(new_delays);
        free(airport);
    } else {
        g_hash_table_insert(catalog->airport_table, airport_id, airport);
        catalog->valid_airport_ids_count++;
        catalog->valid_airport_ids = realloc(catalog->valid_airport_ids,
                                             catalog->valid_airport_ids_count * sizeof(char*));
        catalog->valid_airport_ids[catalog->valid_airport_ids_count - 1] = airport_id;
    }
}


void add_passenger_to_airport(char* id, AirportCatalog* catalog, int year) {
    char* uppercase_id = id;

    Airport* airport = get_airport(catalog, uppercase_id);

    if (airport) {
        int* num_passengers_per_year = get_airport_num_passengers_per_year(airport);
        if (num_passengers_per_year == NULL) {
            num_passengers_per_year = g_new(int, MAX_YEARS - BASE_YEAR);
            memset(num_passengers_per_year, 0, (MAX_YEARS - BASE_YEAR) * sizeof(int));
        }

        if (year >= BASE_YEAR && year < BASE_YEAR + MAX_YEARS) {
            num_passengers_per_year[year - BASE_YEAR]++;
        } else {
            fprintf(stderr, "Ano fora do intervalo esperado.\n");
        }

        set_airport_num_passengers_per_year(airport,num_passengers_per_year);

    } else {
        airport = create_airport();
        set_airport_catalog_id(airport,uppercase_id);
        int num_passengers = get_airport_num_passengers(airport)+1;
        set_airport_num_passengers(airport,num_passengers);
        int* num_passengers_per_year = g_new(int, MAX_YEARS - BASE_YEAR);
        memset(num_passengers_per_year, 0, (MAX_YEARS - BASE_YEAR) * sizeof(int));

        if (year >= BASE_YEAR && year < BASE_YEAR + MAX_YEARS) {
            num_passengers_per_year[year - BASE_YEAR]++;
        } else {
            fprintf(stderr, "Ano fora do intervalo esperado.\n");
        }
        set_airport_num_passengers_per_year(airport, num_passengers_per_year);

        add_airport(catalog, airport);
    }
    free(id);
}


void destroy_airport_catalog(AirportCatalog* catalog) {
    for (int i = 0; i < catalog->valid_airport_ids_count; i++) {
        Airport* airport = get_airport(catalog, catalog->valid_airport_ids[i]);
        free(get_airport_catalog_id(airport));
        free(get_airport_flights(airport));
        free(get_airport_delays(airport));
        free(get_airport_num_passengers_per_year(airport));
        free(airport);
    }
    free(catalog->valid_airport_ids);

    g_hash_table_destroy(catalog->airport_table);
    g_free(catalog);
}

int get_valid_airport_ids_count(AirportCatalog* airportCatalog) {
    return airportCatalog->valid_airport_ids_count;
}

char* get_valid_airport_ids(AirportCatalog* airportCatalog, int index) {
    return airportCatalog->valid_airport_ids[index];
}

Airport* get_airport(AirportCatalog* catalog, char* airport_id) {
    return (Airport*)g_hash_table_lookup(catalog->airport_table, airport_id);
}