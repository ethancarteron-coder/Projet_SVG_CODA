#include <stdio.h>
#include "utils.h"

int read_int(int Maxvalue) {
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