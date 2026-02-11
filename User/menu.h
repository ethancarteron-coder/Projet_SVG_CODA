#ifndef MENU_H
    #define MENU_H

    #include <stdio.h>
    #include "shapes.h"
    
    int main (void);

    void creation_menu(ShapeList* list, Point origin, Style *style);
    void modification_menu(Point* origin);

#endif