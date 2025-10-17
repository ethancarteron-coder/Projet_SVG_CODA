// list.h
#ifndef LIST_H
#define LIST_H

#include "../Shapes/shapes.h"

void add_shape (ShapeList* list, Shapes_type type, Shapes_data data);

void list_shapes(ShapeList* list);

#endif