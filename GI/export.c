#include "export.h"
#include <stdio.h>
#include "../Shapes/shapes.h"
#include "../Utils/utils.h"
#include <unistd.h>


void export_square(FILE *f, const Square *sq) {
    if (sq != NULL && sq->style != NULL) {
        fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
            sq->origin.x, sq->origin.y, sq->side, sq->side,
            sq->style->stroke_color, sq->style->fill_color, sq->style->stroke_width);
        printf(GREEN "Carré exporté avec succès!\n" RESET);
    } else {
        printf(YELLOW "Attention: Carré sans style détecté, ignoré.\n" RESET);
    }
}

void export_circle(FILE *f, const Circle *ci) {
    if (ci != NULL && ci->style != NULL) {
        fprintf(f, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
            ci->center.x, ci->center.y, ci->radius,
            ci->style->stroke_color, ci->style->fill_color, ci->style->stroke_width);
        printf(GREEN "Cercle exporté avec succès!\n" RESET);
    } else {
        printf(YELLOW "Attention: Cercle sans style détecté, ignoré.\n" RESET);
    }
}

void export_rectangle(FILE *f, const Rectangle *re) {
    if (re != NULL && re->style != NULL) {
        fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
            re->origin.x, re->origin.y, re->lenght, re->width,
            re->style->stroke_color, re->style->fill_color, re->style->stroke_width);
        printf(GREEN "Rectangle exporté avec succès!\n" RESET);
    } else {
        printf(YELLOW "Attention: Rectangle sans style détecté, ignoré.\n" RESET);
    }
}

void export_ellipse(FILE *f, const Ellipse *el) {
    if (el != NULL && el->style != NULL) {
        fprintf(f, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
            el->center.x, el->center.y, el->radius_x, el->radius_y,
            el->style->stroke_color, el->style->fill_color, el->style->stroke_width);
        printf(GREEN "Ellipse exportée avec succès!\n" RESET);
    } else {
        printf(YELLOW "Attention: Ellipse sans style détectée, ignorée.\n" RESET);
    }
}

void export_line(FILE *f, const Line *li) {
    if (li != NULL && li->style != NULL) {
        fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%.1f\" />\n",
            li->start.x, li->start.y, li->end.x, li->end.y,
            li->style->stroke_color, li->style->stroke_width);
        printf(GREEN "Ligne exportée avec succès!\n" RESET);
    } else {
        printf(YELLOW "Attention: Ligne sans style détectée, ignorée.\n" RESET);
    }
}

void export_polygon(FILE *f, const Polygone *pg) {
    if (pg != NULL && pg->style != NULL && pg->points != NULL) {
        const int int_value = (int) pg->nb_points;
        fprintf(f, "<polygon points=\"");
        for (int j = 0; j < int_value; j++) {
            fprintf(f, "%d,%d ", pg->points[j].x, pg->points[j].y);
        }
        fprintf(f, "\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%.1f\" />\n",
            pg->style->stroke_color, pg->style->fill_color, pg->style->stroke_width);
        printf(GREEN "Polygone exporté avec succès!\n" RESET);
    } else {
        printf(YELLOW "Attention: Polygone sans style ou points détecté, ignoré.\n" RESET);
    }
}

void export_polyline(FILE *f, const Polyline *pl) {
    if (pl != NULL && pl->style != NULL && pl->points != NULL) {
        const int int_value = (int) pl->nb_points;
        fprintf(f, "<polyline points=\"");
        for (int j = 0; j < int_value; j++) {
            fprintf(f, "%d,%d ", pl->points[j].x, pl->points[j].y);
        }
        fprintf(f, "\" stroke=\"%s\" fill=\"none\" stroke-width=\"%.1f\" />\n",
            pl->style->stroke_color, pl->style->stroke_width);
        printf(GREEN "Polyligne exportée avec succès!\n" RESET);
    } else {
        printf(YELLOW "Attention: Polyligne sans style ou points détectée, ignorée.\n" RESET);
    }
}


void export_svg(const char *filename, const ShapeList* list) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }

    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"960\" height=\"540\"> \n");

    if (list != NULL) {
        const ShapeNode* current = list->head;
        while (current != NULL) {
            switch (current->type) {
                case SQUARE:
                    export_square(f, current->data.square);
                    break;
                case CIRCLE:
                    export_circle(f, current->data.circle);
                    break;
                case RECTANGLE:
                    export_rectangle(f, current->data.rectangle);
                    break;
                case ELLIPSE:
                    export_ellipse(f, current->data.ellipse);
                    break;
                case LINE:
                    export_line(f, current->data.line);
                    break;
                case POLYGONE:
                    export_polygon(f, current->data.polygone);
                    break;
                case POLYLINE:
                    export_polyline(f, current->data.polyline);
                    break;
                default:
                    printf(RED "Type de forme non reconnu\n" RESET);
                    fclose(f);
                    return;
            }
            current = current->next;
        }
    }

    fprintf(f, "</svg>\n");
    fclose(f);
    printf(GREEN"Export SVG termine : %s\n"RESET, filename);
    buffer_clean();
}