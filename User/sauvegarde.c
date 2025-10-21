// sauvegarde.c
#include <stdio.h>
#include <stdlib.h>
#include "sauvegarde.h"
#include "shapes.h"

int save_file(const char* filename, SaveFormat format, Shape_list* list) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) return -1;
    switch (format) {
        case FORMAT_SVG:
            fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
            if (list) {
                for (Shape_node* node = list->head; node; node = node->next) {
                    // TODO: sérialiser chaque forme selon son type
                }
            }
            fprintf(f, "</svg>\n");
            break;
        case FORMAT_BINARY:
            // TODO: Écriture binaire des structures
            break;
        case FORMAT_JSON:
            fprintf(f, "{\n  \"shapes\": [\n");
            if (list) {
                for (Shape_node* node = list->head; node; node = node->next) {
                    // TODO: sérialiser chaque forme en JSON
                }
            }
            fprintf(f, "  ]\n}\n");
            break;
    }
    fclose(f);
    return 0;
}

int export_as_svg(const char* filename, Shape_list* list) {
    return save_file(filename, FORMAT_SVG, list);
}