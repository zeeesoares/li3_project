#include "date.h"

typedef struct date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Date;

//struct de datas para as reservations
typedef struct date_res {
    int year;
    int month;
    int day;
} Date_res;


int get_year(char* token) {
    int res= 0;
    int i;
    for (i = 0; i <  4; i++) {
        res *= 10;
        res += token[i] - '0';
    }
    return res;
}

int get_month(char* token) {
    int res= 0;
    int i;
    for (i = 5; i <  7; i++) {
        res *= 10;
        res += token[i] - '0';
    }
    return res;
}

int get_day(char* token) {
    int res= 0;
    int i;
    for (i = 8; i <  10; i++) {
        res *= 10;
        res += token[i] - '0';
    }
    return res;
}

int get_year_from_date(Date* date) {
    return date->year;
}

int get_month_from_date(Date* date) {
    return date->month;
}

int get_day_from_date(Date* date) {
    return date->day;
}

int get_year_from_date_res(Date_res* date) {
    return date->year;
}

int get_month_from_date_res(Date_res* date) {
    return date->month;
}

int get_day_from_date_res(Date_res* date) {
    return date->day;
}

bool is_valid_date_format(char* date_str) {
    bool res = true;
    if (strlen(date_str) != 19) res = false;
    else if (date_str[4] != '/' || date_str[7] != '/' || date_str[10] != ' ' || date_str[13] != ':' || date_str[16] != ':')
        res = false;
    return res;
}


int is_valid_date_res_format(char* date_str) {
    int res = 1;
    if (strlen(date_str) != 10) res = 0;
    else if (date_str[4] != '/' || date_str[7] != '/' )
        res = 0;

    return res;
}

bool validate_num(Date* date) {
    bool res = true;
    if (date->year < 1 ) res = false;
    else if (date->month < 1 || date->month > 12) res = false;
    else if (date->day < 1 || date->day > 31) res = false;
    else if (date->hour > 23) res = false;
    else if (date->minute > 59) res = false;
    else if (date->second > 59) res = false;
    return res;
}


bool validate_num_res(Date_res *date) {
    bool res = true;
    if (date->year < 1 ) res = false;
    else if (date->month < 1 || date->month > 12) res = false;
    else if (date->day   < 1 || date->day > 31)   res = false;
    return res;
}

bool compare_dates(Date* dateDep, Date* dateArr) {
    if (dateDep->year < dateArr->year ||
        (dateDep->year == dateArr->year && dateDep->month < dateArr->month) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day < dateArr->day) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day == dateArr->day && dateDep->hour < dateArr->hour) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day == dateArr->day && dateDep->hour == dateArr->hour && dateDep->minute < dateArr->minute) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day == dateArr->day && dateDep->hour == dateArr->hour && dateDep->minute == dateArr->minute && dateDep->second < dateArr->second)) {
        return true;
    }
    
    return false;
}


int compare_dates_res(Date_res *begin_date, Date_res *end_date) {

    if (begin_date->year != end_date->year ||
        (begin_date->year == end_date->year && begin_date->month > end_date->month) ||
        (begin_date->year == end_date->year && begin_date->month == end_date->month && begin_date->day > end_date->day)){
        return 0;
    }
    
    return 1;
}


int compare_dates_query(Date* date1, Date* date2) {
    if (date1->year != date2->year) {
        return date2->year - date1->year;
    } else if (date2->month != date1->month) {
        return date2->month - date1->month;
    } else if (date2->day != date1->day) {
        return date2->day - date1->day;
    } else if (date2->hour != date1->hour) {
        return date2->hour - date1->hour;
    } else if (date2->minute != date1->minute) {
        return date2->minute - date1->minute;
    } else if (date2->second != date1->second) {
        return date2->second - date1->second;
    } else return -1;
    return 0;
}


int compare_dates_query_res(Date_res* date1, Date_res* date2) {
    if((date1->year == date2->year && date1->month == date2->month && date1->day == date2->day))
        return 0;


    if (date1->year > date2->year ||
        (date1->year == date2->year && date1->month > date2->month) ||
        (date1->year == date2->year && date1->month == date2->month && date1->day > date2->day)){
        return 1;
    }
    if (date1->year < date2->year ||
        (date1->year == date2->year && date1->month < date2->month) ||
        (date1->year == date2->year && date1->month == date2->month && date1->day < date2->day)){
        return -1;
    }
    return 0;
}


Date* parse_date(char* date_str) {
    Date* date = (Date*)malloc(sizeof(Date));
    
    if (date == NULL) {
        fprintf(stderr, "Erro ao alocar memória para Date\n");
        return NULL;
    }

    date->year = 0;
    date->hour = 0;
    date->day = 0;
    date->month = 0;
    date->minute = 0;
    date->second = 0;

    if (is_valid_date_format(date_str)) {
        int i;
        for (i = 0; i <  4; i++) {
            date->year *= 10;
            date->year += date_str[i] - '0';
        }
        for (i = 5; i < 7; i++) {
            date->month *= 10;
            date->month += date_str[i] - '0';
        }
        for (i = 8; i < 10; i++) {
            date->day *= 10;
            date->day += date_str[i] - '0';
        }
        for (i = 11; i < 13; i++) {
            date->hour *= 10;
            date->hour += date_str[i] - '0';
        }
        for (i = 14; i < 16; i++) {
            date->minute *= 10;
            date->minute += date_str[i] - '0';
        }
        for (i = 17; i < 19; i++) {
            date->second *= 10;
            date->second += date_str[i] - '0';
        }
    }
    return date;
}

Date* parse_date_query5(char* date_begin, char* date_end) {
    Date* date = (Date*)malloc(sizeof(Date));
    
    if (date == NULL) {
        fprintf(stderr, "Erro ao alocar memória para Date\n");
        return NULL;
    }

    date->year = 0;
    date->hour = 0;
    date->day = 0;
    date->month = 0;
    date->minute = 0;
    date->second = 0;

    int i;
    for (i = 0; i <  4; i++) {
        date->year *= 10;
        date->year += date_begin[i] - '0';
    }
    for (i = 5; i < 7; i++) {
        date->month *= 10;
        date->month += date_begin[i] - '0';
    }
    for (i = 8; i < 10; i++) {
        date->day *= 10;
        date->day += date_begin[i] - '0';
    }
    for (i = 0; i < 2; i++) {
        date->hour *= 10;
        date->hour += date_end[i] - '0';
    }
    for (i = 3; i < 5; i++) {
        date->minute *= 10;
        date->minute += date_end[i] - '0';
    }
    for (i = 6; i < 8; i++) {
        date->second *= 10;
        date->second += date_end[i] - '0';
    }
    
    return date;
}

int compare_dates_query5(Date* date1, Date* date2) {
    if (date1->year != date2->year) {
        return date2->year - date1->year;
    } else if (date2->month != date1->month) {
        return date2->month - date1->month;
    } else if (date2->day != date1->day) {
        return date2->day - date1->day;
    } else if (date2->hour != date1->hour) {
        return date2->hour - date1->hour;
    } else if (date2->minute != date1->minute) {
        return date2->minute - date1->minute;
    } else {
        return date2->second - date1->second;
    }
    return 0;
}


bool compare_datesQ7(Date* dateDep, Date* dateArr) {
    if (dateDep->year < dateArr->year ||
        (dateDep->year == dateArr->year && dateDep->month < dateArr->month) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day < dateArr->day) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day == dateArr->day && dateDep->hour < dateArr->hour) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day == dateArr->day && dateDep->hour == dateArr->hour && dateDep->minute < dateArr->minute) ||
        (dateDep->year == dateArr->year && dateDep->month  == dateArr->month && dateDep->day == dateArr->day && dateDep->hour == dateArr->hour && dateDep->minute == dateArr->minute && dateDep->second < dateArr->second)) {
        return true;
    }
    
    return false;
}

int is_date_between(Date* date, Date* date_begin, Date* date_end) {
return (compare_datesQ7(date,date_end) && compare_datesQ7(date_begin, date));
}

Date_res *parse_date_res(char* date_str) {
    Date_res *date = (Date_res*)malloc(sizeof(Date_res));
    if(date==NULL){
        return NULL;
    }
    date->year = 0;
    date->month = 0;
    date->day = 0;

    if (is_valid_date_res_format(date_str)==1) {
        int i;
        for (i = 0; i <  4; i++) {
            date->year *= 10;
            date->year += date_str[i] - '0';
        }
        for (i = 5; i < 7; i++) {
            date->month *= 10;
            date->month += date_str[i] - '0';
        }
        for (i = 8; i < 10; i++) {
            date->day *= 10;
            date->day += date_str[i] - '0';
        }
    }
    return date;
}


Date* convert_date_res_to_date(const Date_res* date_res) {
    Date* date = (Date*)malloc(sizeof(Date));

    if (date != NULL) {
        date->year = date_res->year;
        date->month = date_res->month;
        date->day = date_res->day;
        date->hour = 0;
        date->minute = 0;
        date->second = 0;
    }

    return date;
}


int calculate_delay(Date* schedule, Date* real) {
    int res = (real->hour-schedule->hour)*60*60 + (real->minute-schedule->minute)*60 + (real->second-schedule->second);
    return res;
}


int calculate_day(Date_res* begin, Date_res* end) {
    int res = (end->day - begin->day);
    return res;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    const int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month >= 1 && month <= 12) {
        int days = days_per_month[month];
        
        if (month == 2 && is_leap_year(year)) {
            days++;  // leap year
        }

        return days;
    } else {
        return -1;  //mês inválido
    }
}


int calculate_all_days(Date_res* begin, Date_res* end) {
    int days_difference = 0;
    int max_days_in_month;

    Date_res begin_date = *begin;
    Date_res end_date = *end;


    while (
        begin_date.year < end_date.year ||
        (begin_date.year == end_date.year && begin_date.month < end_date.month) ||
        (begin_date.year == end_date.year && begin_date.month == end_date.month && begin_date.day < end_date.day)
    ) {
        days_difference++;

        max_days_in_month = days_in_month(begin_date.month, begin_date.year);

        if (++begin_date.day > max_days_in_month) {
            begin_date.day = 1;

            if (++begin_date.month > 12) {
                begin_date.month = 1;
                begin_date.year++;
            }
        }
    }

    if (
        begin_date.year > end_date.year ||
        (begin_date.year == end_date.year && begin_date.month > end_date.month) ||
        (begin_date.year == end_date.year && begin_date.month == end_date.month && begin_date.day > end_date.day)
    ) {
        days_difference = -1;
    }

    return days_difference;
}






void printDate(Date * date) {
    if (date->month < 10)
        printf("%d/0%d/%d %02d:%02d:%02d\n", date->year, date->month, date->day, date->hour, date->minute, date->second);
    else
        printf("%d/%d/%d %02d:%02d:%02d\n", date->year, date->month, date->day, date->hour, date->minute, date->second);
}


char* makeDate(Date* date) {
    char* formatted_date = (char*)malloc(50);
    if (formatted_date == NULL) {
        return NULL;
    }

    sprintf(formatted_date, "%04d/%02d/%02d %02d:%02d:%02d", date->year, date->month, date->day, date->hour, date->minute, date->second);

    return formatted_date;
}

char* makeDateOnlyDate(Date* date) {
    char* formatted_date = (char*)malloc(30);
    if (formatted_date == NULL) {
        return NULL;
    }

    sprintf(formatted_date, "%04d/%02d/%02d", date->year, date->month, date->day);

    return formatted_date;
}

char* makeDateRes(Date_res* date) {
    char* formatted_date = (char*)malloc(50);
    if (formatted_date == NULL) {
        return NULL;
    }

    sprintf(formatted_date, "%04d/%02d/%02d", date->year, date->month, date->day);

    return formatted_date;
}

int calculate_age(Date_res* date) {
    Date_res current_date = {2023, 10, 1};

    int age = current_date.year - date->year;

    if (current_date.month < date->month || (current_date.month == date->month && current_date.day < date->day)) {
        age--;
    }

    return age;
}



void printDateRes(Date_res * date) {
    if (date->month < 10)
        printf("%d/0%d/%d\n", date->year, date->month, date->day);
    else
        printf("%d/%d/%d\n", date->year, date->month, date->day); 
}


void freeDate(Date* date) {
    free(date);
}