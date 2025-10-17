#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Polyline* polyline_info(Point* points, int nb_points) {
    if (points == NULL || nb_points <= 0)
        return NULL;

    Polyline* pl = malloc(sizeof(Polyline));
    if (pl == NULL)
        return NULL;

    pl->points = malloc(sizeof(Point) * nb_points);
    if (pl->points == NULL) {
        free(pl);
        return NULL;
    }

    for (int i = 0; i < nb_points; i++) {
        pl->points[i] = points[i];
    }

    pl->nb_points = nb_points;

    nb_forme++;
    return pl;
}

void free_polyline(Polyline* pl) {
    if (pl == NULL)
        return;

    if (pl->points != NULL)
        free(pl->points);

    free(pl);
}
