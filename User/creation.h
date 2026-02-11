#ifndef CREATION_H
    #define CREATION_H

    #include "shapes.h"

    void ask_circle (ShapeList* list, Point center, Style* style);

    void ask_ellipse (ShapeList* list, Point center);

    void ask_line (ShapeList* list, Point start, Point end);

    void ask_rectangle (ShapeList* list, Point origin);

    void ask_square (ShapeList* list, Point origin);

#endif