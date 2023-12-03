#include "header.h"
#include "stations.h"
#include <stdlib.h>
#include <stdio.h>

int get_max_stations (Graphe *graphe) {
    int max =0;
    for(int i = 0; i <graphe->ordre; i++) {
        if (graphe->pSommet[i]->station > max) {
            max = graphe->pSommet[i]->station;
        }
    }
    return max;
}

void affichage_station(Graphe *graphe,int tab_pred[]) {

    for(int k =1; k <= get_max_stations(graphe); k++) {
        int taille =1;
        gotoligcol(30+k, 28);
        printf("Station %d : ",k);
        for(int i = 0; i <graphe->ordre; i++) {
            if (graphe->pSommet[tab_pred[i]]->station == k) {
                gotoligcol(30+k, 40+taille);
                printf("%d ",graphe->pSommet[tab_pred[i]]->id);
                taille+=3;
            }
        }
    }
}

void station (Graphe *graphe, int tab_contraintes[],int nb_contraintes) {


    for(int i = 0; i < graphe->ordre; i++) {
        graphe->pSommet[i]->station = 1;
    }

    //-----------------------------------------------------------------------    Contraintes   -------------------------------------------------------------------

    int tab_pred[graphe->ordre];
    for(int i = 0; i < graphe->ordre; i++) {
        tab_pred[i]= i;
      }
    //Contraintes de précédence
        if (tab_contraintes[0] == 1) {
        precedence(graphe, tab_pred, nb_contraintes);}
        //Contraintes d'exclusion
        if (tab_contraintes[1] == 1) {
            exclusion(graphe, tab_pred, nb_contraintes);
        }
        //Contraintes cycle
        if (tab_contraintes[2] == 1) {
            cycle(graphe, tab_pred, nb_contraintes);
        }
        affichage_station(graphe,tab_pred);


}