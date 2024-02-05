#include "reservation.h"
#include "date.h"
#include "utils.h"

typedef struct reservation{    
    int id;
    char *user_id;
    int hotel_id;
    char *hotel_name;
    int   hotel_stars;
    int   tax;
    Date_res *begin_date;
    Date_res *end_date;
    int   price_per_night;
    int breakfast;
    int   rating;

}Reservation;



Reservation* create_reservation(){
    
    Reservation* reservation = (Reservation*)malloc(sizeof(Reservation));

    if(reservation==NULL){
        return NULL;
    }
    return reservation;
}

Reservation* build_reservation(char** token){
    Reservation* reservation = create_reservation();
    set_id(reservation,token[0]);
    set_user_id(reservation,token[1]);
    set_hotel_id(reservation,token[2]);
    set_hotel_name(reservation,token[3]);
    set_hotel_stars(reservation,token[4]);
    set_tax(reservation,token[5]);
    set_begin_date(reservation,token[7]);
    set_end_date(reservation,token[8]);
    set_price_per_night(reservation,token[9]);
    set_breakfast(reservation,token[10]);
    set_rating(reservation,token[12]);
    return reservation;
}


//sets
void set_id(Reservation *reservation,char *token){
    reservation->id=atoi(token+4);
}

void set_user_id(Reservation *reservation,char *token){
    reservation->user_id=strdup(token);

}

void set_hotel_id(Reservation *reservation,char *token){
    reservation->hotel_id=atoi(token+3);

}
void set_hotel_name(Reservation *reservation,char *token){
    reservation->hotel_name=strdup(token);

}
void set_hotel_stars(Reservation *reservation,char *token){
    reservation->hotel_stars=string_to_int(token);
    

}
void set_tax(Reservation *reservation,char *token){
    reservation->tax=string_to_int(token);
    

}

void set_begin_date(Reservation *reservation,char *token){
    reservation->begin_date=parse_date_res(token);

}
void set_end_date(Reservation *reservation,char *token){
    reservation->end_date=parse_date_res(token);

}
void set_price_per_night(Reservation *reservation,char *token){
    reservation->price_per_night=string_to_int(token);
    

}
void set_breakfast(Reservation *reservation,char *token){
    if(token==NULL){
        reservation->breakfast=0;
    }else{
        if (strcasecmp(token, "f") == 0 || strcasecmp(token, "false") == 0 || strcmp(token, "0") == 0) {
        reservation->breakfast=0;
        }else{
            reservation->breakfast=1;
        }

    }

}

void set_rating(Reservation *reservation,char *token){
    reservation->rating=string_to_int(token);
    
}




void free_reservation(Reservation* reservation){
    if(reservation !=NULL){

    free(reservation->user_id);
    free(reservation->hotel_name);
    free(reservation->begin_date);
    free(reservation->end_date);
    
    if (reservation != NULL) {
        free(reservation);
    }

    }
}


int get_id(Reservation* reservation){
    return reservation->id;
}

char* get_reservation_user_id(Reservation* reservation){
    return strdup(reservation->user_id);
}

char* get_hotel_name(Reservation* reservation){
    return strdup(reservation->hotel_name);
}

int get_hotel_id(Reservation* reservation){
    return reservation->hotel_id;
}

int get_hotel_stars(Reservation* reservation){
    return reservation->hotel_stars;
}

int get_tax(Reservation* reservation){
    return reservation->tax;
}

Date_res* get_begin_date(Reservation* reservation){
    return reservation->begin_date;
}

Date_res* get_end_date(Reservation* reservation){
    return reservation->end_date;
}

int get_price_per_night(Reservation* reservation){
    return reservation->price_per_night;
}

int get_breakfast(Reservation* reservation){
    return reservation->breakfast   ;
}

int get_rating(Reservation* reservation){
    return reservation->rating;
}