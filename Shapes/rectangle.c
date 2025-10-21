#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Rectangle* rectangle_info (const Point origin, const int lenght, const int width) {
    Rectangle* re = (Rectangle*)malloc(sizeof(Rectangle));
    if (re == NULL) return NULL;

    re->origin = origin;
    re->lenght = lenght;
    re->width = width;

    re->style = style_info("black", "white", 1.0f);
    if (re->style == NULL) {
        free(re);
        return NULL;
    }

    re->modif.angle = 0.0;
    re->modif.dx = 0;
    re->modif.dy = 0;
    re->modif.symetry_x = false;
    re->modif.symetry_y = false;

    nb_forme++;
    printf(GREEN"Rectangle créé avec succès !\n"RESET);
    printf("appuyez sur entrer pour continuer...\n");
    scanf("%*c", getchar());
    return re;
}

void free_rectangle (Rectangle* re) {
    if (re == NULL) return;

    if (re->style != NULL) {
        free_style(re->style);
    }

    free(re);
}