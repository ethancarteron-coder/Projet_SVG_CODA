#include "modification.h"
#include "shapes.h"
#include "list.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>

void deplace_shape(Point* point, int dx, int dy) {
    if (point == NULL) return;
    point->x += dx;
    point->y += dy;
}

void symetry(Point* point, const Point center, bool symetry_x, bool symetry_y) {
    if (point == NULL) return;
    if (symetry_x) {
        point->x = 2 * center.x - point->x;
    }
    if (symetry_y) {
        point->y = 2 * center.y - point->y;
    }
}



void apply_modif(Shape_node* shape) {
    if (shape == NULL) return;
    Modif* modif = NULL;
    Point center;
    
    switch (shape->type) {
        case CIRCLE:
            if (shape->data.circle == NULL) return;
            modif = &shape->data.circle->modif;
            center = shape->data.circle->center;
            if (modif->dx != 0 || modif->dy != 0) {
                deplace_shape(&shape->data.circle->center, modif->dx, modif->dy);
            }
            break;
            
        case RECTANGLE:
            if (shape->data.rectangle == 0) return;
            modif = &shape->data.rectangle->modif;
            center = shape->data.rectangle->origin;
            deplace_shape(&shape->data.rectangle->origin, modif->dx, modif->dy);

            if (modif->symetry_x || modif->symetry_y) {
                symetry(&shape->data.rectangle->origin, center, modif->symetry_x, modif->symetry_y);
            }
            break;
        default:
            break;
    }
}