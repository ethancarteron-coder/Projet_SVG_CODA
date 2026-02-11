#ifndef LIST_H
    #define LIST_H

    #include "shapes.h"

    ShapeList* create_list();

    void add_shape (ShapeList* list, ShapeType type, ShapeData data);

    void list_shapes(ShapeList* list);

#endif