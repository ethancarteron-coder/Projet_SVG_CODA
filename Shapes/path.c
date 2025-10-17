#include <stdlib.h>
#include <string.h>
#include "shapes.h"

Path* path_create(void) {
    Path* path = malloc(sizeof(Path));
    if (path == NULL) return NULL;
    
    path->commands = NULL;
    path->num_commands = 0;
    path->capacity = 0;
    path->style = *attributes_create();
    
    return path;
}

static int ensure_capacity(Path* path) {
    if (path->num_commands >= path->capacity) {
        size_t new_cap = path->capacity == 0 ? 4 : path->capacity * 2;
        PathCommand* new_cmds = realloc(path->commands, new_cap * sizeof(PathCommand));
        if (new_cmds == NULL) return -1;
        
        path->commands = new_cmds;
        path->capacity = new_cap;
    }
    return 0;
}

int path_add_command(Path* path, PathCommandType type, Point* points, int num_points) {
    if (path == NULL || points == NULL) return -1;
    if (ensure_capacity(path) != 0) return -1;
    
    PathCommand* cmd = &path->commands[path->num_commands];
    cmd->type = type;
    cmd->num_points = num_points;
    
    cmd->points = malloc(num_points * sizeof(Point));
    if (cmd->points == NULL) return -1;
    
    memcpy(cmd->points, points, num_points * sizeof(Point));
    path->num_commands++;
    
    return 0;
}

int path_move_to(Path* path, Point p) {
    return path_add_command(path, MOVE_TO, &p, 1);
}

int path_line_to(Path* path, Point p) {
    return path_add_command(path, LINE_TO, &p, 1);
}

int path_curve_to(Path* path, Point cp1, Point cp2, Point end) {
    Point points[3] = {cp1, cp2, end};
    return path_add_command(path, CURVE_TO, points, 3);
}

int path_close(Path* path) {
    Point dummy = {0, 0};
    return path_add_command(path, CLOSE_PATH, &dummy, 0);
}

void path_free(Path* path) {
    if (path == NULL) return;
    
    for (size_t i = 0; i < path->num_commands; i++) {
        free(path->commands[i].points);
    }
    free(path->commands);
    free(path);
}