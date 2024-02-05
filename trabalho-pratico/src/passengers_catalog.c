#include "passengers_catalog.h"
#include "catalog_manager.h"
#include "flights_catalog.h"
#include "user_catalog.h"
#include "output.h"
#include <glib.h>

void build_and_add_passenger(char** tokens, FlightCatalog* f_catalog, UserCatalog* u_catalog,  AirportCatalog* a_catalog, MetricsTable* m_table, FILE* file){
    int flight_id = atoi(tokens[0]);
    int code = get_user_code(u_catalog,tokens[1]);
    if (is_flight_id_in_catalog(f_catalog,flight_id) && is_user_id_in_f_catalog(u_catalog,tokens[1])) {
            Flight* flight = get_flight(f_catalog,flight_id);
            Date* date = get_flight_schedule_departure_date(flight);
            set_flight_totalseats(flight, get_flight_totalseats(flight)+1);

            int day = get_day_from_date(date);
            int month = get_month_from_date(date);
            int year = get_year_from_date(date);

            add_passenger_to_airport(get_flight_destination(flight),a_catalog,year);
            add_passenger_to_airport(get_flight_origin(flight),a_catalog,year);
            
            update_metrics_table(m_table,year,month,day,0,0,1,code,0);

            User* user = get_user_from_code(u_catalog, code);
            add_flight_to_user(user,flight_id);
            set_user_number_of_flights(user, get_user_number_of_flights(user)+1);

    }
    else {
        write_output_file(tokens, file, 2); 
    }
}


int is_flight_id_in_catalog(FlightCatalog* flight_catalog, int flight_id) {
    if(get_flight(flight_catalog,flight_id)){
        return 1;
    }
    else {
        return 0;
    } 
}

int is_user_id_in_f_catalog(UserCatalog* user_catalog, const char* user_id) {
    if(get_user(user_catalog,user_id)){
        return 1;
    }
    else {
        return 0;
    } 
}

int validate_passenger(char** tokens) {
    for (int i = 0; i < 2; i++) {
        if (tokens[i] == NULL) return 0;
    }
    return 1; 
}