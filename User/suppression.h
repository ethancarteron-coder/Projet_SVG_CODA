#ifndef SUPPRESSION_H
    #define SUPPRESSION_H

    #include "shapes.h"

    int delete_shape(Shape_node* node);
    int delete_group(Group* group);
    int delete_from_group(Group* group, Shape_node* node);
    void del_all(ShapeList* list);

#endif 