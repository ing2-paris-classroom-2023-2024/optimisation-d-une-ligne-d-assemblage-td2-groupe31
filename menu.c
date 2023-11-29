#include "header.h"
#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

void menu () {
    gotoxy(20,10);
    FILE *fichier;
    char caractere;

    // Ouvre le fichier en mode lecture
    fichier = fopen("../titre.txt", "r");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
    }

    // Lit et affiche chaque caractère du fichier
    while ((caractere = fgetc(fichier)) != EOF) {
        printf("%c", caractere);
    }

    // Ferme le fichier
    fclose(fichier);
}