#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"


const char* list_color[] = {"white", "black", "red", "blue", "green", "yellow"};

const int size_list_color = sizeof(list_color) / sizeof(list_color [0]);

float read_float() {
    float value;
    while (scanf("%f", &value) != 1) {
        printf(RED "Entrée invalide. Veuillez entrer un nombre : " RESET);
        buffer_clean();
    }
    return value;
}

int read_int() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf(RED"Entrée invalide. Veuillez entrer un nombre entier : "RESET);
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
    if (character == NULL) return false;

    for (int i = 0; i < size_list_color; i++) {
        if (strcmp(character, list_color[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool read_color(const char* character) {
    if (character == NULL) return false;
    
    bool is_hex = hexadecimal(character);    
    bool is_std = standard_color(character);
    return is_hex || is_std;
}

bool seize_color(char* buffer, int buflen, char* message) {
    if (!buffer || !message || buflen == 0) return false;

    while (1) {
        printf("%s", message);
        if (fgets(buffer, buflen, stdin) == NULL) return false;
        buffer[strcspn(buffer, "\r\n")] = '\0';

        if (read_color(buffer)) return true;
        printf(RED"\nCouleur invalide ...\n"RESET);
        buffer_clean();
        printf(YELLOW"Veuillez entrer une couleur de la liste : ");
        for (int i = 0; i < size_list_color; i++) {
            printf("%s, ", list_color[i]);
        }
        printf("ou un code hexadécimal au format #RRGGBB.\n" RESET);
    }
}
