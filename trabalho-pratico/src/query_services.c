#include "query_services.h"

typedef struct query1_results {
    union {
        User* user;
        Flight* flight;
        Reservation* reservation;
    } data;
    int type;
    int flag;
} Q1_results;


Q1_results* get_query1_user_results(command* cmd, UserCatalog* catalog) {
    User* user = get_user(catalog,get_cmd_args(cmd,0)); 

    if (user) {          
        int user_status = get_user_account_status(user);
        if (user_status) {    
            Q1_results* result = malloc(sizeof(struct query1_results));
            result->data.user = user;
            result->type = 0;
            result->flag = get_cmd_flag(cmd);
            return (void *)result;
        }
    }
    else {
        return NULL;
    }
    return NULL;
}

Q1_results* get_query1_flight_results(command* cmd, FlightCatalog* catalog) {
    Flight* flight = get_flight(catalog, atoi(get_cmd_args(cmd,0) + 3));

    if (flight) {                 
        Q1_results* result = malloc(sizeof(struct query1_results));
        result->data.flight = flight;
        result->type = 1;
        result->flag = get_cmd_flag(cmd);
        return (void *)result;
    }
    else {
        return NULL;
    }
}

Q1_results* get_query1_reservation_results(command* cmd, ReservationCatalog* catalog) {
    Reservation* reservation = get_reservation_id(catalog, atoi(get_cmd_args(cmd,0)+4));

    if (reservation) {
        Q1_results* result = malloc(sizeof(struct query1_results));
        result->data.reservation = reservation;
        result->type = 2;
        result->flag = get_cmd_flag(cmd);
        return (void *)result;
    }
    else {
        return NULL;
    }
}

int get_q1_type(Q1_results* res) {
    return res->type;
}

int get_q1_flag(Q1_results* res) {
    return res->flag;
}

User* get_q1_user(Q1_results* res) {
    return res->data.user;
}

Flight* get_q1_flight(Q1_results* res) {
    return res->data.flight;
}

Reservation* get_q1_reservation(Q1_results* res) {
    return res->data.reservation;
}




//QUERY2
typedef struct query2_results {
    Info2* infos;
    int count;
    int flag;
    int data_type;
} Q2_results;


typedef struct info2 {
    int id;
    Date* date;
    int type;
} Info2;


Q2_results* get_query2_flighs_and_reservations(command* cmd, User* user, CatalogManager* catalog) {
    int num_flights;
    int num_reservations;
    int* flights; 
    int* reservations;
    Q2_results* result = malloc(sizeof(struct query2_results));;
    Info2* infos = NULL;
    int count = 0;

    num_flights = get_user_number_of_flights(user);
    flights = get_user_flights(user);
    for(int i = 0; i < num_flights; i++) {
        Flight* flight = get_flight(get_flight_catalog(catalog), flights[i]);
        Date* date = get_flight_schedule_departure_date(flight);
        infos = realloc(infos, (count + 1) * sizeof(Info2));
        infos[count].id = flights[i];
        infos[count].date = date;
        infos[count].type = 1;
        count++;
    }
    num_reservations = get_user_number_of_reservations(user);
    reservations = get_user_reservations(user);
    for(int i = 0; i < num_reservations; i++) {
        Reservation* reservation = get_reservation_id(get_reservation_catalog(catalog), reservations[i]);
        Date* date = convert_date_res_to_date(get_begin_date(reservation));
        
        infos = realloc(infos, (count + 1) * sizeof(Info2));
        infos[count].id = reservations[i];
        infos[count].date = date;
        infos[count].type = 2;
        count++;
    }
    result->data_type = 1;

    if (count > 1) {
        qsort(infos, count, sizeof(Info2), compareDates);
    }

    result->infos = infos;
    result->count = count;
    result->flag = get_cmd_flag(cmd);

    if (count > 1) {
            qsort(infos, count, sizeof(Info2), compareDates);
        }

    result->infos = infos;
    result->count = count;
    result->flag = get_cmd_flag(cmd);

    return result;
}

Q2_results* get_query2_flighs(command* cmd, User* user, CatalogManager* catalog) {
    int num_flights;
    int* flights; 
    Q2_results* result = malloc(sizeof(struct query2_results));;
    Info2* infos = NULL;
    int count = 0;

    num_flights = get_user_number_of_flights(user);
    flights = get_user_flights(user);
    for(int i = 0; i < num_flights; i++) {
        Flight* flight = get_flight(get_flight_catalog(catalog), flights[i]);
        Date* date = get_flight_schedule_departure_date(flight);
        infos = realloc(infos, (count + 1) * sizeof(Info2));
        infos[count].id = flights[i];
        infos[count].date = date;
        infos[count].type = 1;
        count++;
    }
    result->data_type = 0;

    if (count > 1) {
        qsort(infos, count, sizeof(Info2), compareDates);
    }

    result->infos = infos;
    result->count = count;
    result->flag = get_cmd_flag(cmd);

    if (count > 1) {
            qsort(infos, count, sizeof(Info2), compareDates);
        }

    result->infos = infos;
    result->count = count;
    result->flag = get_cmd_flag(cmd);

    return result;
}

Q2_results* get_query2_reservations(command* cmd, User* user, CatalogManager* catalog) {
    int num_reservations;
    int* reservations;
    Q2_results* result = malloc(sizeof(struct query2_results));;
    Info2* infos = NULL;
    int count = 0;

    num_reservations = get_user_number_of_reservations(user);
    reservations = get_user_reservations(user);
    for(int i = 0; i < num_reservations; i++) {
        Reservation* reservation = get_reservation_id(get_reservation_catalog(catalog), reservations[i]);
        Date* date = convert_date_res_to_date(get_begin_date(reservation));
        
        infos = realloc(infos, (count + 1) * sizeof(Info2));
        infos[count].id = reservations[i];
        infos[count].date = date;
        infos[count].type = 2;
        count++;
    }
    result->data_type = 0;

    if (count > 1) {
        qsort(infos, count, sizeof(Info2), compareDates);
    }

    result->infos = infos;
    result->count = count;
    result->flag = get_cmd_flag(cmd);

    if (count > 1) {
            qsort(infos, count, sizeof(Info2), compareDates);
        }

    result->infos = infos;
    result->count = count;
    result->flag = get_cmd_flag(cmd);

    return result;
}

int compareDates(const void* a, const void* b) {
    Date* date1 = ((const Info2*)a)->date;
    Date* date2 = ((const Info2*)b)->date;

    int id1 = ((const Info2*)a)->id;
    int id2 = ((const Info2*)b)->id;
    int type1 = ((const Info2*)a)->type;
    int type2 = ((const Info2*)b)->type;
    int res = compare_dates_query(date1, date2);

    if (res == 0) {
        if (type1 == type2)
            return id1-id2;
        else {
            return type1-type2;
        } 
    }
    return res;
}


int get_q2_count(Q2_results* infos) {
    return infos->count;
}

int get_q2_id(Q2_results* info, int index) {
    return info->infos[index].id;
}

int get_q2_type(Q2_results* info, int index) {
    return info->infos[index].type;
}

Date* get_q2_date(Q2_results* info, int index) {
    return info->infos[index].date;
}

int get_q2_flag(Q2_results* info) {
    return info->flag;
}

int get_q2_datatype(Q2_results* info) {
    return info->data_type;
}

void freeInfos2(Q2_results* info) {
    free(info->infos);
}


//QUERY3

typedef struct query3_results {
    double rating;
    int flag;
} Q3_results;


Q3_results* get_query3_rating(command* cmd, Hotel* hotel) {
    double media;
    if (hotel) {
        int flag = get_cmd_flag(cmd);
        double sum = get_hotel_ratings(hotel);
        double num_rates = get_hotel_num_rates(hotel);
        media = sum/num_rates;

        Q3_results* result = malloc(sizeof(struct query3_results));
        result->rating = media;
        result->flag = flag;
        return (void *)result;
    }

    return NULL;

}

double get_q3_median(Q3_results* info) {
    return info->rating;
}

int get_q3_flag(Q3_results* info) {
    return info->flag;
}


//QUERY4

typedef struct query4_results {
    Info4* infos;
    int count;
    int flag;
} Q4_results;


typedef struct info4 {
    int reservation_id;
    Date_res* begin_date;
    Date_res* end_date;
    char* user_id;
    int rating;
    double total_price;
} Info4;


Q4_results* get_query4_result(command* cmd, Hotel* hotel, ReservationCatalog* reservation_catalog) {
    if (hotel) {
        Info4* info = malloc(sizeof(struct info4));
        int count = 0;

        int* res =  get_hotel_reservations(hotel);
        int num_res = get_hotel_num_reservations(hotel);
        for (int i = 0; i < num_res; i++) {
            ReservationCatalog* r_catalog = reservation_catalog;
            Reservation* reservation = get_reservation_id(r_catalog,res[i]);
            
            Date_res* begin_date_res = get_begin_date(reservation);
            Date_res* end_date_res = get_end_date(reservation);
            char* user_id_res = get_reservation_user_id(reservation);
            int rating_res = get_rating(reservation);
            double total_price_res= total_spent(reservation);

            count++;
            info = realloc(info, (count +1) * sizeof(Info4));
            info[i].reservation_id = res[i];
            info[i].begin_date = begin_date_res;
            info[i].end_date = end_date_res;
            info[i].user_id = user_id_res;
            info[i].rating = rating_res;
            info[i].total_price = total_price_res;
        }   
        qsort(info, count, sizeof(Info4), compareDatesRes);

        Q4_results* result = malloc(sizeof(struct query4_results));
        result->count = count;
        result->infos = info;
        result->flag = get_cmd_flag(cmd);
        return result;
    }
    else return NULL;
}


int compareDatesRes(const void* a, const void* b) {
    const Info4* infoA = (const Info4*)a;
    const Info4* infoB = (const Info4*)b;

    int date = compare_dates_query_res(infoB->begin_date, infoA->begin_date);

    if (date == 0) {
        return infoA->reservation_id - infoB->reservation_id;
    }

    return date;
}

void free_q4infos(Q4_results* info){
    for(int i=0;i<info->count;i++){
        free(info->infos[i].user_id);
    }
    free(info->infos);
}

int get_q4_count(Q4_results* infos) {
    return infos->count;
}

char* get_q4_user_id(Q4_results* info, int index) {
    return strdup(info->infos[index].user_id);
}

int get_q4_reservation_id(Q4_results* info, int index) {
    return info->infos[index].reservation_id;
}

double get_q4_total_price(Q4_results* info, int index) {
    return info->infos[index].total_price;
}

char* get_q4_begin_date(Q4_results* info, int index) {
    return makeDateRes(info->infos[index].begin_date);
}

char* get_q4_end_date(Q4_results* info, int index) {
    return makeDateRes(info->infos[index].end_date);
}

int get_q4_rating(Q4_results* info, int index) {
    return info->infos[index].rating;
}

int get_q4_flag(Q4_results* info) {
    return info->flag;
}


//QUERY5

typedef struct query5_results {
    Info5* infos;
    int count;
    int flag;
} Q5_results;


typedef struct info5 {
    int flight_id;
    Date* dep_date;
    char* dest;
    char* airline;
    char* planemodel;
} Info5;


Q5_results* get_query5_results(command* cmd, Airport* airport, FlightCatalog* flight_catalog) {

    if (airport) {
        Info5* info = NULL;
        int count = 0;

        Date* date_begin = parse_date_query5(get_cmd_args(cmd,1), get_cmd_args(cmd,2));
        Date* date_end = parse_date_query5(get_cmd_args(cmd,3), get_cmd_args(cmd,4));

        int* flights = get_airport_flights(airport);
        int num_flights = get_airport_num_flights(airport);

        FlightCatalog* f_catalog = flight_catalog;

        for (int i = 0; i < num_flights; i++) {
            Flight* flight = get_flight(f_catalog, flights[i]);
            Date* date = get_flight_schedule_departure_date(flight);

            if (is_date_between(date, date_begin, date_end)) {
                
                char* dest = get_flight_destination(flight);
                char* airline = get_flight_airline(flight);
                char* plane_model = get_flight_planemodel(flight);
                convert_to_uppercase(dest);
                count++;
                
                info = realloc(info, count * sizeof(Info5));
                info[count - 1].dep_date = date;
                info[count - 1].dest = dest;
                info[count-1].airline = airline;
                info[count - 1].flight_id = flights[i];
                info[count - 1].planemodel = plane_model;
            }
        }

        if (count > 1) {
            qsort(info, count, sizeof(Info5), compareDates);
        }

        free(date_begin);
        free(date_end);

        Q5_results* results = malloc(sizeof(Q5_results));
        results->flag = get_cmd_flag(cmd);
        results->count = count;
        results->infos = info;

        return results;
    }
    return NULL;
}

void free_q5_info(Q5_results* info) {
    for (int i = 0; i < info->count; i++) {
        free(info->infos[i].airline);
        free(info->infos[i].planemodel);
        free(info->infos[i].dest);
    }
    free(info->infos);
}

int get_q5_count(Q5_results* info) {
    return info->count;
}

int get_q5_flag(Q5_results* info) {
    return info->flag;
}

int get_q5_flight_id(Q5_results* info, int index) {
    return info->infos[index].flight_id;
}

char* get_q5_dep_date(Q5_results* info, int index) {
    return makeDate(info->infos[index].dep_date);
}

char* get_q5_airline(Q5_results* info, int index) {
    return strdup(info->infos[index].airline);
}

char* get_q5_destination(Q5_results* info, int index) {
    return strdup(info->infos[index].dest);
}

char* get_q5_planemodel(Q5_results* info, int index) {
    return strdup(info->infos[index].planemodel);
}

//QUERY 6
typedef struct query6_results {
    Info6* infos;
    int count;
    int flag;
} Q6_results;


typedef struct info6 {
    char* id;
    int num_passengers;
} Info6;

Q6_results* get_query6_results(command* cmd, AirportCatalog* catalog) {
    int year = atoi(get_cmd_args(cmd,0));
    int top = atoi(get_cmd_args(cmd,1));
    int num_airports = get_valid_airport_ids_count(catalog);

    Info6* info = malloc(sizeof(Info6));

    for (int i = 0; i < num_airports; i++) {
        info = realloc(info,(i+1)* sizeof(Info6));
        Airport* airport = get_airport(catalog,get_valid_airport_ids(catalog,i));
        
        char* id = get_airport_catalog_id(airport);
        int num_passengers = get_passengers_by_year(airport,year);
        
        info[i].id = id;
        info[i].num_passengers = num_passengers;
    }

    qsort(info, num_airports, sizeof(Info6), compare_num_passengers);

    Q6_results* results = malloc(sizeof(Q6_results));
    results->count = (top < num_airports) ? top : num_airports;
    results->flag = get_cmd_flag(cmd);
    results->infos = info;

    return (void*)results;
}

int compare_num_passengers(const void* a, const void* b) {
    const Info6* infoA = (const Info6*)a;
    const Info6* infoB = (const Info6*)b;

    int diff_passengers = infoB->num_passengers - infoA->num_passengers;

    if (diff_passengers == 0) {
        return strcmp(infoA->id, infoB->id);
    }

    return diff_passengers;
}

void free_q6_info(Q6_results* info) {
    free(info->infos);
}

int get_q6_count(Q6_results* info) {
    return info->count;
}

int get_q6_flag(Q6_results* info) {
    return info->flag;
}

char* get_q6_id(Q6_results* info, int index) {
    return strdup(info->infos[index].id);
}

int get_q6_num_passengers(Q6_results* info, int index) {
    return info->infos[index].num_passengers;
}

//QUERY7

typedef struct query7_results {
    Info7* infos;
    int num_infos;
    int flag;
} Q7_results;

typedef struct info7 {
    char* airline_id;
    int median;
} Info7;

Q7_results* get_query7_results(command* cmd, AirportCatalog* catalog) {
    int top_n = atoi(get_cmd_args(cmd,0));

    int count = get_valid_airport_ids_count(catalog);

    Info7* info = malloc(sizeof(Info7));
    int num_infos = 0;

    for (int i = 0; i < count; i++) {
        Airport* airport = get_airport(catalog,get_valid_airport_ids(catalog,i));
        int num_flights = get_airport_num_flights(airport);
        
        if (num_flights) {
            info = realloc(info,sizeof(Info7)*(num_infos+1));
            info[num_infos].airline_id = get_airport_catalog_id(airport); //strdup
            info[num_infos].median= calculate_median(get_airport_delays(airport),get_airport_num_flights(airport));
            num_infos++;
        }
    }

    qsort(info, num_infos, sizeof(Info7), compare_airline_info);

    Q7_results* results = malloc(sizeof(Q7_results));
    results->infos = info;
    results->num_infos = top_n;
    results->flag = get_cmd_flag(cmd);

    if (top_n > num_infos)
        results->num_infos = num_infos;

    return results; 

}


int compare_airline_info(const void* a, const void* b) {
    int median_diff = ((Info7*)b)->median - ((Info7*)a)->median;

    if (median_diff != 0) {
        return median_diff;
    } else {
        return strcmp(((Info7*)a)->airline_id, ((Info7*)b)->airline_id);
    }
}

int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int calculate_median(int* delays, int num_delays) {
    qsort(delays, num_delays, sizeof(int), compare_int);  // Alteração aqui para usar compare_int

    if (num_delays % 2 == 0) {
        int middle1 = delays[num_delays / 2 - 1];
        int middle2 = delays[num_delays / 2];
        return (middle1 + middle2) / 2;
    } else {
        return delays[num_delays / 2];
    }
}

int get_q7_num_infos(Q7_results* info) {
    return info->num_infos;
}

int get_q7_flag(Q7_results* info) {
    return info->flag;
}

char* get_q7_name(Q7_results* info, int index) {
    return strdup(info->infos[index].airline_id);
}

int get_q7_median(Q7_results* info, int index) {
    return info->infos[index].median;
}

void free_q7infos(Q7_results* info){
    free(info->infos);
}


//QUERY8
typedef struct query8_results {
    int revenue;
    int flag;
} Q8_results;

Q8_results* get_query8_results(command* cmd, Hotel* hotel, ReservationCatalog* catalog) {
    char* date1 = get_cmd_args(cmd,1);
    char* date2 = get_cmd_args(cmd,2);

    Date_res* begin = parse_date_res(date1);
    Date_res* end = parse_date_res(date2);

    int revenues=0;

    Q8_results* result = malloc(sizeof(struct query8_results));

    Date_res* begin_date;
    Date_res* end_date;
    if (hotel) {
        int count = 0;
        int ppn=0;
        int* res =  get_hotel_reservations(hotel);
        int num_res = get_hotel_num_reservations(hotel);
        
        
        for (int i = 0; i < num_res; i++) {
            int dia=0;
            
            Reservation* reservation = get_reservation_id(catalog,res[i]);
            begin_date=get_begin_date(reservation);
            end_date=get_end_date(reservation);
            ppn=get_price_per_night(reservation);
            
            if(compare_dates_query_res(begin,begin_date)==1){
                begin_date=begin;
            }
            if(compare_dates_query_res(end_date,end)==1){
                end_date=end;
                dia++;
            }
            
            dia += calculate_all_days(begin_date,end_date);

            count=(dia >= 0) ? dia : 0;
            revenues+=(count*ppn);
        }

        result->revenue=revenues;
        result->flag=get_cmd_flag(cmd);

        free(begin);
        free(end);

        return (void*)result;
    }
    return NULL;

}

int get_q8_flag(Q8_results* info) {
    return info->flag;
}

int get_q8_result(Q8_results* info) {
    return info->revenue;
}


//QUERY9

typedef struct query9_results {
    Info9* infos;
    int num_infos;
    int flag;
} Q9_results;

typedef struct info9 {
    char* user_name_info;
    char* user_id_info;
} Info9;


Q9_results* get_query9_results(command* cmd, UserCatalog* catalog, const char* prefixo) {
    Info9* info = malloc(sizeof(Info9));
    int j = 0;

    int size_pre = strlen(prefixo);

    char first_letter = prefixo[0];
    int hash_key;

    if (first_letter >= 'A' && first_letter <= 'Z') {
        hash_key = first_letter - 'A';
    } else {
        hash_key = 26;  // Caso não seja uma letra, utiliza a posição 26
    }

    GList* current = get_user_list_for_letter(catalog, hash_key);

    while (current != NULL) {
        User* user = get_user_from_code(catalog,GPOINTER_TO_INT(current->data));
        char* user_id = get_user_id(user);
        char* user_name = get_user_name(user);
        int user_status = get_user_account_status(user);

        if (user_status && strncmp(prefixo, user_name, size_pre) == 0) {
            info = realloc(info,sizeof(Info9)* (j+1));
            info[j].user_id_info = user_id;
            info[j].user_name_info = user_name;
            j++;
        } else {
            free(user_name);
            free(user_id);
        }
        current = g_list_next(current);
    }


    qsort(info, j, sizeof(Info9), compare_info_q9);

    Q9_results* results = malloc(sizeof(Q9_results));
    results->flag = get_cmd_flag(cmd);
    results->num_infos = j;
    results->infos = realloc(info, sizeof(Info9) * j);  // Redimensiona para o tamanho exato necessário

    return results;
}


int compare_info_q9(const void* a, const void* b) {
    const char* nameA = ((Info9*)a)->user_name_info;
    const char* nameB = ((Info9*)b)->user_name_info;
    char* idA = ((Info9*)a)->user_id_info;
    char* idB = ((Info9*)b)->user_id_info;

    // Substituir espaços por hífens nas strings antes de comparar
    char* modifiedNameA = strdup(nameA);
    char* modifiedNameB = strdup(nameB);

    for (int i = 0; modifiedNameA[i]; i++) {
        if (modifiedNameA[i] == ' ') {
            modifiedNameA[i] = '-';
        }
    }

    for (int i = 0; modifiedNameB[i]; i++) {
        if (modifiedNameB[i] == ' ') {
            modifiedNameB[i] = '-';
        }
    }

    int result = strcoll(modifiedNameA, modifiedNameB);

    if (result == 0) {
        // Se os nomes forem iguais, compare os IDs
        result = strcoll(idA, idB);
    }

    free(modifiedNameA);
    free(modifiedNameB);
    return result;
}

void free_q9_info(Q9_results* info) {
    for (int i = 0; i < info->num_infos; i++) {
        free(info->infos[i].user_name_info);
        free(info->infos[i].user_id_info);
    }
    free(info->infos);
}

int get_q9_num_infos(Q9_results* info) {
    return info->num_infos;
}

int get_q9_flag(Q9_results* info) {
    return info->flag;
}

char* get_q9_user_name_info(Q9_results* info, int index) {
    return strdup(info->infos[index].user_name_info);
}

char* get_q9_user_id_info(Q9_results* info, int index) {
    return strdup(info->infos[index].user_id_info);
}

//QUERY10

typedef struct query10_results {
    Info10* infos;
    int num_infos;
    int flag;
    int type;
} Q10_results;

typedef struct info10 {
    int id;
    int num_users;
    int num_flights;
    int num_passengers;
    int num_single_passengers;
    int num_reservations;
} Info10;


Q10_results* get_query10_results_year(command* cmd, MetricsTable* table) {
    Q10_results* results;
    Info10* info = malloc(sizeof(Info10));

    Metrics* metrics;

    int* years = get_valid_years_ids(table);
    int num_years = get_valid_years_ids_count(table);
    qsort(years, num_years, sizeof(int), compare_integer);
    for (int i = 0; i< num_years; i++) {
        metrics = get_year_metrics(table,years[i]);
        info = realloc(info,sizeof(Info10)*(i+1));

        info[i].id = years[i];
        info[i].num_users = get_num_new_users(metrics);
        info[i].num_flights = get_num_flights(metrics);
        info[i].num_passengers = get_num_passengers(metrics);
        info[i].num_single_passengers = get_num_unique_passengers(metrics);
        info[i].num_reservations = get_num_reservations(metrics);
    }
    results = malloc(sizeof(Q10_results));
    results->infos = info;
    results->num_infos = num_years;
    results->flag = get_cmd_flag(cmd);
    results->type = get_cmd_num_args(cmd);
    return results;
}

Q10_results* get_query10_results_month(command* cmd, MetricsTable* table) {
    Q10_results* results;
    Info10* info = malloc(sizeof(Info10));

    Metrics* metrics;


    int year_search = atoi(get_cmd_args(cmd,0));
    YearNode* year = get_year_node(table,year_search);
    if (year == NULL)
        return NULL;
    int* months = get_valid_months_ids(year);
    int num_months = get_valid_months_ids_count(year);
    qsort(months, num_months, sizeof(int), compare_integer);
    for (int i = 0; i< num_months; i++) {
        metrics = get_month_metrics(table,year_search,months[i]);
        info = realloc(info,sizeof(Info10)*(i+1));
        info[i].id = months[i];
        info[i].num_users = get_num_new_users(metrics);
        info[i].num_flights = get_num_flights(metrics);
        info[i].num_passengers = get_num_passengers(metrics);
        info[i].num_single_passengers = get_num_unique_passengers(metrics);
        info[i].num_reservations = get_num_reservations(metrics);
    }
    
    results = malloc(sizeof(Q10_results));
    results->infos = info;
    results->num_infos = num_months;
    results->flag = get_cmd_flag(cmd);
    results->type = get_cmd_num_args(cmd);
    return results;

}


Q10_results* get_query10_results_day(command* cmd, MetricsTable* table) {
    Q10_results* results;
    Info10* info = malloc(sizeof(Info10));

    Metrics* metrics;

    int year_search = atoi(get_cmd_args(cmd,0));
    int month_search = atoi(get_cmd_args(cmd,1));
    YearNode* year = get_year_node(table,year_search);
    if (year == NULL)
        return NULL;
    MonthNode* month = get_month_node(year,month_search);
    if (month == NULL)
        return NULL;
    int* days = get_valid_days_ids(month);
    int num_days = get_valid_days_ids_count(month);
    qsort(days, num_days, sizeof(int), compare_integer);
    for (int i = 0; i< num_days; i++) {
        metrics = get_day_metrics(table,year_search,month_search,days[i]);
        info = realloc(info,sizeof(Info10)*(i+1));
        info[i].id = days[i];
        info[i].num_users = get_num_new_users(metrics);
        info[i].num_flights = get_num_flights(metrics);
        info[i].num_passengers = get_num_passengers(metrics);
        info[i].num_single_passengers = get_num_unique_passengers(metrics);
        info[i].num_reservations = get_num_reservations(metrics);
    }
    
    results = malloc(sizeof(Q10_results));
    results->infos = info;
    results->num_infos = num_days;
    results->flag = get_cmd_flag(cmd);
    results->type = get_cmd_num_args(cmd);
    return results;

}

int compare_integer(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int get_query10_num_infos(Q10_results* result) {
    return result->num_infos;
}

int get_query10_flag(Q10_results* result) {
    return result->flag;
}

int get_query10_type(Q10_results* result) {
    return result->type;
}

int get_q10_num_users(Q10_results* info, int index) {
    return info->infos[index].num_users;
}

int get_q10_num_flights(Q10_results* info, int index) {
    return info->infos[index].num_flights;
}

int get_q10_num_passengers(Q10_results* info, int index) {
    return info->infos[index].num_passengers;
}

int get_q10_num_single_passengers(Q10_results* info, int index) {
    return info->infos[index].num_single_passengers;
}

int get_q10_num_reservations(Q10_results* info, int index) {
    return info->infos[index].num_reservations;
}

int get_q10_id(Q10_results* info, int index) {
    return info->infos[index].id;
}

void free_q10infos(Q10_results* info) {
    free(info->infos);
}