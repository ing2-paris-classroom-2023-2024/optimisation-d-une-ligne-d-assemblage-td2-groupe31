#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "stations.h"


// Fonction récursive pour trouver tous les chemins
void trouver_chemins(Graphe* graphe, int num, int chemins,int tab[],int index) {
    pArc arc= graphe->pSommet[num]->arc;
    if (arc != NULL){
        if (index != 0 & arc->arc_suivant!=NULL) {
            index++;
        }
        while(arc!=NULL)
        {
            trouver_chemins(graphe, arc->sommet,chemins+1,tab,index);
            arc=arc->arc_suivant;
            if (arc != NULL) {
                index ++;
            }
        }
    }
    else {
        tab[index] = chemins;
    }
}

// Fonction principale pour trouver tous les chemins
void trouver_precedence(Graphe* graphe) {
    int chemins, tab[graphe->taille],index,max;
    for(int i = 0; i < graphe->ordre; i ++) {
        chemins = 0, index = 0, max = 0;

        for(int j = 0; j < graphe->taille; j ++) {
            tab[j] = 0;
        }
        trouver_chemins(graphe, i, chemins,tab, index);

        //on garde le plus long chemin à chaque fois
        for (int k = 0; k < graphe->taille; k ++) {
            if (tab[k] > max && tab[k] < graphe->taille) {
                max = tab[k];
            }
        }
        graphe->pSommet[i]->precedence = max;
    }
}

void precedence (Graphe *graphe, int tab[]) {


    trouver_precedence(graphe);

    // On fait un tableau des sommets triés dans l'ordre décroissant
    for (int i = 0; i < graphe->ordre; i++) {
        tab[i] = i;
    }
    for (int i = 0; i < graphe->ordre - 1; i++) {
        for (int j = 0; j < graphe->ordre - i - 1; j++) {
            if (graphe->pSommet[tab[j]]->precedence < graphe->pSommet[tab[j+1]]->precedence) {
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < graphe->ordre; i++) {
        //printf("%d|%d ",graphe->pSommet[tab[i]]->id,graphe->pSommet[tab[i]]->precedence);
    }

    //Trier le tableau en fonction des durée pour optimiser la répartition des stations
    for (int i = 0; i < graphe->ordre - 1; i++) {
        for (int j = 0; j < graphe->ordre - i - 1; j++) {
            if (graphe->pSommet[tab[j]]->duree < graphe->pSommet[tab[j+1]]->duree) {
                if (graphe->pSommet[tab[j]]->precedence == graphe->pSommet[tab[j+1]]->precedence) {
                    int temp = tab[j];
                    tab[j] = tab[j+1];
                    tab[j+1] = temp;
                }
            }
        }
    }






}