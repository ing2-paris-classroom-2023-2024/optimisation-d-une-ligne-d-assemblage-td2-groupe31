#include "header.h"
#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


void gotoligcol( int lig, int col ) {
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void afficher_menu () {
    int c;
    printf("         %c", 16);

    gotoligcol(13,0);
    printf(""
           "                                                  _____         _    _             _              _               \n"
           "                                                 |  _  |       | |  (_)           (_)            | |              \n"
           "                                                 | | | | _ __  | |_  _  _ __ ___   _  ___   __ _ | |_  ___   _ __ \n"
           "                                                 | | | || '_ \\ | _|| || ' ` _ \\ | |/ __| / _` || __|/ _ \\ | '__|\n"
           "                                                 \\ \\/ /| |_) || | | || | | | | || |\\__ \\| (_| || |_| (_) || |   \n"
           "                                                  \\___/ | .__/  \\__||_||_| |_| |_||_||___/ \\__,_| \\__|\\___/ |_|   \n"
           "                                                        | |                                                       \n"
           "                                                        |_|          ");

    gotoligcol(25, 70);
    printf("Appuyez sur ENTRER...");
    do {
        c = getch();
    } while (c != 13);
    system("cls");
}



void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void chargement () {
    system("cls");
    gotoligcol(15, 66);
    printf("Lancement de la partie en cours : ...");
    // barre de chargement
    int x=20;
    int y = 68;
    int i;

    gotoligcol(x-2, y+11);
    Color(12,0);
    printf("LABYRINTHE");

    Color(15,0);
    gotoligcol(x,y);
    printf("%c", 0xDA);// angle haut gauche
    for(i=0; i<30; i++)
    {
        printf("%c",0xC4); // ligne haut
    }
    printf("%c", 0xBF);// angle haut droit

    gotoligcol(x+1,y);
    printf("%c",0xB3);// coté gauche
    for(i=0; i<30; i++)
    {
        printf(" ");// trou des cases
    }
    printf("%c", 0xB3);// coté droit max 97

    /*gotoligcol(x+2,y);
    printf("%c",0xB3);// coté gauche
    for(i=0; i<30; i++)
    {
        printf(" ");// trou des cases
    }
    printf("%c", 0xB3);// coté droit max 97*/

    gotoligcol(x+2,y);
    printf("%c",0xC0);// angle bas gauche

    for(i=0; i<30; i++)
    {
        printf("%c",0xC4);// ligne bas
    }

    printf("%c",0xD9);// angle bas droit

    for(i = 0; i<30; i++)
    {
        gotoligcol(x+1, y+1+i),
                printf("%c", 0xDB);
        Sleep(107);
    }
    system("cls");

}


void flecheMenu(int x) {
    if (x == 18) {
        Color(12, 0);
        gotoligcol(18, 70);
        printf("%c", 62);
        Color(15, 0);
    } else {
        gotoligcol(18, 70);
        printf("%c", 62);
    }
    if (x == 19) {
        Color(12, 0);
        gotoligcol(19, 70);
        printf("%c", 62);
        Color(15, 0);
    } else {
        gotoligcol(19, 70);
        printf("%c", 62);
    }
    if (x == 20) {
        Color(12, 0);
        gotoligcol(20, 70);
        printf("%c", 62);
        Color(15, 0);
    } else {
        gotoligcol(20, 70);
        printf("%c", 62);
    }
    if (x == 21) {
        Color(12, 0);
        gotoligcol(21, 70);
        printf("%c", 62);
        Color(15, 0);
    } else {
        gotoligcol(21, 70);
        printf("%c", 62);
    }
}

void regles()
{  printf("######  #######  #####  #       #######  #####     ######  #     #          # ####### #     #\n");
    printf("#     # #       #     # #       #       #     #    #     # #     #          # #       #     #\n");
    printf("#     # #       #       #       #       #          #     # #     #          # #       #     # \n");
    printf("######  #####   #  #### #       #####    #####     #     # #     #          # #####   #     # \n");
    printf("#   #   #       #     # #       #             #    #     # #     #    #     # #       #     # \n");
    printf("#    #  #       #     # #       #       #     #    #     # #     #    #     # #       #     # \n");
    printf("#     # #######  #####  ####### #######  #####     ######   #####      #####  #######  #####  \n");

    printf("Le programme que nous avons developpe pour optimiser les lignes d'assemblage, telles que celle de la future voiture electrique ECElecar, est un outil puissant qui prend en compte diverses contraintes inherentes a la fabrication a la chaine.\n");
    printf("Implemente en langage C par notre equipe composee de Theodore Bricout, Evan Siritham, Benoit Quaranta, et Paul Drochon, ce programme offre une solution complete pour la planification et l'optimisation des operations d'assemblage.\n\n");

    printf("Voici les principales fonctionnalites de notre programme :\n");
    printf("Gestion des Stations :\n");
    printf("Le programme peut modeliser n'importe quelle ligne d'assemblage en considerant chaque etape d'assemblage comme une station. Chaque station est capable d'executer une ou plusieurs operations, et le programme prend en compte la flexibilite ou chaque station peut realiser n'importe quelle operation.\n\n");

}

void menuDemarrage() {
    int c = 0, x = 18, tab[3] = {0};
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("                                                                    __  __ _____ _   _ _   _ \n"
           "                                                                   |  \\/  | ____| \\ | | | | |\n"
           "                                                                   | |\\/| |  _| |  \\| | | | |\n"
           "                                                                   | |  | | |___| |\\  | |_| |\n"
           "                                                                   |_|  |_|_____|_| \\_|\\___/");
    gotoligcol(16, 56);
    printf("Utiliser Z et S pour vous deplacer de haut en bas");
    gotoligcol(18, 72);
    printf("Contrainte simple");
    gotoligcol(19, 72);
    printf("Contraintes multiples");
    gotoligcol(20, 72);
    printf("R");
    gotoligcol(21, 72);
    printf("Valider");
    gotoligcol(23, 63);
    printf("Appuyez sur ENTRER pour selectionner...");
    flecheMenu(x);
    do {
        gotoligcol(0,0);
        c = getch();
        if (c == 122) {
            if (x > 18) {
                x -= 1;
                flecheMenu(x);
            } else if (x == 18) {
                x = 21;
                flecheMenu(x);
            }
        } else if (c == 115) {
            if (x < 21) {
                x += 1;
                flecheMenu(x);
            } else if (x == 21) {
                x = 18;
                flecheMenu(x);
            }
        } else if (c == 13) {
            if (x == 18) {
                if (tab[0] == 0) {
                    Color(12, 0);
                    gotoligcol(18, 72);
                    printf("Contrainte simple");
                    tab[0] =1;
                    Color(15, 0);
                } else {
                    Color(15, 0);
                    gotoligcol(18, 72);
                    printf("Contrainte simple");
                    tab[0] = 0;
                }
            } else if (x == 19) {
                if (tab[1] == 0) {
                    Color(12, 0);
                    gotoligcol(19, 72);
                    printf("Contraintes multiples");
                    tab[1] =1;
                    Color(15, 0);
                } else {
                    Color(15, 0);
                    gotoligcol(19, 72);
                    printf("Contraintes multiples");
                    tab[1] = 0;
                }
            } else if (x == 20) {
                if (tab[2] == 0) {
                    Color(12, 0);
                    gotoligcol(20, 72);
                    printf("R");
                    tab[2] =1;
                    Color(15, 0);
                } else {
                    Color(15, 0);
                    gotoligcol(20, 72);
                    printf("R");
                    tab[2] = 0;
                }
            }  else if (x == 21) {
                break;
            }
        }
    } while (1);
    chargement();
    system("cls");
    /*if (x == 18) {
        chargement();
        system("cls");
    } else if (x == 19) {
        chargement();
        system("cls");
    } else if ( x == 20) {
        system("cls");
        c = 0;
        do {
            regles();
            c = getch();
        } while (c != 13);
        system("cls");
        menuDemarrage();
    }*/

}

void menu () {
    afficher_menu();
    menuDemarrage();
}
