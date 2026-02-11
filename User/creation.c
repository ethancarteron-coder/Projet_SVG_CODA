#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "utils.h"
#include "shapes.h"

void ask_circle(ShapeList* list) {
    Point center;
    int radius;
    float stroke_width;
    char fill_color[16];
    char stroke_color[16];

    if (!read_int(&center.x, "Entrez la coordonnée x du centre : ")) return;
    if (!read_int(&center.y, "Entrez la coordonnée y du centre : ")) return;
    if (!read_int(&radius, "Entrez le rayon : ")) return;
    if (!read_float(&stroke_width, "Entrez l'épaisseur du trait : ")) return;

    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) return;
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) return;

    Circle* ci = circle_info(center, radius);
    if (ci == NULL) return;

    if (ci->style != NULL) free_style(ci->style);
    ci->style = style_info(stroke_color, fill_color, stroke_width);

    const ShapeData data = {.circle = ci};
    add_shape(list, CIRCLE, data);
}

void ask_ellipse(ShapeList* list) {
    Point center;
    int radius_x;
    int radius_y;
    float stroke_width;
    char fill_color[16];
    char stroke_color[16];

    if (!read_int(&center.x, "Entrez la coordonnée x du centre : ")) return;
    if (!read_int(&center.y, "Entrez la coordonnée y du centre : ")) return;
    if (!read_int(&radius_x, "Entrez le rayon X : ")) return;
    if (!read_int(&radius_y, "Entrez le rayon Y : ")) return;
    if (!read_float(&stroke_width, "Entrez l'épaisseur du trait : ")) return;

    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) return;
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) return;

    Ellipse* el = ellipse_info(center, radius_x, radius_y);
    if (el == NULL) return;

    if (el->style != NULL) free_style(el->style);
    el->style = style_info(stroke_color, fill_color, stroke_width);

    const ShapeData data = {.ellipse = el};
    add_shape(list, ELLIPSE, data);
}

void ask_line(ShapeList* list) {
    Point start;
    Point end;
    float stroke_width;
    char stroke_color[16];

    printf("--- Point de départ ---\n");
    if (!read_int(&start.x, "x : ")) return;
    if (!read_int(&start.y, "y : ")) return;

    printf("--- Point d'arrivée ---\n");
    if (!read_int(&end.x, "x : ")) return;
    if (!read_int(&end.y, "y : ")) return;

    if (!read_float(&stroke_width, "Entrez l'épaisseur du trait : ")) return;
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) return;

    Line* li = line_info(start, end);
    if (li == NULL) return;

    if (li->style != NULL) free_style(li->style);
    li->style = style_info(stroke_color, "none", stroke_width);

    const ShapeData data = {.line = li};
    add_shape(list, LINE, data);
}

void ask_rectangle(ShapeList* list) {
    Point origin;
    int lenght;
    int width;
    float stroke_width;
    char fill_color[16];
    char stroke_color[16];

    if (!read_int(&origin.x, "Entrez la coordonnée x (coin haut gauche) : ")) return;
    if (!read_int(&origin.y, "Entrez la coordonnée y (coin haut gauche) : ")) return;
    if (!read_int(&lenght, "Entrez la longueur : ")) return;
    if (!read_int(&width, "Entrez la largeur : ")) return;
    if (!read_float(&stroke_width, "Entrez l'épaisseur du trait : ")) return;

    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) return;
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) return;

    Rectangle* re = rectangle_info(origin, lenght, width);
    if (re == NULL) return;

    if (re->style != NULL) free_style(re->style);
    re->style = style_info(stroke_color, fill_color, stroke_width);

    const ShapeData data = {.rectangle = re};
    add_shape(list, RECTANGLE, data);
}

void ask_square(ShapeList* list) {
    Point origin;
    int side;
    float stroke_width;
    char fill_color[16];
    char stroke_color[16];

    if (!read_int(&origin.x, "Entrez la coordonnée x (coin haut gauche) : ")) return;
    if (!read_int(&origin.y, "Entrez la coordonnée y (coin haut gauche) : ")) return;
    if (!read_int(&side, "Entrez la longueur du côté : ")) return;
    if (!read_float(&stroke_width, "Entrez l'épaisseur du trait : ")) return;

    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) return;
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) return;

    Square* sq = square_info(origin, side);
    if (sq == NULL) return;

    if (sq->style != NULL) free_style(sq->style);
    sq->style = style_info(stroke_color, fill_color, stroke_width);

    const ShapeData data = {.square = sq};
    add_shape(list, SQUARE, data);
}

void ask_polyline(ShapeList* list) {
    int intput_value;
    float stroke_width;
    char stroke_color[16];

    if (!read_int(&intput_value, "Entrez le nombre de points (min 2) : ")) return;
    if (intput_value < 2) {
        printf(RED "Il faut au moins 2 points.\n" RESET);
        return;
    }
    const size_t nb_points = (size_t)intput_value;

    Point* points = malloc(sizeof(Point) * nb_points);
    if (points == NULL) {
        perror("Erreur allocation points");
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("--- Point %d ---\n", i + 1);
        if (!read_int(&points[i].x, "x : ")) { free(points); return; }
        if (!read_int(&points[i].y, "y : ")) { free(points); return; }
    }

    if (!read_float(&stroke_width, "Entrez l'épaisseur du trait : ")) { free(points); return; }
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) { free(points); return; }

    Polyline* pl = polyline_info(points, nb_points);

    free(points);

    if (pl == NULL) return;

    if (pl->style != NULL) free_style(pl->style);
    pl->style = style_info(stroke_color, "none", stroke_width);

    const ShapeData data = {.polyline = pl};
    add_shape(list, POLYLINE, data);
}

void ask_polygone(ShapeList* list) {
    int input_value;
    float stroke_width;
    char fill_color[16];
    char stroke_color[16];

    if (!read_int(&input_value, "Entrez le nombre de points (min 3) : ")) return;
    if (input_value < 3) {
        printf(RED "Il faut au moins 3 points pour un polygone.\n" RESET);
        return;
    }

    const size_t nb_points = (size_t)input_value;

    Point* points = malloc(sizeof(Point) * nb_points);
    if (points == NULL) {
        perror("Erreur allocation points");
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("--- Point %d ---\n", i + 1);
        if (!read_int(&points[i].x, "x : ")) { free(points); return; }
        if (!read_int(&points[i].y, "y : ")) { free(points); return; }
    }

    if (!read_float(&stroke_width, "Entrez l'épaisseur du trait : ")) { free(points); return; }
    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) { free(points); return; }
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) { free(points); return; }

    Polygone* pg = polygone_info(points, input_value);

    free(points);

    if (pg == NULL) return;

    if (pg->style != NULL) free_style(pg->style);
    pg->style = style_info(stroke_color, fill_color, stroke_width);

    const ShapeData data = {.polygone = pg};
    add_shape(list, POLYGONE, data);
}