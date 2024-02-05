#include "reservation_catalog.h"
#include "catalog_manager.h"
#include "user_catalog.h"
#include "utils.h"
#include "output.h"
#include <glib.h>

struct ReservationCatalog
{
    GHashTable* reservation_table;
};


ReservationCatalog* create_reservation_catalog(){
    ReservationCatalog* catalog =g_new(ReservationCatalog,1);
    catalog->reservation_table = g_hash_table_new_full(g_direct_hash, g_direct_equal,NULL,(GDestroyNotify)free_reservation);
    return catalog;
}

void build_and_add_reservation(char** token, ReservationCatalog* catalog, UserCatalog* user_catalog, HotelCatalog* hotel_catalog, MetricsTable* m_table, FILE* file){
    

    if(is_user_id_in_catalog_reservation(user_catalog,token[1]))
    {
            Reservation* reservation=build_reservation(token);
            int reservation_id = get_id(reservation);

            add_reservation(catalog,reservation);
            
            User * aux = get_user(user_catalog,token[1]);
            add_reservation_to_user(aux,reservation_id);
            set_user_number_of_reservations(aux, get_user_number_of_reservations(aux)+1);
            double total = total_spent(reservation);
            set_user_total_spent(aux,get_user_total_spent(aux)+total);


            Hotel* hotel = build_hotel(get_hotel_id(reservation),atoi(token[12]));
            add_hotel(hotel_catalog,hotel);
            Hotel* new = get_hotel(hotel_catalog,get_hotel_id(reservation));
            add_reservation_to_hotel(new,reservation_id);
            
            Date_res* date = get_begin_date(reservation);
            int day = get_day_from_date_res(date);
            int month = get_month_from_date_res(date);
            int year = get_year_from_date_res(date);
        
            update_metrics_table(m_table,year,month,day,0,0,0,-1,1);
    }
    else{
        write_output_file(token,file, 14);
    }
}

int is_user_id_in_catalog_reservation(UserCatalog* user_catalog, const char* user_id){
   if(get_user(user_catalog,user_id)){
        return 1;
   }
   else {
     return 0;
   } 
}

void destroy_reservation_catalog(ReservationCatalog* catalog){
        g_hash_table_destroy(catalog->reservation_table);
        free(catalog);
}

void add_reservation(ReservationCatalog* catalog, Reservation* reservation) {
    int reservation_id = get_id(reservation);
    g_hash_table_insert(catalog->reservation_table,  GINT_TO_POINTER(reservation_id), reservation);
}

Reservation* get_reservation_id(ReservationCatalog* catalog,int id){
    return (Reservation*)g_hash_table_lookup(catalog->reservation_table, GINT_TO_POINTER(id));
}

int validate_rating_stars(char* rating){
    if (rating[1] == '.' || rating[0] == '-') return 0;

    return 1;
}

int validate_tax(char* tax){
    if(is_num(tax)==-1) return 0;
    
    return 1;
}

int validate_price_per_night(char* price){
    
    for (int i = 0; price[i] != '\0'; i++) {
            if(price[i]=='.' || price[i]=='-')return 0;
            
        }
    return 1;
}

int validate_breakfast(char* breakfast) {

    if (breakfast == NULL || breakfast[0] == '\0') {
        return 1;
    }

    if (strcasecmp(breakfast, "f") == 0 || strcasecmp(breakfast, "false") == 0 || strcmp(breakfast, "0") == 0 ||
        strcasecmp(breakfast, "t") == 0 || strcasecmp(breakfast, "true") == 0 || strcmp(breakfast, "1") == 0) {
        return 1;
    }

    return 0;
}

int validate_dates(Date_res *begin_date,Date_res *end_date){
    int flag=1;
    
    if(compare_dates_res(begin_date,end_date)==0) flag=0;
    
    if (begin_date != NULL)
        free(begin_date);
    if (end_date != NULL)
        free(end_date);

    return flag;
}

int validate_reservations(char** token){
    int flag=1;

    for(int i=0;i<reservation_camps-1;i++){
        if(token[i]==NULL && i!=10){
            return 0;
        } 
    }
    
    if (validate_rating_stars(token[12]) == 0) return 0; 

    if (validate_rating_stars(token[4]) == 0) return 0;

    if (validate_tax(token[5]) == 0) return 0;

    if (validate_price_per_night(token[9]) == 0) return 0;

    if (validate_breakfast(token[10]) == 0) return 0;
       
    if (validate_dates(parse_date_res(token[7]),parse_date_res(token[8])) == 0) return 0; 
    
    return flag; 
}


double total_spent(Reservation* reservation) {

    double price_per_night = (double)get_price_per_night(reservation);
    double num_of_nights = (double)calculate_day(get_begin_date(reservation), get_end_date(reservation));
    double total_night_spent = (price_per_night*num_of_nights);
    double total_spent = total_night_spent + (total_night_spent/100) * (double)get_tax(reservation);
    return total_spent;
}