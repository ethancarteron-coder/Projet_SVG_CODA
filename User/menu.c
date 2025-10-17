#include <stdio.h>
#include <stdlib.h>
#include "creation.h"
#include "suppression.h"
#include "utils.h"
#include "shapes.h"
#include "export.h"


int main () {

    ShapeList* list = malloc(sizeof(ShapeList));
    list->head = NULL;
    list->size = 0;
    list->tail = NULL;

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
        printf("Votre choix : "), choice = read_int(5);

        switch (choice) {
            case 1: creation_menu(list); break;
            case 2: modification_menu(list); break;
            case 3: suppression_menu(list);break;
            case 4: list_shapes(list); break;
            case 5: export_svg("affichage.svg",list); break;
            case 0: break;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (choice != 0);
}


void creation_menu (ShapeList* list) {
    int choice;
    do {
        //system("clear");
        printf ("===== MENU CREATION ===== \n");
        printf ("1: Afficher les formes créées \n");
        printf ("2: créer cerlce \n");
        printf ("3: créer ellipse \n");
        printf ("4: créer ligne \n");
        printf ("5: créer rectangle \n");
        printf ("6: créer carré \n");
        printf ("7: créer polygone \n");
        printf ("8: créer polyligne \n");
        printf ("0: revenir au menu \n");
        printf ("Votre choix : "), choice = read_int(8);

        switch (choice) {
            case 1: export_svg("affichage.svg", list); break;
            case 2: ask_circle(list); break;
            case 3: ask_ellipse(); break;
            case 4: ask_line(); break;
            case 5: ask_rectangle(); break;
            case 6: ask_square(); break;
            case 7: ask_polygone(); break;
            case 8: ask_polyline(); break;
            case 0:
                printf("Retour au menu principal \n");
                main(list); break;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (choice != 0);

}


int modification_menu (ShapeList* list) {
    int choice;
    do {
        system("clear");
        printf("1: Déplacer forme \n");
        printf("2: Rotation forme \n");
        printf("3: Symétrie \n");
        printf("4: Changer couleur \n");
        printf("5: Epaisseur \n");
        printf("0: retour au menu\n");
        printf("Votre choix : "), choice = read_int(5);

        switch (choice) {
            case 1: break;
            case 2: break;
            case 3: symetry(); break;
            case 4: break;
            case 5: break;
            case 0:
                printf("Retour au menu principal \n");
                main(list); break;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (choice != 0);
}

int suppression_menu() {
    int choice;
    do {
        system("clear");
        printf("1: Lister forme \n");
        printf("2: supprimer une forme : \n");
        printf("3: Supprimer toutes les formes \n");
        printf("4: Supprimer un groupe \n");
        printf("5: Epaisseru \n");
        printf("0: retour au menu\n");
        printf("Votre choix : "), choice = read_int(5);

        switch (choice) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 0: break;
            default: printf("Choix invalide, veuillez réessayer.\n"); break;
        }
    } while (choice != 0);
}
