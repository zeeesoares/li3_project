#include "utils.h"
#include <ctype.h>
#include "queries.h"


int string_to_int(char* string) {
    int res = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        res *= 10;
        res += string[i] - '0';
    }
    return res;
}

int is_num(char* string) {
    int res = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if(string[i]=='.' || string[i]=='-')return -1;
        int acc = string[i] - '0';
        if (acc >= 0 && acc <= 9) res = 1;
    }
    return res;
}

void convert_to_uppercase(char* str) {
    if (str == NULL) {
        return; 
    }

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

int compare_ids(char *id) {
    char *flight_id_pattern = "000";
    char *reservation_id_pattern = "Book";

    if (strstr(id, reservation_id_pattern) != NULL) {
        return 2;
    } else if (strstr(id, flight_id_pattern) != NULL) {
        return 1;
    } else {
        return 0;
    }
}

void get_date_components(int date, int* year, int* month, int* day) {
    *year = date / 10000;
    *month = (date / 100) % 100;
    *day = date % 100;
}

// Função para realizar a fusão de duas subarrays ordenadas
void merge(char** arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Criação de subarrays temporárias
    char** left_arr = malloc(n1 * sizeof(char*));
    char** right_arr = malloc(n2 * sizeof(char*));

    // Copia os dados para as subarrays temporárias
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[middle + 1 + j];

    // Combina as subarrays temporárias de volta na array original
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (strcmp(left_arr[i], right_arr[j]) <= 0) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes, se houver, das subarrays esquerda e direita
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    // Libera a memória alocada para as subarrays temporárias
    free(left_arr);
    free(right_arr);
}

// Função principal do algoritmo Merge Sort
void mergeSort(char** arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Ordena as duas metades
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combina as duas metades ordenadas
        merge(arr, left, middle, right);
    }
}

// Função para iniciar o Merge Sort na lista de IDs de usuários válidos
void sortValidUserIds(char** valid_user_ids, int valid_user_ids_count) {
    mergeSort(valid_user_ids, 0, valid_user_ids_count - 1);
}

int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}