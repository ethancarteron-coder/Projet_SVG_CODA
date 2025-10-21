
#ifndef MODIFICATION_H
    #define MODIFICATION_H

    #include <math.h>
    #ifndef M_PI
        #define M_PI 3.1416
    #endif
    #include "shapes.h"


    void rotation(Point* point, const Point center, double angle);


    void deplace_shape(Point* point, int tx, int ty);


    void symetry(Point* point, const Point center, bool flip_x, bool flip_y);


    void apply_modif(Shape_node* shape);


    int modify_shape_position(Shape_node* node, Point new_position);
    int modify_shape_attributes(Shape_node* node, const Style* new_style);
#endif