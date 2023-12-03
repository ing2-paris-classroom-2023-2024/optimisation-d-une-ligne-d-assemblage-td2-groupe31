#include "header.h"
#include "stations.h"
#include <stdlib.h>
#include <stdio.h>

void verif_station(Graphe *graphe) {
    for(int i = 0; i <graphe->ordre; i++) {
        if (graphe->pSommet[i]->station == 1) {
            printf("%d ",graphe->pSommet[i]->id);
        }
    }
}

void station (Graphe *graphe, int tab_contraintes[]) {

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

        precedence(graphe, tab_pred);
        operation = usine->station->operation;
        for(int i = 0; i < graphe->ordre; i++) {
            operation->num = graphe->pSommet[tab_pred[i]]->id;
            operation = operation->operation_suvante;
        }
    }

    for(int i = 0; i < graphe->ordre; i ++) {
        printf("%d", graphe->pSommet[tab_pred[i]]->id);
    }
    printf("\n");
    //Contraintes d'exclusion
    if (tab_contraintes[1] == 1) {
        exclusion(usine,graphe, tab_pred);
    }

    verif_station(graphe);
    //Contraintes cycle
    if (tab_contraintes[2] == 1) {
        cycle(graphe);
    }

    //---------------------------------------------------------------------  Afficher les stations  ---------------------------------------------------------------------------

    /*operation = usine->station->operation;
    for(int i = 0; i < graphe->ordre; i++) {
        printf("%d ",operation->num);
        operation = operation->operation_suvante;
    }*/



}