#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "user.h"
#include "date.h"
#include "flight.h"


typedef struct User {
    char *id;
    char *name;
    Date_res* birth_date;
    char *sex;
    char *passport;
    char *country_code;
    Date* account_creation;
    int account_status;
    
    double total_spent;
    int number_of_flights;  
    int number_of_reservations;  

    int* flights;
    int* reservations;
} User;



char** parseUser(char* line) {
    char** tokens = malloc(12 * sizeof(char*)); 
    if (tokens == NULL) {
        return NULL;
    }

    char *token;
    char *rest = line;

    int field = 0;
    while ((token = strsep(&rest, ",")) != NULL) {
        tokens[field] = strdup(token);
        field++;
    }

    return tokens;
}

void freeTokens(char** tokens) {
    for (int i = 0; i < 12; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

User* createUserFromTokens(char** tokens) {
    User* user = (User*)malloc(sizeof(User));
    if (user == NULL) {
        return NULL;
    }

    user->id = strdup(tokens[0]);
    user->name = strdup(tokens[1]);
    user->birth_date = parse_date_res(tokens[4]);
    user->sex = strdup(tokens[5]);
    user->passport = strdup(tokens[6]);
    user->country_code = strdup(tokens[7]);
    user->account_creation = parse_date(tokens[9]);
    set_user_account_status(user,tokens[11]);


    user->total_spent = 0.0;
    user->number_of_flights = 0;  
    user->number_of_reservations = 0;  

    user->flights = NULL;
    user->reservations = NULL;

    return user;
}


void freeUser(User* user) {
    if (user == NULL) {
        return;
    }

    free(user->id);
    free(user->name);
    free(user->birth_date);
    free(user->sex);
    free(user->passport);
    free(user->country_code);
    free(user->account_creation);
    free(user->flights);
    free(user->reservations);

    free(user);
}


char *get_user_id(User *user){
	return strdup(user->id);
}

void set_user_user_id(User* user, char* token) {
    user->id = strdup(token);
}

char *get_user_name(User *user){
	return strdup(user->name);
}

void set_user_name(User* user, char* token) {
    user->name = strdup(token);
}


Date_res* get_user_birth_date(User *user){
	return user->birth_date;
}

void set_user_birth_date(User* user, char* token) {
    user->birth_date = parse_date_res(token);
}

char *get_user_sex(User *user){
	return strdup(user->sex);
}

void set_user_sex(User* user, char* token) {
    user->sex = strdup(token);
}

char *get_user_passport(User *user){
	return strdup(user->passport);
}

void set_user_passport(User* user, char* token) {
    user->passport = strdup(token);
}

char *get_user_country_code(User *user){
	return strdup(user->country_code);
}

void set_user_country_code(User* user, char* token) {
    user->country_code = strdup(token);
}

Date* get_user_account_creation(User *user){
	return user->account_creation;
}

void set_user_account_creation(User* user, char* token) {
    user->account_creation = parse_date(token);
}

int get_user_account_status(User *user){
	return user->account_status;
}

void set_user_account_status(User* user, char* token) {
    if (token == NULL || strstr(token,"n") != NULL || strstr(token,"N") != NULL)
        user->account_status = 0;
    else user->account_status = 1;
}

double get_user_total_spent(User* user) {
    return user->total_spent;
}

void set_user_total_spent(User* user, double value) {
    user->total_spent = value;
}

int get_user_number_of_flights(User* user) {
    return user->number_of_flights;
}

void set_user_number_of_flights(User* user, int value) {
    user->number_of_flights = value;
}

int get_user_number_of_reservations(User* user) {
    return user->number_of_reservations;
}

void set_user_number_of_reservations(User* user, int value) {
    user->number_of_reservations = value;
}

int* get_user_flights(User* user) {
    return user->flights;
}

int* get_user_reservations(User* user) {
    return user->reservations;
}

int get_user_age(User* user) {
    Date_res* date = get_user_birth_date(user);

    int month= get_month_from_date_res(date);
    int day = get_day_from_date_res(date);
    int age = 2023 - get_year_from_date_res(date);

    if (10 < month || (10 == month && 1 < day)) {
        age--;
    }

    return age;
}

void add_flight_to_user(User* user, int flight_id) {
    if (user == NULL) {
        return; 
    }

    user->flights = realloc(user->flights, (user->number_of_flights + 1) * sizeof(int));
    if (user->flights == NULL) {
        return;
    }

    user->flights[user->number_of_flights] = flight_id;
}

void add_reservation_to_user(User* user, int reservation_id) {
    if (user == NULL) {
        return; 
    }

    user->reservations = realloc(user->reservations, (user->number_of_reservations + 1) * sizeof(int));
    if (user->reservations == NULL) {
        return;
    }

    user->reservations[user->number_of_reservations] = reservation_id;
}