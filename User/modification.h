#ifndef MODIFICATION_H
    #define MODIFICATION_H

    #include "shapes.h"
    
    void deplace_shape(Point* point, int dx, int dy);
    void symetry(Point* point, const Point center, bool symetry_x, bool symetry_y);
    void apply_modif(Shape_node* shape);

#endif