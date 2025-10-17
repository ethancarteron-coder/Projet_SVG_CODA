#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Ellipse* ellipse_info (Point center, int radius_x, int radius_y) {
    Ellipse* el = malloc(sizeof(Ellipse));
    if(el == 0)
        return NULL;
    
    el->center = center;
    el->radius_x = radius_x;
    el->radius_y = radius_y;

    nb_forme++;
    return el;
}

void free_ellipse(Ellipse* el) {
    if(el == 0)
        return;
    
    free(el);
}
