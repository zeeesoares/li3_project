#include "parser.h"
#include "date.h"
#include "output.h"

void parse_csv_file(FILE* filename, void * catalog, void(*f)(char**, void*, FILE*), int(*g) (char**), FILE* errors_file, int max_tokens) {


    char* line = NULL;
    size_t len = 0;
    size_t read;
    read = getline(&line, &len, filename);
    line[read - 1] = '\0';
    char** tokens = parse_csv_line(line, max_tokens);
    write_output_file(tokens, errors_file, max_tokens);
    free_tokens(tokens, max_tokens);


    while ((read = getline(&line, &len, filename)) != (size_t)-1) {
        line[read - 1] = '\0';
        
        tokens = parse_csv_line(line, max_tokens);
        if (!g(tokens)) {
            write_output_file(tokens, errors_file, max_tokens);
        }
            
        else {
            f(tokens, catalog, errors_file);
        }
        
        free_tokens(tokens, max_tokens);
    }
    free(line);
}   

char** parse_csv_line(char* line, int num_tokens) {
    char **tokens = malloc(sizeof(char *) * num_tokens);
    if (tokens == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_tokens; i++) {
        tokens[i] = NULL;
    }

    char* token = strsep(&line, ";");
    int token_counter = 0;
    while (token_counter < num_tokens) {
        if (token != NULL) {
            if (strlen(token) == 0) {
                tokens[token_counter] = NULL;
            } else {
                tokens[token_counter] = strdup(token);  
            }
        } else {
            tokens[token_counter] = NULL;
        }
        token_counter++;
        token = strsep(&line, ";");
    }

    return tokens;
}

void free_tokens(char** tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
}