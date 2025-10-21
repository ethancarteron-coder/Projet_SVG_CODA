
#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "list.h"

void add_shape (Shape_list* list, const Shapes_type type, const Shapes_data data) {
    if  (list == NULL) return;
    Shape_node* node = malloc(sizeof(Shape_node));
    if (node == NULL) return;

    node->type = type;
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;

    if  (list->tail != NULL)
        list->tail->next = node;
    else {
        list->head = node;
    }
    list->tail = node;
    list->size++;
}



void list_shapes(Shape_list* list) {
    if (list == NULL || list->size == 0) {
    printf(YELLOW"Aucune forme disponible.\n"RESET);
        return;
    }

    printf("Nombre total de formes: %d\n", list->size);
    int i = 1;
    for (Shape_node* node = list->head; node != NULL; node = node->next, i++) {
        switch (node->type) {
            case CIRCLE:
                if (node->data.circle) {
                    printf("Forme %d: cercle\n", i);
                    printf("  Centre: (%d, %d)\n", node->data.circle->center.x, node->data.circle->center.y);
                    printf("  Rayon: %d\n", node->data.circle->radius);
                }
                break;
            case ELLIPSE:
                if (node->data.ellipse) {
                    printf("Shape %d: Ellipse\n", i);
                    printf("  Center: (%d, %d)\n", node->data.ellipse->center.x, node->data.ellipse->center.y);
                    printf("  Radius X: %d\n", node->data.ellipse->radius_x);
                    printf("  Radius Y: %d\n", node->data.ellipse->radius_y);
                }
                break;
            case LINE:
                if (node->data.line) {
                    printf("Shape %d: Line\n", i);
                    printf("  Start: (%d, %d)\n", node->data.line->start.x, node->data.line->start.y);
                    printf("  End: (%d, %d)\n", node->data.line->end.x, node->data.line->end.y);
                }
                break;
            case POLYLINE:
                if (node->data.polyline) {
                    printf("Shape %d: Polyline\n", i);
                    printf("  Number of Points: %lu\n", (unsigned long)node->data.polyline->nb_points);
                    for (size_t j = 0; j < node->data.polyline->nb_points; j++) {
                        printf("    Point %lu: (%d, %d)\n", (unsigned long)(j+1),
                            (int)node->data.polyline->points[j].x,
                            (int)node->data.polyline->points[j].y);
                    }
                }
                break;


                
            // Ajouter autres types de formes


            default:
                printf(YELLOW"Shape %d: Type inconnu\n"RESET, i);
                break;
        }
    }
    printf("Appuyez sur Entrée pour continuer...\n");
    scanf("%*c", 0, getchar());
}