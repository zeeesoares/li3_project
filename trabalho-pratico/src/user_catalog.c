#include "user_catalog.h"
#include "user.h"
#include "catalog_manager.h"
#include "utils.h"
#include <ctype.h>
#include <stdlib.h>


struct UserCatalog {
    GHashTable* user_table;
    GHashTable* user_id_to_user_code;
    GHashTable* user_name_to_code;
    int valid_user_ids_count;
};

UserCatalog* create_user_catalog() {
    UserCatalog* catalog = g_new(UserCatalog, 1);
    catalog->user_table = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)freeUser);
    catalog->user_id_to_user_code = g_hash_table_new_full(g_str_hash, g_str_equal, free, NULL);
    catalog->user_name_to_code = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, NULL);
    catalog->valid_user_ids_count = 1;
    return catalog;
}

void build_and_add_user(char** tokens, UserCatalog* catalog, MetricsTable* m_table) {
    User* user = createUserFromTokens(tokens);

    if (user != NULL) {
        add_user(catalog, user);

        Date* date = get_user_account_creation(user);
        int day = get_day_from_date(date);
        int month = get_month_from_date(date);
        int year = get_year_from_date(date);

        update_metrics_table(m_table,year,month,day,1,0,0,-1,0);
    }
}

void destroy_user_catalog(UserCatalog* catalog) {
    g_hash_table_destroy(catalog->user_table);
    g_hash_table_destroy(catalog->user_id_to_user_code);
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->user_name_to_code);
    while (g_hash_table_iter_next(&iter, &key, &value)) {
        GList* user_positions = (GList*)value;
        g_list_free(user_positions);
    }

    g_hash_table_destroy(catalog->user_name_to_code);
    g_free(catalog);
}

void add_user(UserCatalog* catalog, User* user) {
    char* user_name = get_user_name(user);
    char* user_id = get_user_id(user);

    g_hash_table_insert(catalog->user_id_to_user_code, (gpointer)user_id, GINT_TO_POINTER(catalog->valid_user_ids_count));
    g_hash_table_insert(catalog->user_table, GINT_TO_POINTER(catalog->valid_user_ids_count), user);

    char first_letter = user_name[0];
    int hash_key;

    if (first_letter >= 'A' && first_letter <= 'Z') {
        hash_key = first_letter - 'A';
    } else {
        hash_key = 26;  // Caso não seja uma letra, utiliza a posição 2
    }

    // Adiciona a posição do usuário ao hash de nome
    GList* user_positions = g_hash_table_lookup(catalog->user_name_to_code, GINT_TO_POINTER(hash_key));
    if (user_positions == NULL) {
        user_positions = g_list_append(NULL, GINT_TO_POINTER(catalog->valid_user_ids_count));
    } else {
        user_positions = g_list_prepend(user_positions, GINT_TO_POINTER(catalog->valid_user_ids_count));
    }

    g_hash_table_insert(catalog->user_name_to_code, GINT_TO_POINTER(hash_key), user_positions);

    free(user_name);
    catalog->valid_user_ids_count++;
}

User* get_user(UserCatalog* catalog, const char* user_id) {
    gpointer user_code = g_hash_table_lookup(catalog->user_id_to_user_code, user_id);
    if (user_code != NULL) {
        return (User*)g_hash_table_lookup(catalog->user_table, user_code);
    }
    return NULL;
}

int get_user_code(UserCatalog* catalog, const char* user_id) {
    gpointer user_code_ptr = g_hash_table_lookup(catalog->user_id_to_user_code, user_id);
    
    if (user_code_ptr != NULL) {
        return GPOINTER_TO_INT(user_code_ptr);
    } else {
        return -1; 
    }
}

User* get_user_from_code(UserCatalog* catalog, int user_code) {
    return g_hash_table_lookup(catalog->user_table, GINT_TO_POINTER(user_code));
    
}


GList* get_user_list_for_letter(UserCatalog* catalog, int letter) {
    // Converta a letra para minúscula se necessário

    // Calcule o índice no array
    int hash_key = letter;

    // Obtenha a lista correspondente
    GList* user_list = g_hash_table_lookup(catalog->user_name_to_code, GINT_TO_POINTER(hash_key));

    return user_list;
}

int get_valid_user_ids_count(UserCatalog* catalog) {
    return catalog->valid_user_ids_count;
}


int isValidDate(char **token) {
    if (strlen(token[4]) != 10)
        return 0;

    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (token[4][i] != '/')
                return 0;
        } else {
            if (!isdigit(token[4][i]))
                return 0;
        }
    }

    int month = (token[4][5] - '0') * 10 + (token[4][6] - '0');
    int day = (token[4][8] - '0') * 10 + (token[4][9] - '0');

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return 0;

    return 1;
}

int isValidDateTime(char **token) {
    if (strlen(token[9]) != 19)
        return 0;

    for (int i = 0; i < 19; i++) {
        if (i == 4 || i == 7 || i == 10 || i == 13 || i == 16) {
            if (token[9][i] != '/' && token[9][i] != ' ' && token[9][i] != ':')
                return 0;
        } else {
            if (!isdigit(token[9][i]))
                return 0;
        }
    }

    int month = (token[9][5] - '0') * 10 + (token[9][6] - '0');
    int day = (token[9][8] - '0') * 10 + (token[9][9] - '0');
    int hour = (token[9][11] - '0') * 10 + (token[9][12] - '0');
    int minute = (token[9][14] - '0') * 10 + (token[9][15] - '0');
    int second = (token[9][17] - '0') * 10 + (token[9][18] - '0');

    if (month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        return 0;

    return 1;
}


int isValidEmail(char **token) {
    if (strlen(token[2]) < 5) {
        return 0;
    }

    int atCount = 0;
    int dotCount = 0;
    int length = strlen(token[2]);

    for (int i = 0; i < length; i++) {
        if (token[2][i] == '@') {
            atCount++;
        } else if (token[2][i] == '.') {
            dotCount++;
        }
    }

    if (atCount == 1 && dotCount >= 1) {
        return 1;
    }

    return 0; 
}

int isValidCountryCode(char **token) {
    return (strlen(token[7]) == 2);
}

int isValidAccountStatus(char **token) {
    if (strcasecmp(token[11], "active") == 0 || strcasecmp(token[11], "inactive") == 0) {
        return 1;
    }
    return 0;
}

int validate_user(char** token) {

	for(int i = 0; i < 12; i++){
	   if (token[i] == NULL) return 0;
	}
	if (!isValidDate(token)) 
	   return 0;
    if (!isValidDateTime(token)) 
        return 0;
    if (!isValidEmail(token)) 
        return 0;
    if (!isValidCountryCode(token)) 
        return 0;
    if (!isValidAccountStatus(token)) 
      return 0;
    return 1;
}