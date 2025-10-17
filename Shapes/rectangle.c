#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Rectangle* rectangle_info (Point origin, int lenght, int width){
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