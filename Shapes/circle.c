#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "../Utils/error.h"

int nb_forme = 0;

Circle* circle_info(Point center, int radius) {
    if (radius <= 0) {
        SET_ERROR(ERR_INVALID_PARAMETER, "Circle radius must be positive");
        return NULL;
    }

    Circle* ci = malloc(sizeof(Circle));
    if (ci == 0) {
        SET_ERROR(ERR_MEMORY, "Failed to allocate memory for circle");
        return NULL;
    }

    ci->center = center;
    ci->radius = radius;
    

    ci->style = attributes_create();
    if (ci->style == 0) {
        free(ci);
        SET_ERROR(ERR_MEMORY, "Failed to allocate memory for circle attributes");
        return NULL;
    }


    ci->transform.angle = 0.0;
    ci->transform.dx = 0;
    ci->transform.dy = 0;
    ci->transform.flip_x = false;
    ci->transform.flip_y = false;
    
    nb_forme++;
    return ci;
}

void free_circle(Circle* ce) {
    if (ce == NULL) return;

    if (ce->style != NULL) {
        attributes_free(ce->style);
    }
    free(ce);
}