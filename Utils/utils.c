#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"


const char* list_color[] = {"white", "black", "red", "blue", "green", "yellow"};
const int size_list_color = sizeof(list_color) / sizeof(list_color [0]);

void buffer_clean() {
    int character;
    while ((character = getchar()) != '\n' && character != EOF);
}

bool read_float(float* value, char* message) {
    if (!value) return false;
    printf("%s", message);
    while (scanf("%f", value) != 1) {
        printf(RED "Entrée invalide. Veuillez entrer un nombre : " RESET);
        buffer_clean();
    }
    return true;
}

bool read_int(int* value, char* message) {
    if (!value) return false;
    printf("%s", message);
    while (scanf("%d", value) != 1) {
        printf(RED"Entrée invalide..."RESET);
        buffer_clean();
        printf("%s", message);
    }
    buffer_clean();
    return true;
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
    
    const bool is_hex = hexadecimal(character);
    const bool is_std = standard_color(character);
    return is_hex || is_std;
}

bool seize_color(char* buffer, const int buflen, char* message) {
    if (!buffer || !message || buflen == 0) return false;

    while (!read_color(buffer)) {
        printf("%s", message);
        if (fgets(buffer, buflen, stdin) == NULL) return false;

        const size_t user_value = strcspn(buffer, "\r\n");
        if (user_value < (size_t)buflen) {
            buffer[user_value] = '\0';
        }

        printf(RED"\nCouleur invalide ...\n"RESET);
        buffer_clean();
        printf(YELLOW"Veuillez entrer une couleur de la liste : ");
        for (int i = 0; i < size_list_color; i++) {
            printf("%s, ", list_color[i]);
        }
        printf("ou un code hexadécimal au format #RRGGBB.\n" RESET);
    }
    return true;
}
