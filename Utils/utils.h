#ifndef UTILS_H
    #define UTILS_H
    
    #include <stdbool.h>
    

    #define WHITE  "\033[1;37m"
    #define BLACK  "\033[1;30m"
    #define RED    "\033[1;31m"
    #define BLUE   "\033[1;34m"
    #define GREEN  "\033[1;32m"
    #define YELLOW "\033[1;33m"
    #define RESET  "\033[1;0m"

    int read_int();

    void buffer_clean();

    bool hexadecimal(const char* character);

    bool standard_color (const char* character);

    bool read_color(const char* character);

    bool seize_color(char* buffer, int buflen, char* message);

#endif