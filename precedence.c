#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#define MAX_SOMMETS 34

int precedence (Graphe *graphe, int num, int compteur) {

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
}



/* Fonction récursive pour trouver tous les chemins */
void trouver_chemins(Graphe* graphe, int num, int visite[], int chemin[], int index) {
    pArc arc= graphe->pSommet[num]->arc;
    while(arc!=NULL)
    {
        precedence(graphe, arc->sommet,compteur);
        arc=arc->arc_suivant;
    }
}

/* Fonction principale pour trouver tous les chemins */
void tous_les_chemins(Graphe* graphe, int depart, int arrivee) {
    int visite[MAX_SOMMETS] = {0};
    int chemin[MAX_SOMMETS];
    int index = 0;

    trouver_chemins(graphe, depart, visite, chemin, index);
}
