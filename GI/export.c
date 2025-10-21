#include "export.h"
#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

void export_svg(const char *filename, Shape_list* list, Style* style) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    
    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\"> \n");
    
    if (list == NULL) return;
    Shape_node* current = list->head;
    while (current != NULL) {
        
        printf("Loop\n");
        switch (current->type) {
            case SQUARE: {
                Square* sq = (Square*)current->data.square;
                fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\" />\n",
                    sq->origin.x, sq->origin.y, sq->side, sq->side, sq->style->stroke_color, sq->style->fill_color);
                break;
            }
            case CIRCLE: {
                printf("Exporting Circle\n");
                Circle* ci = (Circle*)current->data.circle;
                if (ci != NULL && ci->style != NULL) {
                    printf("de la couleur !\n");
                    fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"%s\" fill=\"%s\" />\n",
                            ci->center.x, ci->center.y, ci->radius,
                            ci->style->stroke_color,
                            ci->style->fill_color);

                    printf("Cercle exporté avec succès!\n");
                } else {
                    printf("Attention: Cercle sans style détecté, ignoré.\n");
                }
                break;
            }
            case RECTANGLE: {
                Rectangle* re = (Rectangle*)current->data.rectangle;
                fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\" />\n",
                        re->origin.x, re->origin.y, re->lenght, re->width, re->style->stroke_color, re->style->fill_color);
                break;
            }
            case ELLIPSE: {
                Ellipse* el = (Ellipse*)current->data.ellipse;
                fprintf(f, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" stroke=\"%s\" fill=\"%s\" />\n",
                        el->center.x, el->center.y, el->radius_x, el->radius_y, el->style->stroke_color, el->style->fill_color);
                break;
            }
            case LINE: {
                Line* li = (Line*)current->data.line;
                fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" />\n",
                        li->start.x, li->start.y, li->end.x, li->end.y, li->style->stroke_color);
                break;
            }
            case POLYGONE: {
                Polygone* pg = (Polygone*)current->data.polygone;
                fprintf(f, "<polygon points=\"");
                for (int j = 0; j < pg->nb_points; j++) {
                    fprintf(f, "%d,%d ", pg->points[j].x, pg->points[j].y);
                }
                fprintf(f, "\" stroke=\"%s\" fill=\"%s\" />\n",
                        pg->style->stroke_color, pg->style->fill_color);
                break;
            }
            case POLYLINE: {
                Polyline* pl = (Polyline*)current->data.polyline;
                fprintf(f, "<polyline points=\"");
                for (int j = 0; j < pl->nb_points; j++) {
                    fprintf(f, "%d,%d ", pl->points[j].x, pl->points[j].y);
                }
                fprintf(f, "\" stroke=\"%s\" fill=\"none\" />\n", pl->style->stroke_color);
                break;
            }
            default:
                printf("Forme non reconnue");
                return;
        }
        current = current->next;
    }

    fprintf(f, "</svg>\n");
    fclose(f);
    printf("Export SVG termine : %s\n", filename);
}