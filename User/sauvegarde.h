#ifndef SAUVEGARDE_H
    #define SAUVEGARDE_H

    #include "shapes.h"

    typedef enum {
        FORMAT_SVG,
        FORMAT_BINARY,
        FORMAT_JSON
    } SaveFormat;


    int save_to_file(const char* filename, SaveFormat format, ShapeList* list);
    int load_from_file(const char* filename, SaveFormat format);
    int export_as_svg(const char* filename, ShapeList* list);
    ShapeList* import_from_svg(const char* filename);

#endif