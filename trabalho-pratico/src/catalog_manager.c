#include "catalog_manager.h"
#include "flights_catalog.h"
#include "passengers_catalog.h"
#include "user_catalog.h"
#include "reservation_catalog.h"
#include "stats.h"


typedef struct catalog_manager
{
    UserCatalog* user_catalog;
    FlightCatalog* flight_catalog;
    ReservationCatalog* reservation_catalog;
    HotelCatalog* hotel_catalog;
    AirportCatalog* airport_catalog;
    MetricsTable* metrics_table;
    
} CatalogManager;


CatalogManager* create_catalog_manager(UserCatalog* u_catalog, FlightCatalog* f_catalog,ReservationCatalog* r_catalog, HotelCatalog* h_catalog, AirportCatalog* a_catalog, MetricsTable* m_table) {
    CatalogManager* new = (CatalogManager*)malloc(sizeof(CatalogManager));

    if (new == NULL) {
        return NULL;
    }
    new->user_catalog = u_catalog;
    new->flight_catalog = f_catalog;
    new->reservation_catalog=r_catalog;
    new->hotel_catalog = h_catalog;
    new->airport_catalog = a_catalog;
    new->metrics_table = m_table;
    return new;
}

void build_and_add_flight_manager(char** tokens, void* catalog, FILE* file) {
    CatalogManager* catalog_manager = (CatalogManager*) catalog;
    build_and_add_flight(tokens, get_flight_catalog(catalog_manager),get_airport_catalog(catalog_manager),get_metrics_table(catalog_manager));
}

void build_and_add_passenger_manager(char** tokens, void* catalog, FILE* file) {
    CatalogManager* catalog_manager = (CatalogManager*) catalog;
    build_and_add_passenger(tokens, get_flight_catalog(catalog_manager), get_user_catalog(catalog_manager), get_airport_catalog(catalog_manager),get_metrics_table(catalog_manager),file);
}

void build_and_add_user_manager(char** tokens, void* catalog, FILE* file) {
    CatalogManager* catalog_manager = (CatalogManager*) catalog;
    build_and_add_user(tokens, get_user_catalog(catalog_manager), get_metrics_table(catalog_manager));
}

void build_and_add_reservation_manager(char** tokens, void* catalog, FILE* file) {
    CatalogManager* catalog_manager = (CatalogManager*) catalog;
    build_and_add_reservation(tokens, get_reservation_catalog(catalog_manager), get_user_catalog(catalog_manager), get_hotel_catalog(catalog_manager),get_metrics_table(catalog_manager),file);
}

UserCatalog* get_user_catalog(CatalogManager* catalog) {
    return catalog->user_catalog;
}

FlightCatalog* get_flight_catalog(CatalogManager* catalog) {
    return catalog->flight_catalog;
}

ReservationCatalog* get_reservation_catalog(CatalogManager* catalog) {
    return catalog->reservation_catalog;
}

HotelCatalog* get_hotel_catalog(CatalogManager* catalog) {
    return catalog->hotel_catalog;
}

AirportCatalog* get_airport_catalog(CatalogManager* catalog) {
    return catalog->airport_catalog;
}

MetricsTable* get_metrics_table(CatalogManager* catalog) {
    return catalog->metrics_table;
}