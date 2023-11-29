#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "stations.h"

/*int precedence (Graphe *graphe, int num, int compteur) {

    pArc arc= graphe->pSommet[num]->arc;
    while(arc!=NULL)
    {
        if (arc->sommet == 0) { // Si une opération qui précède n'a pas encore été fini, on annule l'opération
            return 1;
        }
        precedence(graphe, arc->sommet,compteur);
        arc=arc->arc_suivant;
    }
    return 0; // Aucune
}*/



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
    int chemins,num = 28, tab[graphe->taille],index,max;
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

void precedence (Graphe *graphe) {
    int tab[graphe->ordre], max = 0;

    trouver_precedence(graphe);

    //On fait un tableau des sommets trier dans l'ordre décroissants
    for (int i  = 0; i < graphe->ordre; i ++) {
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


}