#include <stdlib.h>
#include <string.h>
#include "shapes.h"

Style* style_info(const char* stroke_color, const char* fill_color, float stroke_width) {
    Style* style = malloc(sizeof(Style));
    if (style == NULL) return NULL;

    if (stroke_color != NULL) {
        style->stroke_color = malloc(strlen(stroke_color) + 1);
        if (style->stroke_color) strcpy(style->stroke_color, stroke_color);
    } else {
        style->stroke_color = NULL;
    }

    if (fill_color != NULL) {
        style->fill_color = malloc(strlen(fill_color) + 1);
        if (style->fill_color) strcpy(style->fill_color, fill_color);
    } else {
        style->fill_color = NULL;
    }

    style->stroke_width = stroke_width;
    style->id = NULL;
    
    return style;
}

void free_style(Style* style) {
    if (style == NULL) return;
    free(style->stroke_color);
    free(style->fill_color);
    free(style->id);
    free(style);
}
