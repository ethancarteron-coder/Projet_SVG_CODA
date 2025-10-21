#include "modification.h"
#include "shapes.h"
#include <string.h>

void rotation(Point* point, const Point center, double angle) {
    if (point == 0) return;
    double radians = angle * M_PI / 180.0;
    int x = point->x - center.x;
    int y = point->y - center.y;
    point->x = (int)(x * cos(radians) - y * sin(radians)) + center.x;
    point->y = (int)(x * sin(radians) + y * cos(radians)) + center.y;
}

void deplace_shape(Point* point, int dx, int dy) {
    if (point == NULL) return;
    point->x += dx;
    point->y += dy;
}

void symetry(Point* point, const Point center, bool symetry_x, bool symetry_y) {
    if (point == NULL) return;
    if (symetry_x != NULL) {
        point->x = 2 * center.x - point->x;
    }
    if (symetry_y == 1) {
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
            deplace_shape(&shape->data.circle->center, modif->dx, modif->dy);
            if (modif->angle != 0) {
                rotation(&shape->data.circle->center, center, modif->angle);
            }
            if (modif->flip_x != NULL|| modif->flip_y != NULL) {
                symetry(&shape->data.circle->center, center, modif->flip_x, modif->flip_y);
            }
            break;
        case RECTANGLE:
            if (shape->data.rectangle == 0) return;
            modif = &shape->data.rectangle->modif;
            center = shape->data.rectangle->origin;
            deplace_shape(&shape->data.rectangle->origin, modif->dx, modif->dy);
            if (modif->angle != 0) {
                rotation(&shape->data.rectangle->origin, center, modif->angle);
            }
            if (modif->flip_x != NULL || modif->flip_y != NULL) {
                symetry(&shape->data.rectangle->origin, center, modif->flip_x, modif->flip_y);
            }
            break;
        default:
            break;
    }
}




int modify_position(Shape_node* node, Point position) {
    if (node == 0) return -1;
    switch (node->type) {
        case CIRCLE:
            if (node->data.circle) node->data.circle->center = position;
            break;
        case RECTANGLE:
            if (node->data.rectangle) node->data.rectangle->origin = position;
            break;
        case SQUARE:
            if (node->data.square) node->data.square->origin = position;
            break;
        // Ajouter les autres cas
        default:
            return -1;
    }
    return 0;
}


int modify_attributes(Shape_node* node, const Style* new_style) {
    if (node == 0 || new_style == 0) return -1;
    switch (node->type) {
        case CIRCLE:
            if (node->data.circle && node->data.circle->style)
                *(node->data.circle->style) = *new_style;
            break;
        case RECTANGLE:
            if (node->data.rectangle && node->data.rectangle->style)
                *(node->data.rectangle->style) = *new_style;
            break;
        case SQUARE:
            if (node->data.square && node->data.square->style)
                *(node->data.square->style) = *new_style;
            break;
        // Ajouter les autres cas
        default:
            return -1;
    }
    return 0;
}
