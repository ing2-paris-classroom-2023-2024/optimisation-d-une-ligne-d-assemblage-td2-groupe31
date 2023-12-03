#include "header.h"
#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>

void cycle (Graphe *graphe) {
    int tab[graphe->ordre], verif = 0, i = 0, station = 0;
    float somme = 0;
    for (int i = 0; i < graphe->ordre; i++) {
        tab[i] = i;
    }
    for (int i = 0; i < graphe->ordre - 1; i++) {
        for (int j = 0; j < graphe->ordre - i - 1; j++) {
            if (graphe->pSommet[tab[j]]->duree < graphe->pSommet[tab[j + 1]]->duree) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    do {
        do {

            if(tab[i] !=graphe->ordre + 1 ) {
                if (graphe->pSommet[tab[i]]->duree + somme <= graphe->cycle) {
                    somme += graphe->pSommet[tab[i]]->duree;
                    tab[i] = graphe->ordre + 1;
                }
            }
            i++;
        } while (i < graphe->ordre);
        printf("somme : %f\n", somme);
        i=0;
        somme = 0;
        station++;
        verif = 1;
        for (int i = 0; i < graphe->ordre; i++) {
            if (tab[i] != graphe->ordre + 1) {
                verif = 0;
            }
        }
    } while (verif == 0);

    printf("nb station : %d ", station);
}





