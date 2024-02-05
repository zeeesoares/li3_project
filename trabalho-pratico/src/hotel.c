#include "hotel.h"

typedef struct hotel {
    int id;
    int sum_rating;
    int num_rates;
    int* reservations;
    int num_reservations;
} Hotel;

Hotel* create_hotel() {
    Hotel* new = (Hotel*)malloc(sizeof(Hotel));
    if (new == NULL) {
        return NULL;
    }
    new->reservations = NULL;
    new->sum_rating = 0;
    new->num_rates = 0;
    new->sum_rating = 0;
    new->id=0;
    return new;
}

Hotel* build_hotel(int id, int rating) {
    Hotel* hotel = create_hotel();
    hotel->id = id;
    hotel->num_rates = 1;
    hotel->num_reservations = 0;
    hotel->sum_rating = rating;
    return hotel;
}


void add_reservation_to_hotel(Hotel* hotel, int reservation_id) {
    if (hotel == NULL) {
        return; 
    }

    hotel->reservations = realloc(hotel->reservations, (hotel->num_reservations + 1) * sizeof(int));
    if (hotel->reservations == NULL) {
        return;
    }

    hotel->reservations[hotel->num_reservations++] = reservation_id;
}

int get_hotel_catalog_id(Hotel* hotel) {
    return hotel->id;
}

int get_hotel_ratings(Hotel* hotel) {
    return hotel->sum_rating;
}

int get_hotel_num_reservations(Hotel* hotel) {
    return hotel->num_reservations;
}

int* get_hotel_reservations(Hotel* hotel) {
    return hotel->reservations;
}

int get_hotel_num_rates(Hotel* hotel) {
    return hotel->num_rates;
}

void set_hotel_catalog_id(Hotel* hotel, int new_id) {
    hotel->id = new_id;
}

void set_hotel_ratings(Hotel* hotel, int new_sum_rating) {
    hotel->sum_rating = new_sum_rating;
}

void set_hotel_num_rates(Hotel* hotel, int new_num_rates) {
    hotel->num_rates = new_num_rates;
}

void freeHotel(Hotel* hotel) {
    free(hotel->reservations);
    free(hotel);
}


