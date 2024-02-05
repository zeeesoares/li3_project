#include "hotel_catalog.h"


struct HotelCatalog {
    GHashTable* hotel_table;
};


HotelCatalog* create_hotel_catalog() {
    HotelCatalog* catalog = g_new(HotelCatalog, 1);
    catalog->hotel_table = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)freeHotel);
    return catalog;
}


void add_hotel(HotelCatalog* catalog, Hotel* hotel) {
    int hotel_id = get_hotel_catalog_id(hotel);


    Hotel* new = get_hotel(catalog, hotel_id);
    if (new) {
        int num_rates = get_hotel_num_rates(new);
        int sum_rating = get_hotel_ratings(new);
        int new_rating = get_hotel_ratings(hotel);
        set_hotel_num_rates(new,num_rates+1);
        set_hotel_ratings(new,sum_rating+new_rating);
        get_hotel_reservations(hotel);
        free(hotel);
        
    }
    else {
        g_hash_table_insert(catalog->hotel_table, GINT_TO_POINTER(hotel_id), hotel);
    }
}

void destroy_hotel_catalog(HotelCatalog* catalog) {
    g_hash_table_destroy(catalog->hotel_table);
    g_free(catalog);
}

Hotel* get_hotel(HotelCatalog* catalog, int hotel_id) {
    return (Hotel*)g_hash_table_lookup(catalog->hotel_table, GINT_TO_POINTER(hotel_id));
}