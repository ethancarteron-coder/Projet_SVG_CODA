#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

int nb_forme = 0;

Circle* circle_info(Point center, int radius) {

    Circle* ci = malloc(sizeof(Circle));
    if (ci == NULL) return NULL;

    ci->center = center;
    ci->radius = radius;

    const char* stroke_color;
    const char* fill_color;
    float stroke_width;
    ci->style = style_info("black", "white", 1.0f);
    if (ci->style == NULL) {
        free(ci);
        return NULL;
    }


    ci->modif.angle = 0.0;
    ci->modif.dx = 0;
    ci->modif.dy = 0;
    ci->modif.flip_x = false;
    ci->modif.flip_y = false;
    
    nb_forme++;
    return ci;
}

void free_circle(Circle* ce) {
    if (ce == NULL) return;

    if (ce->style != NULL) {
        free_style(ce->style);
    }
    free(ce);
}