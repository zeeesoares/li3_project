#include "stats.h"
#include "utils.h"
#include <glib.h>
#include <string.h>
#include <stdbool.h>


typedef struct metrics {
    int num_new_users;
    int num_flights;
    int num_passengers;
    GHashTable* unique_passengers;
    int num_unique_passengers;
    int num_reservations;
} Metrics;

typedef struct yearNode{
    int year;
    Metrics year_metrics; 
    GHashTable* month_data; 
    int* valid_month_ids;
    int valid_month_ids_count;
} YearNode;

typedef struct monthNode{
    int month;
    Metrics month_metrics;
    GHashTable* day_data; 
    int* valid_days_ids;
    int valid_days_ids_count;
} MonthNode;

typedef struct dayNode {
    int day;
    Metrics day_metrics; 
} DayNode;

typedef struct MetricsTable{
    GHashTable* hash_table; 
    int* valid_year_ids;
    int valid_year_ids_count;
} MetricsTable;

MetricsTable* create_metrics_table() {
    MetricsTable* table = (MetricsTable*)malloc(sizeof(MetricsTable));

    table->hash_table = g_hash_table_new(g_direct_hash, g_direct_equal);
    table->valid_year_ids = NULL;
    table->valid_year_ids_count = 0;
    return table;
}

YearNode* create_year_node(int year) {
    YearNode* node = (YearNode*)malloc(sizeof(YearNode));

    node->year = year;
    memset(&node->year_metrics, 0, sizeof(Metrics));
    node->month_data = g_hash_table_new(g_direct_hash, g_direct_equal);
    node->year_metrics.unique_passengers = g_hash_table_new(g_direct_hash, g_direct_equal);
    node->valid_month_ids = NULL;
    node->valid_month_ids_count = 0;

    return node;
}

MonthNode* create_month_node(int month) {
    MonthNode* node = (MonthNode*)malloc(sizeof(MonthNode));

    node->month = month;
    memset(&node->month_metrics, 0, sizeof(Metrics));
    node->day_data = g_hash_table_new(g_direct_hash, g_direct_equal);
    node->month_metrics.unique_passengers = g_hash_table_new(g_direct_hash, g_direct_equal);
    node->valid_days_ids = NULL;
    node->valid_days_ids_count = 0;

    return node;
}

DayNode* create_day_node(int day) {
    DayNode* node = (DayNode*)malloc(sizeof(DayNode));
    node->day = day;
    memset(&node->day_metrics, 0, sizeof(Metrics));
    node->day_metrics.unique_passengers = g_hash_table_new(g_direct_hash, g_direct_equal);

    return node;
}

void update_metrics(Metrics* metrics, int new_users, int flights, int passengers, int unique_passengers, int reservations) {
    metrics->num_new_users += new_users;
    metrics->num_flights += flights;
    metrics->num_passengers += passengers;
    metrics->num_reservations += reservations;

    if (unique_passengers != -1) {   
         if (g_hash_table_lookup(metrics->unique_passengers,GINT_TO_POINTER(unique_passengers)) == NULL) {
            g_hash_table_insert(metrics->unique_passengers, GINT_TO_POINTER(unique_passengers), GINT_TO_POINTER(-1));
            metrics->num_unique_passengers++;
        } 
    }
}

void update_metrics_table(MetricsTable* table, int year, int month, int day, int new_users, int flights, int passengers, int unique_passengers, int reservations) {
    
    YearNode* yearNode = g_hash_table_lookup(table->hash_table, GINT_TO_POINTER(year));

    if (yearNode == NULL) {
        yearNode = create_year_node(year);
        g_hash_table_insert(table->hash_table, GINT_TO_POINTER(year), yearNode);
        table->valid_year_ids_count++;
        table->valid_year_ids = realloc(table->valid_year_ids, table->valid_year_ids_count * sizeof(int));
        table->valid_year_ids[table->valid_year_ids_count - 1] = year;
    }

    MonthNode* monthNode = g_hash_table_lookup(yearNode->month_data, GINT_TO_POINTER(month));

    if (monthNode == NULL) {
        monthNode = create_month_node(month);
        g_hash_table_insert(yearNode->month_data, GINT_TO_POINTER(month), monthNode);
        yearNode->valid_month_ids_count++;
        yearNode->valid_month_ids = realloc(yearNode->valid_month_ids, yearNode->valid_month_ids_count * sizeof(int));
        yearNode->valid_month_ids[yearNode->valid_month_ids_count - 1] = month;
    }

    DayNode* dayNode = g_hash_table_lookup(monthNode->day_data, GINT_TO_POINTER(day));

    if (dayNode == NULL) {
        dayNode = create_day_node(day);
        g_hash_table_insert(monthNode->day_data, GINT_TO_POINTER(day), dayNode);
        monthNode->valid_days_ids_count++;
        monthNode->valid_days_ids = realloc(monthNode->valid_days_ids, monthNode->valid_days_ids_count * sizeof(int));
        monthNode->valid_days_ids[monthNode->valid_days_ids_count - 1] = day;
    }

    update_metrics(&yearNode->year_metrics, new_users, flights, passengers, unique_passengers, reservations);
    update_metrics(&monthNode->month_metrics, new_users, flights, passengers, unique_passengers, reservations);
    update_metrics(&dayNode->day_metrics, new_users, flights, passengers, unique_passengers, reservations);
}


int* get_valid_years_ids(MetricsTable* table) {
    return table->valid_year_ids;
}

int get_valid_years_ids_count(MetricsTable* table) {
    return table->valid_year_ids_count;
}

int* get_valid_months_ids(YearNode* yearNode) {
    return yearNode->valid_month_ids;
}

int get_valid_months_ids_count(YearNode* yearNode) {
    return yearNode->valid_month_ids_count;
}

int* get_valid_days_ids(MonthNode* monthNode) {
    return monthNode->valid_days_ids;
}

int get_valid_days_ids_count(MonthNode* monthNode) {
    return monthNode->valid_days_ids_count;
}

YearNode* get_year_node(MetricsTable* table, int year) {
    return g_hash_table_lookup(table->hash_table, GINT_TO_POINTER(year));
}

MonthNode* get_month_node(YearNode* year, int month) {
    return g_hash_table_lookup(year->month_data, GINT_TO_POINTER(month));
}

DayNode* get_day_node(MonthNode* month, int day) {
    return g_hash_table_lookup(month->day_data, GINT_TO_POINTER(day));
}

Metrics* get_year_metrics(MetricsTable* table, int year) {
    YearNode* yearNode = get_year_node(table, year);
    return (yearNode != NULL) ? &yearNode->year_metrics : NULL;
}

Metrics* get_month_metrics(MetricsTable* table, int year, int month) {
    YearNode* yearNode = get_year_node(table, year);
    if (yearNode != NULL) {
        MonthNode* monthNode = get_month_node(yearNode, month);
        return (monthNode != NULL) ? &monthNode->month_metrics : NULL;
    }
    return NULL;
}

Metrics* get_day_metrics(MetricsTable* table, int year, int month, int day) {
    YearNode* yearNode = get_year_node(table, year);
    if (yearNode != NULL) {
        MonthNode* monthNode = get_month_node(yearNode, month);
        if (monthNode != NULL) {
            DayNode* dayNode = get_day_node(monthNode, day);
            return (dayNode != NULL) ? &dayNode->day_metrics : NULL;
        }
    }
    return NULL;
}

int get_num_new_users(Metrics* metrics) {
    return (metrics != NULL) ? metrics->num_new_users : 0;
}

int get_num_flights(Metrics* metrics) {
    return (metrics != NULL) ? metrics->num_flights : 0;
}

int get_num_passengers(Metrics* metrics) {
    return (metrics != NULL) ? metrics->num_passengers : 0;
}

int get_num_unique_passengers(Metrics* metrics) {
    return (metrics != NULL) ? metrics->num_unique_passengers : 0;
}

int get_num_reservations(Metrics* metrics) {
    return (metrics != NULL) ? metrics->num_reservations : 0;
}


void destroy_metrics_table(MetricsTable* table) {
    int* years = get_valid_years_ids(table);
    int num_years = get_valid_years_ids_count(table);

    for (int i = 0; i < num_years; i++) {
        YearNode* yearNode = g_hash_table_lookup(table->hash_table, GINT_TO_POINTER(years[i]));

        if (yearNode != NULL) {
            int* months = get_valid_months_ids(yearNode);
            int num_months = get_valid_months_ids_count(yearNode);

            for (int j = 0; j < num_months; j++) {
                MonthNode* monthNode = g_hash_table_lookup(yearNode->month_data, GINT_TO_POINTER(months[j]));

                if (monthNode != NULL) {
                    int* days = get_valid_days_ids(monthNode);
                    int num_days = get_valid_days_ids_count(monthNode);

                    for (int z = 0; z < num_days; z++) {
                        DayNode* dayNode = g_hash_table_lookup(monthNode->day_data, GINT_TO_POINTER(days[z]));
                        if (dayNode != NULL) {
                            g_hash_table_destroy(dayNode->day_metrics.unique_passengers);
                            free(dayNode);
                        }
                        g_hash_table_remove(monthNode->day_data, GINT_TO_POINTER(days[z]));
                    }

                    free(days);
                    g_hash_table_destroy(monthNode->day_data);
                    g_hash_table_destroy(monthNode->month_metrics.unique_passengers);
                }

                g_hash_table_remove(yearNode->month_data, GINT_TO_POINTER(months[j]));
                free(monthNode);
            }

            free(months);
        }

        g_hash_table_destroy(yearNode->year_metrics.unique_passengers);
        g_hash_table_destroy(yearNode->month_data);
        g_hash_table_remove(table->hash_table, GINT_TO_POINTER(years[i]));
        free(yearNode);
    }

    free(years);
    g_hash_table_destroy(table->hash_table);
    free(table);
}
