#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "list.h"
#include "modification.h"
#include "utils.h"
#include "shapes.h"
#include "export.h"

int main(void) {
    Shape_list* list = malloc(sizeof(Shape_list));
    if (!list) {
        printf(RED"Erreur allocation liste\n"RESET);
        return 1;
    }

    list->head = NULL;
    list->size = 0;
    list->tail = NULL;

    Style* style = NULL;
    Point origin = {0,0};
    int choice;

    do {
        system("clear");
        printf(BLUE"===== MENU PRINCIPAL ===== \n" RESET);
        printf("1: Créer/ajouter une forme \n");
        printf("2: Modifier une forme \n");
        printf("3: Lister les formes \n");
        printf("4: Afficher \n");
        printf("0: Quitter\n");
        printf(BLUE"Votre choix : " RESET);
        choice = read_int();

        switch (choice) {
            case 1: creation_menu(list, origin, style); break;
            case 2: modification_menu(list); break;
            case 3: list_shapes(list); break;
            case 4: export_svg("affichage.svg", list, style); break;
            case 0: break;
            default: printf(RED"Choix invalide, veuillez réessayer.\n"RESET); break;
        }
    } while (choice != 0);
    free(list);
    return 0;
}


void creation_menu(Shape_list* list, Point origin, Style *style) {
    int choice;
    do {
        system("clear");
        printf (BLUE "===== MENU CREATION ===== \n" RESET);
        printf ("1: Afficher les formes créées \n");
        printf ("2: créer cercle \n");
        printf ("3: créer ellipse \n");
        printf ("4: créer ligne \n");
        printf ("5: créer rectangle \n");
        printf ("6: créer carré \n");
        printf ("7: créer polygone \n");
        printf ("8: créer polyligne \n");
        printf ("0: revenir au menu \n");
        printf (BLUE "Votre choix : " RESET);
        choice = read_int();

        switch (choice) {
            case 1: export_svg("affichage.svg", list, style); break;
            case 2: ask_circle(list, origin, style); break;
            case 3: ask_ellipse(list, origin); break;
            case 4: ask_line(list, origin, origin); break;
            case 5: ask_rectangle(list, origin); break;
            case 6: ask_square(list, origin); break;
            case 7: ask_polygone(list, origin); break;
            case 8: ask_polyline(list, origin); break;
            case 0:
                printf(BLUE "Retour au menu principal \n" RESET);
                return;
            default: printf(RED"Choix invalide, veuillez réessayer.\n"RESET); break;
        }
    } while (1);
}


void modification_menu(Shape_list* list) {
    int choice;
    do {
        system("clear");
        printf (BLUE "===== MENU MODIFICATION ===== \n" RESET);
        printf("1: Déplacer forme \n");
        printf("2: Rotation forme \n");
        printf("3: Symétrie \n");
        printf("4: Modifier le style \n");
        printf("0: retour au menu\n");
        printf(BLUE "Votre choix : " RESET);
        choice = read_int();

        switch (choice) {
        case 1:
            printf("Veuillez indiquer le déplacement en x : "); int dx = read_int();
            printf("Veuillez indiquer le déplacement en y : "); int dy = read_int();
            deplace_shape(list, dx, dy);
            break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 0:
            printf(BLUE"Retour au menu principal\n" RESET);
            return;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
            break;
    }
    printf("\nAppuyez sur Entrée pour continuer...");
    getchar();
    } while (1);
}