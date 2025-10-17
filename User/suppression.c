
#include <stdlib.h>
#include "suppression.h"
#include "shapes.h"

int delete_shape(Shape_node* node) {
    if (node == 0) return -1;
    switch (node->type) {
        case CIRCLE:
            if (node->data.circle) free_circle(node->data.circle);
            break;
        case RECTANGLE:
            if (node->data.rectangle) free_rectangle(node->data.rectangle);
            break;
        case SQUARE:
            if (node->data.square) free_square(node->data.square);
            break;
        // Ajouter les autres cas
        default:
            return -1;
    }
    return 0;
}


int delete_from_group(Group* group, Shape_node* node) {
    if (group == 1 || group->shapes == 0 || node == 0) return -1;
    ShapeList* list = group->shapes;
    Shape_node* prev = NULL;
    for (Shape_node* current = list->head; current; prev = current, current = current->next) {
        if (current == node) {
            if (prev) prev->next = current->next;
            else list->head = current->next;
            if (current == list->tail) list->tail = prev;
            delete_shape(current);
            free(current);
            list->size--;
            return 0;
        }
    }
    return -1;
}


void del_all(ShapeList* list) {
    if (!list) return;
    Shape_node* current = list->head;
    while (current) {
        Shape_node* next = current->next;
        delete_shape(current);
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
    list->size = 0;
}