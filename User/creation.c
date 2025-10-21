#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "shapes.h"
#include "menu.h"


void ask_circle(Shape_list* list, Point center, Style* style) {
    int radius;
    float stroke_width;
    char* fill_color = malloc(16);
    if (fill_color == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    char* stroke_color = malloc(16);
    if (stroke_color == NULL) { free(fill_color); perror("malloc"); exit(EXIT_FAILURE); }

    printf("Entrez la coordonnée x : "); center.x = read_int();
    printf("Entrez la coordonnée y : "); center.y = read_int();
    printf("Entrez le rayon : "); radius = read_int();
    printf("Entrez l'épaisseur du trait : "); stroke_width = read_float();
    buffer_clean();
    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) {
        printf(RED"Erreur lors de la saisie de la couleur de fond\n"RESET);
        return;
    }
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) {
        printf(RED"Erreur lors de la saisie de la couleur du trait\n"RESET);
        return;
    }

    Circle* ci = circle_info(center, radius);
    if (ci == NULL) {
        free(fill_color);
        free(stroke_color);
        printf(RED"Erreur lors de la création du cercle\n"RESET);
        return;
    }

    if (ci->style != NULL) {
        free_style(ci->style);
    }
    ci->style = style_info(stroke_color, fill_color, stroke_width);

    free(fill_color);
    free(stroke_color);

    Shapes_data data = {.circle = ci};
    add_shape(list, CIRCLE, data);
}

void ask_ellipse (Shape_list* list, Point center) {
    int radius_x, radius_y;
    float stroke_width;
    char* fill_color = malloc(16);
    if (fill_color == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    char* stroke_color = malloc(16);
    if (stroke_color == NULL) { free(fill_color); perror("malloc"); exit(EXIT_FAILURE); }

    printf("Entrez la coordonnée x : "); center.x = read_int();
    printf("Entrez la coordonnée y : "); center.y = read_int();
    printf("Entrez le rayon x : "); radius_x = read_int();
    printf("Entrez le rayon y : "); radius_y = read_int();
    printf("Entrez l'épaisseur du trait : "); stroke_width = read_float();
    buffer_clean();
    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) {
        free(fill_color);
        free(stroke_color);
        return;
    }
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) {
        free(fill_color);
        free(stroke_color);
        return;
    }

    Ellipse* el = ellipse_info(center, radius_x, radius_y);
    if (el == NULL) {
        free(fill_color);
        free(stroke_color);
        return;
    }

    if (el->style != NULL) {
        free_style(el->style);
    }
    el->style = style_info(stroke_color, fill_color, stroke_width);

    free(fill_color);
    free(stroke_color);

    Shapes_data data = {.ellipse = el};
    add_shape(list, ELLIPSE, data);
}

void ask_line (Shape_list* list, Point start, Point end) {
    float stroke_width;
    char* stroke_color = malloc(16);
    if (stroke_color == NULL) { perror("malloc"); exit(EXIT_FAILURE); }

    printf("Point de départ :\n");
    printf("Entrez la coordonnée x : "); start.x = read_int();
    printf("Entrez la coordonnée y : "); start.y = read_int();
    
    printf("\nPoint d'arrivée :\n");
    printf("Entrez la coordonnée x : "); end.x = read_int();
    printf("Entrez la coordonnée y : "); end.y = read_int();

    printf("Entrez l'épaisseur du trait : "); stroke_width = read_float();
    buffer_clean();
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) {
        free(stroke_color);
        return;
    }

    Line* li = line_info(start, end);
    if (li == NULL) {
        free(stroke_color);
        return;
    }

    if (li->style != NULL) {
        free_style(li->style);
    }
    li->style = style_info(stroke_color, "none", stroke_width);

    free(stroke_color);

    Shapes_data data = {.line = li};
    add_shape(list, LINE, data);
}

void ask_rectangle(Shape_list* list, Point origin) {
    int lenght, width;
    float stroke_width;
    char* fill_color = malloc(16);
    if (fill_color == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    char* stroke_color = malloc(16);
    if (stroke_color == NULL) { free(fill_color); perror("malloc"); exit(EXIT_FAILURE); }

    printf("Entrez la coordonnée x : "); origin.x = read_int();
    printf("Entrez la coordonnée y : "); origin.y = read_int();
    printf("Entrez la longueur : "); lenght = read_int();
    printf("Entrez la largeur : "); width = read_int();
    printf("Entrez l'épaisseur du trait : "); stroke_width = read_float();
    buffer_clean();
    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) {
        free(fill_color);
        free(stroke_color);
        return;
    }
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) {
        free(fill_color);
        free(stroke_color);
        return;
    }

    Rectangle* re = rectangle_info(origin, lenght, width);
    if (re == NULL) {
        free(fill_color);
        free(stroke_color);
        return;
    }

    if (re->style != NULL) {
        free_style(re->style);
    }
    re->style = style_info(stroke_color, fill_color, stroke_width);

    free(fill_color);
    free(stroke_color);

    Shapes_data data = {.rectangle = re};
    add_shape(list, RECTANGLE, data);
}

void ask_square(Shape_list* list, Point origin) {
    int x, y, side;
    printf("Entrez la coordonnée x : "); origin.x = read_int();
    printf("Entrez la coordonnée y : "); origin.y = read_int();
    printf("Entrez le côté : "); side =  read_int();

    Circle* circle_info (origin, side);

}

void ask_polygone(Shape_list* list, Point center) {
    int nb_points;
    float stroke_width;
    char* fill_color = malloc(16);
    if (fill_color == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    char* stroke_color = malloc(16);
    if (stroke_color == NULL) { free(fill_color); perror("malloc"); exit(EXIT_FAILURE); }

    printf("Entrez le nombre de points (minimum 3) : ");
    nb_points = read_int();
    if (nb_points < 3) {
        printf(RED"Le polygone doit avoir au moins 3 points.\n"RESET);
        free(fill_color);
        free(stroke_color);
        return;
    }

    Point* points = malloc(sizeof(Point) * nb_points);
    if (points == NULL) {
        free(fill_color);
        free(stroke_color);
        perror("malloc");
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("Point %d :\n", i + 1);
        printf("Entrez la coordonnée x : "); points[i].x = read_int();
        printf("Entrez la coordonnée y : "); points[i].y = read_int();
    }

    printf("Entrez l'épaisseur du trait : "); stroke_width = read_float();
    buffer_clean();
    if (!seize_color(fill_color, 16, "Entrez la couleur du fond : ")) {
        free(points);
        free(fill_color);
        free(stroke_color);
        return;
    }
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) {
        free(points);
        free(fill_color);
        free(stroke_color);
        return;
    }

    Polygone* pg = polygone_info(points, nb_points);
    if (pg == NULL) {
        free(points);
        free(fill_color);
        free(stroke_color);
        return;
    }

    if (pg->style != NULL) {
        free_style(pg->style);
    }
    pg->style = style_info(stroke_color, fill_color, stroke_width);

    free(points);
    free(fill_color);
    free(stroke_color);

    Shapes_data data = {.polygone = pg};
    add_shape(list, POLYGONE, data);
}

void ask_polyline(Shape_list* list, Point center) {
    int nb_points;
    float stroke_width;
    char* stroke_color = malloc(16);
    if (stroke_color == NULL) { perror("malloc"); exit(EXIT_FAILURE); }

    printf("Entrez le nombre de points (minimum 2) : ");
    nb_points = read_int();
    if (nb_points < 2) {
        printf(RED"La polyligne doit avoir au moins 2 points.\n"RESET);
        free(stroke_color);
        return;
    }

    Point* points = malloc(sizeof(Point) * nb_points);
    if (points == NULL) {
        free(stroke_color);
        perror("malloc");
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("Point %d :\n", i + 1);
        printf("Entrez la coordonnée x : "); points[i].x = read_int();
        printf("Entrez la coordonnée y : "); points[i].y = read_int();
    }

    printf("Entrez l'épaisseur du trait : "); stroke_width = read_float();
    buffer_clean();
    if (!seize_color(stroke_color, 16, "Entrez la couleur du trait : ")) {
        free(points);
        free(stroke_color);
        return;
    }

    Polyline* pl = polyline_info(points, nb_points);
    if (pl == NULL) {
        free(points);
        free(stroke_color);
        return;
    }

    if (pl->style != NULL) {
        free_style(pl->style);
    }
    pl->style = style_info(stroke_color, "none", stroke_width);

    free(points);
    free(stroke_color);

    Shapes_data data = {.polyline = pl};
    add_shape(list, POLYLINE, data);
}