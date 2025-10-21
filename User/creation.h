#ifndef CREATION_H
    #define CREATION_H

    #include "shapes.h"

    void ask_circle (Shape_list* list, Point center, Style* style);

    void ask_ellipse (Shape_list* list, Point center);

    void ask_line (Shape_list* list, Point start, Point end);

    void ask_rectangle (Shape_list* list, Point origin);

    void ask_square (Shape_list* list, Point origin);

#endif