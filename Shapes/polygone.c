#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Polygone* polygone_info(const Point* point, const int nb_points) {
    if (point == NULL || nb_points <= 3)
        return NULL;

    Polygone* pg = (Polygone*) malloc(sizeof(Polygone));
    if (pg == NULL)
        return NULL;

    pg->points = malloc(sizeof(Point) * nb_points);
    if (pg->points == NULL) {
        free(pg);
        return NULL;
    }

    for (int i = 0; i < nb_points; i++) {
        pg->points[i] = point[i];
    }

    pg->nb_points = nb_points;
    pg->style = NULL;

    nb_forme++;
            return pg;
}

void free_polygone(Polygone* pg) {
    if (pg == NULL)
        return;

    if (pg->points != NULL)
        free(pg->points);

    free(pg);
}
