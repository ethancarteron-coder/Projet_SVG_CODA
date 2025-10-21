#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"


const char* list_color[] = {"white", "black", "red", "blue", "green", "yellow"};

const int size_list_color = sizeof(list_color) / sizeof(list_color [0]);

int read_int() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Entrée invalide. Veuillez entrer un nombre entier : ");
        buffer_clean();
    }
    return value;
}

void buffer_clean() {
    int character;
    while ((character = getchar()) != '\n' && character != EOF);
}

bool hexadecimal(const char* character) {
    
    if (character == NULL || strlen(character) != 7 || character[0] != '#')
        return false;
    for (int i = 1; i < 7; i++) {
        if (!isxdigit((unsigned char)character[i]))
            return false;
    }
    return true;
}

bool standard_color (const char* character) {
    printf("ça passe \n");
    if (character == NULL) return false;
    
    printf("Juste après ça passe plus \n");
    for (int i = 0; i < size_list_color; i++) {
        printf("tableau %d ", i);
        if (strcmp(character, list_color[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool read_color(const char* character) {
    printf("Debug: read_color called with '%s'\n", character ? character : "NULL");
    if (character == NULL) return false;
    
    bool is_hex = hexadecimal(character);
    printf("Debug: hexadecimal check: %s\n", is_hex ? "true" : "false");
    
    bool is_std = standard_color(character);
    printf("Debug: standard_color check: %s\n", is_std ? "true" : "false");
    
    return is_hex || is_std;
}

bool seize_color(char* buffer, int buflen, char* message) {
    if (!buffer || !message || buflen == 0) return false;
    printf("il appel la fonction\n");
    while (1) {
        printf("loop \n");
        printf("%s", message);
        if (!fgets(buffer, buflen, stdin)) return false;
        buffer[strcspn(buffer, "\r\n")] = '\0';

        if (read_color(buffer)) return true;

        printf("\nCouleur invalide ...\n");
    }
}
