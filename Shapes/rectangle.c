#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Rectangle* rectangle_info (const Point origin, const int lenght, const int width){
    Rectangle* re = (Rectangle*)malloc(sizeof(Rectangle));
    re->origin = origin;
    re->style = NULL;
    re->lenght = lenght;
    re->width = width;

    nb_forme++;
    return re;
}

void free_rectangle (Rectangle* re) {
    if (re == 0)
        return;
    
    free(re);
}