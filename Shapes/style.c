#include <stdlib.h>
#include <string.h>
#include "shapes.h"

Color color_create(unsigned char r, unsigned char g, unsigned char b, float opacity) {
    Color color = {r, g, b};
    return color;
}

Style* attributes_create() {
    Style* style = malloc(sizeof(Style));
    if (style == NULL) return NULL;

    style->stroke_color = color_create(0, 0, 0, 1.0f);
    style->fill_color = color_create(255, 255, 255, 1.0f);
    style->stroke_width = 1.0f;
    style->id = NULL;
    
    return style;
}

void attributes_free(Style* style) {
    if (style == NULL) return;
    free(style->id);
    free(style);
}
