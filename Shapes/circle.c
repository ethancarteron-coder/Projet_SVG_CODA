#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "utils.h"

int nb_forme = 0;

Circle* circle_info(const Point center, const int radius, Style* style) {

    Circle* ci = malloc(sizeof(Circle));
    if (ci == NULL) return NULL;

    ci->center = center;
    ci->radius = radius;
    ci->style = style;

    ci->style = style_info(style->stroke_color, style->fill_color, style->stroke_width);
    if (ci->style == NULL) {
        free(ci);
        return NULL;
    }


    ci->modif.angle = 0.0;
    ci->modif.dx = 0;
    ci->modif.dy = 0;
    ci->modif.symetry_x = false;
    ci->modif.symetry_y = false;
    
    nb_forme++;
    printf(GREEN"Cercle créé avec succès !\n"RESET);
    printf("appuyez sur entrer pour continuer...\n");
    buffer_clean();
    return ci;
}

void free_circle(Circle* ci) {
    if (ci == NULL) return;

    if (ci->style != NULL) {
        free_style(ci->style);
    }

    free(ci);
}