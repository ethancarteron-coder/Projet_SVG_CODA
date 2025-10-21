#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

Line* line_info (const Point start, const Point end) {
    Line* li = malloc(sizeof(Line));
    if (li == NULL) return NULL;

    li->start = start;
    li->end = end;

    li->style = style_info("black", "white", 1.0f);
    if (li->style == NULL) {
        free(li);
        return NULL;
    }

    li->modif.angle = 0.0;
    li->modif.dx = 0;
    li->modif.dy = 0;
    li->modif.symetry_x = false;
    li->modif.symetry_y = false;

    nb_forme++;
    printf(GREEN"Ligne créée avec succès !\n"RESET);
    printf("appuyez sur entrer pour continuer...\n");
    scanf("%*c", getchar());
    return li;
}

void free_line (Line* li) {
    if (li == NULL) return;

    if (li->style != NULL) {
        free_style(li->style);
    }

    free(li);
}