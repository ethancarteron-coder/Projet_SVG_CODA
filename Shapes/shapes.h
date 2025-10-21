#ifndef SHAPES_H
    #define SHAPES_H

    
    #define WHITE  "\033[1;37m"
    #define BLACK  "\033[1;30m"
    #define RED    "\033[1;31m"
    #define BLUE   "\033[1;34m"
    #define GREEN  "\033[1;32m"
    #define YELLOW "\033[1;33m"
    #define RESET  "\033[1;0m"

    
    #include <stdio.h>
    #include <stdbool.h>

    typedef struct {
        char* stroke_color;
        char* fill_color;
        float stroke_width;
        char* id;
    } Style;

    Style* style_info(const char* stroke_color, const char* fill_color, float stroke_width);
    void free_style(Style* style);
    
    extern int nb_forme;
    
    typedef struct {
        int x;
        int y;
    } Point;
    
    typedef struct {
        double angle;
        int dx;
        int dy;
        bool symetry_x;
        bool symetry_y;
    } Modif;



    typedef struct {
        Point center;
        int radius;
        Style* style;
        Modif modif;
    } Circle;

    typedef struct {
        Point center;
        int radius_x;
        int radius_y;
        Style* style;
        Modif modif;
    } Ellipse;



    typedef struct {
        Point start;
        Point end;
        Style* style;
        Modif modif;
    } Line;



    typedef struct {
        Point origin;
        int lenght;
        int width;
        Style* style;
        Modif modif;
    } Rectangle;



    typedef struct {
        Point origin;
        int side;
        Style* style;
        Modif modif;
    } Square;



    typedef struct {
        size_t nb_points;
        Point* points;
        Style* style;
        Modif modif;
    } Polyline;



    typedef struct {
        size_t nb_points;
        Point* points;
        Style* style;
        Modif modif;
    } Polygone;



    typedef union {
        Circle* circle;
        Ellipse* ellipse;
        Line* line;
        Rectangle* rectangle;
        Square* square;
        Polygone* polygone;
        Polyline* polyline;
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
        GROUP
    } Shapes_type;



    typedef struct{
        Shapes_data data;
        Shapes_type type;
        struct Shape_node* next;
        struct Shape_node* prev;
    }Shape_node;

    typedef struct {
        Shape_node* head;
        Shape_node* tail;
        int size;
    } Shape_list;


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
    Polyline* polyline_info(const Point* point, int nb_points);
    void free_polyline(Polyline* pl);
    Polygone* polygone_info(const Point* point, int nb_points);
    void free_polygone(Polygone* pg);

#endif