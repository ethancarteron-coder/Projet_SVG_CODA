#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Square* square_info (const Point origin, const int side) {
    Square* sq = malloc (sizeof(Square));
    if (sq == 0)
        return NULL;

    sq->origin = origin;
    sq->side = side;

    nb_forme++;
    return sq;
}

void free_square (Square* sq) {
    if (sq == 0)
        return;

    free (sq);
}