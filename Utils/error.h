#ifndef ERROR_H
    #define ERROR_H

    typedef enum {
        ERR_NONE = 0,
        ERR_MEMORY,
        ERR_INVALID_PARAMETER,
        ERR_FILE_IO,
        ERR_SHAPE_NOT_FOUND,
        ERR_VIEWPORT_OVERFLOW,
        ERR_UNSUPPORTED_SHAPE,
        ERR_UNSUPPORTED_COLOR,
        ERR_GROUP_NOT_FOUND,
        ERR_INVALID_TRANSFORM
    } ErrorCode;

    // Structure pour stocker les informations d'erreur
    typedef struct {
        ErrorCode code;
        const char* message;
        const char* file;
        int line;
    } ErrorInfo;

    // Initialise le système de gestion d'erreurs
    void error_init(void);

    // Définit l'erreur courante
    void error_set(ErrorCode code, const char* message, const char* file, int line);

    // Récupère l'erreur courante
    ErrorInfo* error_get(void);

    // Efface l'erreur courante
    void error_clear(void);

    // Macro pour faciliter la gestion des erreurs
    #define SET_ERROR(code, message) error_set(code, message, __FILE__, __LINE__)

#endif