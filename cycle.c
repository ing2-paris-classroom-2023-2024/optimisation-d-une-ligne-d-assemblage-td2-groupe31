#include "header.h"
#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>


void cycle_simple (Graphe *graphe, int tab[]) {
    int verif = 0, i = 0, station = 1;
    float somme = 0;
    //Tri par ordre décroissant
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
                    graphe->pSommet[tab[i]]->station = station;
                    tab[i] = graphe->ordre + 1;
                }
            }
            i++;
        } while (i < graphe->ordre);
        gotoligcol(30+station, 110);
        printf("Duree: %f \n",somme);
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

}

void cycle_multiples (Graphe *graphe, int tab[], int tab_pred[]) {
    for(int j = 0; j <= get_max_stations (graphe); j++) {
        for(int i =0; i < graphe->ordre; i ++) {
            
            if (graphe->pSommet[tab_pred[i]]->station == j) {

            }
        }
    }
}
void cycle (Graphe *graphe,int tab[], int nb_contraintes) {
    printf("\n");
    int i = 0,verif =0, station = 0, station_transite[graphe->ordre],n;
    float somme = 0;
    for(int j = 0; j < graphe->ordre; j++) {
        station_transite[j] = 0;
    }
    if (nb_contraintes == 1) {
        cycle_simple(graphe,tab);
    } else {
        for(int j = 1; j <= get_max_stations(graphe);j++) {
            //Réalocation des stations
            for(int k = 0; k < graphe->ordre; k++) {
                if (graphe->pSommet[tab[k]]->station == j){
                    //printf("%d ",graphe->pSommet[tab[k]]->id);
                    if (graphe->pSommet[tab[k]]->duree + somme <= graphe->cycle ) {
                        //printf("%d ",graphe->pSommet[tab[k]]->id);
                        somme += graphe->pSommet[tab[k]]->duree;
                    } else {
                        station_transite[i] = tab[k];
                        //printf("%d(t) ",graphe->pSommet[tab[k]]->id);
                        i++;
                    }
                }
            }
            gotoligcol(30+j, 100);
            printf("Duree: %f \n",somme);
            for(int k =0; k < i; k++) {
                n=0;
                do {
                    n++;
                    verif =1;
                    //Vérifier qu'il n'y aucune contrainte d'exclusion pendant la réalocation
                    pExclusion exclusion = graphe->pSommet[station_transite[k]]->exclusion;
                    while (exclusion != NULL){
                        for(int l = 0; l < graphe->ordre; l++) {
                            if (graphe->pSommet[tab[l]]->station == j+n) {
                                if (exclusion->sommet == tab[l]) {
                                    //printf("exclu %d ",exclusion->sommet);
                                    verif = 0;
                                    break;
                                }
                            }
                        }
                        exclusion = exclusion->ex_suivant;
                    }
                } while (verif == 0);
                graphe->pSommet[station_transite[k]]->station = j+n;
                station_transite[k] =0;
            }
            i=0;
            somme = 0;

        }

    }
}





