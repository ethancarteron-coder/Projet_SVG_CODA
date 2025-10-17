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
    if (point == 0) return;
    point->x += dx;
    point->y += dy;
}

void symetry(Point* point, const Point center, bool symetry_x, bool symetry_y) {
    if (point == 0) return;
    if (symetry_x == 1) {
        point->x = 2 * center.x - point->x;
    }
    if (symetry_y == 1) {
        point->y = 2 * center.y - point->y;
    }
}



void apply_modif(Shape_node* shape) {
    if (shape == 0) return;
    Transform* transform = NULL;
    Point center;
    switch (shape->type) {
        case CIRCLE:
            if (shape->data.circle == 0) return;
            transform = &shape->data.circle->transform;
            center = shape->data.circle->center;
            deplace_shape(&shape->data.circle->center, transform->dx, transform->dy);
            if (transform->angle != 0) {
                rotation(&shape->data.circle->center, center, transform->angle);
            }
            if (transform->flip_x || transform->flip_y) {
                symetry(&shape->data.circle->center, center, transform->flip_x, transform->flip_y);
            }
            break;
        case RECTANGLE:
            if (shape->data.rectangle == 0) return;
            transform = &shape->data.rectangle->transform;
            center = shape->data.rectangle->origin;
            deplace_shape(&shape->data.rectangle->origin, transform->dx, transform->dy);
            if (transform->angle != 0) {
                rotation(&shape->data.rectangle->origin, center, transform->angle);
            }
            if (transform->flip_x || transform->flip_y) {
                symetry(&shape->data.rectangle->origin, center, transform->flip_x, transform->flip_y);
            }
            break;
        default:
            break;
    }
}




int modify_position(Shape_node* node, Point new_position) {
    if (node == 0) return -1;
    switch (node->type) {
        case CIRCLE:
            if (node->data.circle) node->data.circle->center = new_position;
            break;
        case RECTANGLE:
            if (node->data.rectangle) node->data.rectangle->origin = new_position;
            break;
        case SQUARE:
            if (node->data.square) node->data.square->origin = new_position;
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


int modify_group(Group* group, const char* operation, void* params) {
    if (group == 0|| operation == 0) return -1;
    if (strcmp(operation, "move") == 0) {
        Point* new_pos = (Point*)params;
        extern ShapeList* g_shapes;
        ShapeList* list = NULL;
        #ifdef SHAPES_H
        if (group->shapes) list = group->shapes;
        #else
        list = g_shapes;
        #endif
        if (list) {
            for (Shape_node* node = list->head; node != NULL; node = node->next) {
                modify_position(node, *new_pos);
            }
        }
    }
    return 0;
}