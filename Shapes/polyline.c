#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Polyline* polyline_info(const Point* point, const int nb_points) {
    if (point == NULL || nb_points <= 0)
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
        pl->points[i] = point[i];
    }

    pl->nb_points = nb_points;

    pl->style = style_info("black", "white", 1.0f);
    if (pl->style == NULL) {
        free(pl->points);
        free(pl);
        return NULL;
    }

    pl->modif.angle = 0.0;
    pl->modif.dx = 0;
    pl->modif.dy = 0;
    pl->modif.symetry_x = false;
    pl->modif.symetry_y = false;

    nb_forme++;
    printf(GREEN"Polyligne créée avec succès !\n"RESET);
    printf("appuyez sur entrer pour continuer...\n");
    scanf("%*c", getchar());
    return pl;
}

void free_polyline(Polyline* pl) {
    if (pl == NULL)
        return;

    if (pl->points != NULL)
        free(pl->points);

    if (pl->style != NULL) {
        free_style(pl->style);
    }

    free(pl);
}
