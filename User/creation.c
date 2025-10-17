#include <stdio.h>
#include "utils.h"
#include "shapes.h"


void ask_circle(ShapeList* list, Point center) {
    int x, y, radius;
    printf("Entrez la coordonnée x : "); center.x = read_int();
    printf("Entrez la coordonnée y : "); center.y = read_int();
    printf("Entrez le rayon : "); radius =  read_int();

    Circle* ci = circle_info (center, radius);
    Shapes_data data = {.circle = ci};
    add_shape (list, CIRCLE, data);
}

void ask_ellipse (ShapeList* list, Point center) {
    int x, y, radius_x, radius_y;
    printf("Entrez la coordonnée x : "); center.x = read_int();
    printf("Entrez la coordonnée y : "); center.y = read_int();
    printf("Entrez le rayon x : "); radius_x = read_int();
    printf("Entrez le rayon y : "); radius_y = read_int();

    Ellipse* ellipse_info (center, radius_x, radius_y);
}

void ask_line (ShapeList* list, Point start, Point end) {
    int x, y;
    printf("Entrez la coordonnée x de départ : "); start.x = read_int();
    printf("Entrez la coordonnée y de départ : "); start.y = read_int();
    printf("Entrez la coordonnée x de fin : "); end.x = read_int();
    printf("Entrez la coordonnée y de fin : "); end.y = read_int();

    Line* line_info(start, end);
}

void ask_rectangle(ShapeList* list, Point origin) {
    int x, y, lenght, width;
    printf("Entrez la coordonnée x : "); origin.x = read_int();
    printf("Entrez la coordonnée y : "); origin.y = read_int();
    printf("Entrez le la longueur : "); lenght =  read_int();
    printf("Entrez le la largeur : "); width =  read_int();

    Rectangle* rectangle_info (origin, lenght, width);

}

void ask_square(ShapeList* list, Point origin) {
    int x, y, side;
    printf("Entrez la coordonnée x : "); origin.x = read_int();
    printf("Entrez la coordonnée y : "); origin.y = read_int();
    printf("Entrez le côté : "); side =  read_int();

    Circle* circle_info (origin, side);

}

void ask_polygone(ShapeList* list, Point center) {
    int nb_points;
    printf("Entrez le nombre de points du polygone : "); nb_points = read_int();

    Point* points = malloc(sizeof(Point) * nb_points);
    if (points == NULL) {
        printf("Erreur d'allocation mémoire pour les points.\n");
        return;
    }

    for (int i = 0; i < nb_points; i++) {
        printf("Point %d:\n", i + 1);
        printf("Entrez la coordonnée x : "); points[i].x = read_int();
        printf("Entrez la coordonnée y : "); points[i].y = read_int();
    }

    Polygone* polygone_info(points, nb_points);
    free(points);
}

void ask_polyline(ShapeList* list, Point center) {
    int nb_points;
    printf("Entrez le nombre de points de la polyligne : "); nb_points = read_int();
    
    Point* point = malloc(sizeof(Point) * nb_points);
    if (point == NULL) {
        printf("Erreur d'allocation mémoire pour les points.\n");
        return;
    }
    for (int i = 0; i < nb_points; i++) {
        printf("Point %d:\n", i + 1);
        printf("Entrez la coordonnée x : "); point[i].x = read_int();
        printf("Entrez la coordonnée y : "); point[i].y = read_int();
    }

    Polyline* polyline_info (Point* point, int nb_points);
}