#include "export.h"
#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include <unistd.h>

void export_svg(const char *filename, Shape_list* list, Style* style) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    
    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"960\" height=\"540\"> \n");
    
    if (list == NULL) return;
    Shape_node* current = list->head;
    while (current != NULL) {
        switch (current->type) {
            case SQUARE: {
                Square* sq = (Square*)current->data.square;
                if (sq != NULL && sq->style != NULL) {
                    fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
                        sq->origin.x, sq->origin.y, sq->side, sq->side, 
                        sq->style->stroke_color, sq->style->fill_color, sq->style->stroke_width);
                    printf(GREEN "Carré exporté avec succès!\n" RESET);
                } else {
                    printf(YELLOW "Attention: Carré sans style détecté, ignoré.\n" RESET);
                }
                break;
            }
            case CIRCLE: {
                Circle* ci = (Circle*)current->data.circle;
                if (ci != NULL && ci->style != NULL) {
                    fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
                        ci->center.x, ci->center.y, ci->radius,
                        ci->style->stroke_color, ci->style->fill_color, ci->style->stroke_width);
                    printf(GREEN "Cercle exporté avec succès!\n" RESET);
                } else {
                    printf(YELLOW "Attention: Cercle sans style détecté, ignoré.\n" RESET);
                }
                break;
            }
            case RECTANGLE: {
                Rectangle* re = (Rectangle*)current->data.rectangle;
                if (re != NULL && re->style != NULL) {
                    fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
                        re->origin.x, re->origin.y, re->lenght, re->width,
                        re->style->stroke_color, re->style->fill_color, re->style->stroke_width);
                    printf(GREEN "Rectangle exporté avec succès!\n" RESET);
                } else {
                    printf(YELLOW "Attention: Rectangle sans style détecté, ignoré.\n" RESET);
                }
                break;
            }
            case ELLIPSE: {
                Ellipse* el = (Ellipse*)current->data.ellipse;
                if (el != NULL && el->style != NULL) {
                    fprintf(f, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
                        el->center.x, el->center.y, el->radius_x, el->radius_y,
                        el->style->stroke_color, el->style->fill_color, el->style->stroke_width);
                    printf(GREEN "Ellipse exportée avec succès!\n" RESET);
                } else {
                    printf(YELLOW "Attention: Ellipse sans style détectée, ignorée.\n" RESET);
                }
                break;
            }
            case LINE: {
                Line* li = (Line*)current->data.line;
                if (li != NULL && li->style != NULL) {
                    fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%.1f\" />\n",
                        li->start.x, li->start.y, li->end.x, li->end.y,
                        li->style->stroke_color, li->style->stroke_width);
                    printf(GREEN "Ligne exportée avec succès!\n" RESET);
                } else {
                    printf(YELLOW "Attention: Ligne sans style détectée, ignorée.\n" RESET);
                }
                break;
            }
            case POLYGONE: {
                Polygone* pg = (Polygone*)current->data.polygone;
                if (pg != NULL && pg->style != NULL && pg->points != NULL) {
                    fprintf(f, "<polygon points=\"");
                    for (int j = 0; j < pg->nb_points; j++) {
                        fprintf(f, "%d,%d ", pg->points[j].x, pg->points[j].y);
                    }
                    fprintf(f, "\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
                        pg->style->stroke_color, pg->style->fill_color, pg->style->stroke_width);
                    printf(GREEN "Polygone exporté avec succès!\n" RESET);
                } else {
                    printf(YELLOW "Attention: Polygone sans style ou points détecté, ignoré.\n" RESET);
                }
                break;
            }
            case POLYLINE: {
                Polyline* pl = (Polyline*)current->data.polyline;
                if (pl != NULL && pl->style != NULL && pl->points != NULL) {
                    fprintf(f, "<polyline points=\"");
                    for (int j = 0; j < pl->nb_points; j++) {
                        fprintf(f, "%d,%d ", pl->points[j].x, pl->points[j].y);
                    }
                    fprintf(f, "\" stroke=\"%s\" fill=\"none\" stroke-width=\"%.1f\" />\n",
                        pl->style->stroke_color, pl->style->stroke_width);
                    printf(GREEN "Polyligne exportée avec succès!\n" RESET);
                } else {
                    printf(YELLOW "Attention: Polyligne sans style ou points détectée, ignorée.\n" RESET);
                }
                break;
            }
            default:
                printf(RED "Type de forme non reconnu\n" RESET);
                return;
        }
        current = current->next;
    }

    fprintf(f, "</svg>\n");
    fclose(f);
    printf(GREEN"Export SVG termine : %s\n"RESET, filename);
    scanf("%*c", getchar());
}