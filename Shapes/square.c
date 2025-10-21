#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Square* square_info (const Point origin, const int side) {
    Square* sq = malloc(sizeof(Square));
    if (sq == NULL) return NULL;

    sq->origin = origin;
    sq->side = side;

    sq->style = style_info("black", "white", 1.0f);
    if (sq->style == NULL) {
        free(sq);
        return NULL;
    }

    sq->modif.angle = 0.0;
    sq->modif.dx = 0;
    sq->modif.dy = 0;
    sq->modif.symetry_x = false;
    sq->modif.symetry_y = false;

    nb_forme++;
    printf(GREEN"Carré créé avec succès !\n"RESET);
    printf("appuyez sur entrer pour continuer...\n");
    scanf("%*c", getchar());
    return sq;
}

void free_square (Square* sq) {
    if (sq == NULL) return;

    if (sq->style != NULL) {
        free_style(sq->style);
    }

    free(sq);
}