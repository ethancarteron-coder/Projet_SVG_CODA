#ifndef SHAPES_H
    #define SHAPES_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>


    typedef struct {
        unsigned char r, g, b;

    } Color;

    typedef struct {
        Color stroke_color;
        Color fill_color;
        float stroke_width;
        char* id;
    } Style;

    Color color_create(unsigned char r, unsigned char g, unsigned char b, float opacity);
    Style* attributes_create(void);
    void attributes_free(Style* style);
    
    extern int nb_forme;
    
    typedef struct {
        int x;
        int y;
    } Point;
    
    typedef struct {
        double angle;
        int dx;
        int dy;
        bool flip_x;
        bool flip_y;
    } Transform;



    typedef struct {
        Point center;
        int radius;
        Style* style;
        Transform transform;
    } Circle;

    typedef struct {
        Point center;
        int radius_x;
        int radius_y;
        Style* style;
        Transform transform;
    } Ellipse;



    typedef struct {
        Point start;
        Point end;
        Style* style;
        Transform transform;
    } Line;



    typedef struct {
        Point origin;
        int lenght;
        int width;
        Style* style;
        Transform transform;
    } Rectangle;



    typedef struct {
        Point origin;
        int side;
        Style* style;
        Transform transform;
    } Square;



    typedef struct {
        size_t nb_points;
        Point *points;
        Style* style;
        Transform transform;
    } Polyline;



    typedef struct {
        size_t nb_points;
        Point* points;
        Style* style;
        Transform transform;
    } Polygone;

    typedef enum {
        MOVE_TO,
        LINE_TO,
        CURVE_TO,
        CLOSE_PATH
    }PathCommandType;

    typedef struct {
        PathCommandType type;
        Point* points;
        int num_points;
    } PathCommand;

    typedef struct {
        PathCommand* commands;
        size_t num_commands;
        size_t capacity;
        Style style;
    } Path;


    typedef union {
        Circle* circle;
        Ellipse* ellipse;
        Line* line;
        Rectangle* rectangle;
        Square* square;
        Polygone* polygone;
        Polyline* polyline;
        Path* path;
    } Shapes_data;



    typedef enum {
        UNKNOWN = 0,
        CIRCLE,
        ELLIPSE,
        LINE,
        RECTANGLE,
        SQUARE,
        POLYGONE,
        POLYLINE,
        PATH,
        GROUP
    } Shapes_type;



    typedef struct{
        Shapes_data data;
        Shapes_type type;
        struct ShapeNode* next;
        struct ShapeNode* prev;
    }Shape_node;

    typedef struct {
        Shape_node* head;
        Shape_node* tail;
        int size;
    } ShapeList;

    typedef struct {
        ShapeList* shapes;
        Style style;
        char* id;
    } Group;



    Group* group_create(void);
    void free_group(Group* group);
    int group_add_element(Group* group, void* element, int is_group);
    int group_remove_element(Group* group, void* element);
    void group_apply_attributes(Group* group, Style* style);
    void group_transform(Group* group);


    Circle* circle_info(Point center, int radius);
    void free_circle (Circle* sq);
    Ellipse* ellipse_info(Point center, int radius_x, int radius_y);
    void free_ellipse(Ellipse* el);
    Line* line_info (Point start, Point end);
    void free_line (Line* li);
    Rectangle* rectangle_info(Point origin, int lenght, int width);
    void free_rectangle (Rectangle* re);
    Square* square_info(Point origin, int side);
    void free_square (Square* sq);
    Polyline* polyline_info(Point* point, int nb_points);
    void free_polyline(Polyline* pl);
    Polygone* polygone_info(Point* point, int nb_points);
    void free_polygone(Polygone* pg);


    Path* path_create(void);
    void path_free(Path* path);


    int path_move_to(Path* path, Point p);
    int path_line_to(Path* path, Point p);
    int path_curve_to(Path* path, Point cp1, Point cp2, Point end);
    int path_close(Path* path);


    int path_add_command(Path* path, PathCommandType type, Point* points, int num_points);
#endif