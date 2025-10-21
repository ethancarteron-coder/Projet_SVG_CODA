#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "suppression.h"
#include "list.h"
#include "modification.h"
#include "utils.h"
#include "shapes.h"
#include "export.h"

int main(void) {
    Shape_list* list = malloc(sizeof(Shape_list));
    if (!list) {
        fprintf(stderr, "Erreur allocation liste\n");
        return 1;
    }
    list->head = NULL;
    list->size = 0;
    list->tail = NULL;

    Style* style = NULL;
    Point origin = {0,0};
    int choice;

    do {
        //system("clear");
        printf("===== MENU PRINCIPAL ===== \n");
        printf("1: Créer/ajouter une forme \n");
        printf("2: Modifier une forme \n");
        printf("3: Supprimer une forme \n");
        printf("4: Lister les formes \n");
        printf("5: Afficher \n");
        printf("0: Quitter\n");
        printf("Votre choix : ");
        choice = read_int();

        switch (choice) {
            case 1: creation_menu(list, origin, style); break;
            case 2: modification_menu(list); break;
            case 3: suppression_menu(list); break;
            case 4: list_shapes(list); break;
            case 5: export_svg("affichage.svg", list, style); break;
            case 0: break;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (choice != 0);
    free(list);
    return 0;
}


void creation_menu(Shape_list* list, Point origin, Style *style) {
    int choice;
    do {
        //system("clear");
        printf ("===== MENU CREATION ===== \n");
        printf ("1: Afficher les formes créées \n");
        printf ("2: créer cercle \n");
        printf ("3: créer ellipse \n");
        printf ("4: créer ligne \n");
        printf ("5: créer rectangle \n");
        printf ("6: créer carré \n");
        printf ("7: créer polygone \n");
        printf ("8: créer polyligne \n");
        printf ("0: revenir au menu \n");
        printf ("Votre choix : ");
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
                printf("Retour au menu principal \n");
                return;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (1);
}


void modification_menu(Shape_list* list) {
    int choice;
    do {
        system("clear");
        printf("1: Déplacer forme \n");
        printf("2: Rotation forme \n");
        printf("3: Symétrie \n");
        printf("4: Changer couleur \n");
        printf("5: Epaisseur \n");
        printf("0: retour au menu\n");
        printf("Votre choix : ");
        choice = read_int();

        switch (choice) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 0:
                printf("Retour au menu principal \n");
                return;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (1);
}


void suppression_menu(Shape_list* list) {
    int choice;
    do {
        system("clear");
        printf("1: Lister forme \n");
        printf("2: supprimer une forme : \n");
        printf("3: Supprimer toutes les formes \n");
        printf("4: Supprimer un groupe \n");
        printf("5: Epaisseur \n");
        printf("0: retour au menu\n");
        printf("Votre choix : ");
        choice = read_int();

        switch (choice) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 0: return;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (1);
}