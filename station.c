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

    //--------------------------------------------------------------------   Initialisation   --------------------------------------------------------------
    Usine *usine = (Usine *) malloc(sizeof(Usine));
    pStation station0 = (pStation) malloc(sizeof(struct Station));
    pOperation operation0 = (pOperation) malloc(sizeof (struct Operation));
    station0->station_suivant = NULL;
    operation0->num = 0;
    operation0->operation_suvante = NULL;
    station0->operation = operation0;
    station0->num = 0;
    usine->station = station0;

    pOperation operation = usine->station->operation;
    for(int i = 0; i < graphe->ordre; i++) {
        pOperation temp = usine->station->operation;
        while (!(temp->operation_suvante == NULL)) {
            temp = temp->operation_suvante;
        }
        pOperation Newop = (pOperation) malloc(sizeof(struct Operation));
        Newop->num = i;
        Newop->operation_suvante = NULL;
        temp->operation_suvante = Newop;
        graphe->pSommet[i]->station = 1;
    }

    //-----------------------------------------------------------------------    Contraintes   -------------------------------------------------------------------

    int tab_pred[graphe->ordre];
    //Contraintes de précédence
    if (tab_contraintes[0] == 1) {
        precedence(graphe, tab_pred, nb_contraintes);
        //Contraintes d'exclusion
        if (tab_contraintes[1] == 1) {
            exclusion(usine, graphe, tab_pred, nb_contraintes);
        }
        //Contraintes cycle
        if (tab_contraintes[2] == 1) {
            cycle(graphe, tab_pred, nb_contraintes);
        }

        affichage_station(graphe,tab_pred);
    }

}