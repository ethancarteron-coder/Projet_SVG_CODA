#ifndef MENU_H
    #define MENU_H

    #include <stdio.h>
    #include "shapes.h"
    
    int main (void);
    void creation_menu(Shape_list* list, Point origin, Style *style);
    void modification_menu(Shape_list* list);

#endif