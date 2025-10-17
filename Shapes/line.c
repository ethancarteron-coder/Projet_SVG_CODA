#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Line* line_info (Point start, Point end) {
    Line* li = malloc(sizeof(Line));
    if (li == 0) 
        return NULL;

    li->start = start;
    li->end = end;

    nb_forme++;
    return li;
}

void free_line (Line* li) {
    if (li == 0)
        return;
    
    free(li);
}