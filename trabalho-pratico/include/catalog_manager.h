#ifndef CATALOG_MANAGER
#define CATALOG_MANAGER
#include "user_catalog.h"
#include "flights_catalog.h"
#include "passengers_catalog.h"
#include "reservation_catalog.h"
#include "stats.h"

typedef struct catalog_manager CatalogManager;

/*
 * Creates a new CatalogManager.
 *
 * @param u_catalog A pointer to the UserCatalog.
 * @param f_catalog A pointer to the FlightCatalog.
 * @param r_catalog A pointer to the ReservationCatalog.
 * @param p_catalog A pointer to the PassengerCatalog.
 * @returns A pointer to the newly created CatalogManager.
 */
CatalogManager* create_catalog_manager(UserCatalog* u_catalog, FlightCatalog* f_catalog,ReservationCatalog* r_catalog, HotelCatalog* h_catalog, AirportCatalog* a_catalog, MetricsTable* m_table);

/*
 * Builds and adds a User to the UserCatalog within the CatalogManager.
 *
 * @param tokens An array of CSV tokens representing user information.
 * @param catalog A pointer to the CatalogManager.
 */
void build_and_add_user_manager(char** tokens, void* catalog, FILE* file);

/*
 * Builds and adds a Flight to the FlightCatalog within the CatalogManager.
 *
 * @param tokens An array of CSV tokens representing flight information.
 * @param catalog A pointer to the CatalogManager.
 */
void build_and_add_flight_manager(char** tokens, void* catalog, FILE* file);

/*
 * Builds and adds a Passenger to the PassengerCatalog within the CatalogManager.
 *
 * @param tokens An array of CSV tokens representing passenger information.
 * @param catalog A pointer to the CatalogManager.
 */
void build_and_add_passenger_manager(char** tokens, void* catalog, FILE* file);

/*
 * Builds and adds a Reservation to the ReservationCatalog within the CatalogManager.
 *
 * @param tokens An array of CSV tokens representing reservation information.
 * @param catalog A pointer to the CatalogManager.
 */
void build_and_add_reservation_manager(char** tokens, void* catalog, FILE* file);

/*
 * Gets the UserCatalog from the CatalogManager.
 *
 * @param catalog A pointer to the CatalogManager.
 * @returns A pointer to the UserCatalog.
 */
UserCatalog* get_user_catalog(CatalogManager* catalog);

/*
 * Gets the FlightCatalog from the CatalogManager.
 *
 * @param catalog A pointer to the CatalogManager.
 * @returns A pointer to the FlightCatalog.
 */
FlightCatalog* get_flight_catalog(CatalogManager* catalog);

/*
 * Gets the HotelCatalog from the CatalogManager.
 *
 * @param catalog A pointer to the CatalogManager.
 * @returns A pointer to the HotelCatalog.
 */
HotelCatalog* get_hotel_catalog(CatalogManager* catalog);

/*
 * Gets the ReservationCatalog from the CatalogManager.
 *
 * @param catalog A pointer to the CatalogManager.
 * @returns A pointer to the ReservationCatalog.
 */
ReservationCatalog* get_reservation_catalog(CatalogManager* catalog);

/**
 * @brief Gets the AirportCatalog from the CatalogManager.
 *
 * @param catalog A pointer to the CatalogManager.
 * @return A pointer to the AirportCatalog.
 */
AirportCatalog* get_airport_catalog(CatalogManager* catalog);

/**
 * @brief Gets the MetricsTable from the CatalogManager.
 *
 * @param catalog A pointer to the CatalogManager.
 * @return A pointer to the MetricsTable.
 */
MetricsTable* get_metrics_table(CatalogManager* catalog);

#endif