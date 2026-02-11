#ifndef LIST_H
    #define LIST_H

    #include "../Shapes/shapes.h"

    ShapeList* create_list();

    void add_shape (ShapeList* list, ShapeType type, ShapeData data);

    void show_list (const int i, const ShapeNode* node);

    void list_shapes(const ShapeList* list);

#endif