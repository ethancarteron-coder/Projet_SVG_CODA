#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Ellipse* ellipse_info (const Point center, const int radius_x, const int radius_y) {
    Ellipse* el = malloc(sizeof(Ellipse));
    if (el == NULL) return NULL;
    
    el->center = center;
    el->radius_x = radius_x;
    el->radius_y = radius_y;

    el->style = style_info("black", "white", 1.0f);
    if (el->style == NULL) {
        free(el);
        return NULL;
    }

    el->modif.angle = 0.0;
    el->modif.dx = 0;
    el->modif.dy = 0;
    el->modif.symetry_x = false;
    el->modif.symetry_y = false;

    nb_forme++;
    printf(GREEN"Ellipse créée avec succès !\n"RESET);
    printf("appuyez sur entrer pour continuer...\n");
    scanf("%*c", getchar());
    return el;
}

void free_ellipse(Ellipse* el) {
    if (el == NULL) return;

    if (el->style != NULL) {
        free_style(el->style);
    }

    free(el);
}
