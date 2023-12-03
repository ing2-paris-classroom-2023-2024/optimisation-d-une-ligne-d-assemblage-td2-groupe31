#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "stations.h"
#define MAX_OPERATIONS 35

// Structure pour représenter une paire d'opérations incompatibles
typedef struct {
    int op1;
    int op2;
} Exclusion;

void creergroupe(Exclusion *exclusions, int numExclusions,Graphe *graphe) {
    int groups[MAX_OPERATIONS] = {0}; // init tous à 0
    int colors[MAX_OPERATIONS] = {0}; // Tab pour stocker les couleurs

    for (int op = 1; op <= MAX_OPERATIONS; ++op) {
        // Vérifier les couleurs déjà attribuées
        for (int i = 0; i < numExclusions; ++i) {
            if (exclusions[i].op1 == op) {
                colors[op - 1] |= (1 << (groups[exclusions[i].op2 - 1] - 1));
            } else if (exclusions[i].op2 == op) {
                colors[op - 1] |= (1 << (groups[exclusions[i].op1 - 1] - 1));
            }
        }


        int color = 1;
        while (colors[op - 1] & (1 << (color - 1))) {
            color++;
        }

        groups[op - 1] = color;

        for (int i = 0; i < numExclusions; ++i) {
            if (exclusions[i].op1 == op) {
                colors[exclusions[i].op2 - 1] |= (1 << (color - 1));
            } else if (exclusions[i].op2 == op) {
                colors[exclusions[i].op1 - 1] |= (1 << (color - 1));
            }
        }
    }

    // Afficher les résultats
    for (int i = 0; i < graphe->ordre; ++i) {
        printf("Operation %d dans le groupe %d\n", i + 1, groups[i]);
    }
}

void delete_successeurs(Graphe *graphe,pArc arc,int num) {
    while (arc != NULL ) {
        graphe->pSommet[arc->sommet]->station = num+1;
        //printf("%d ",graphe->pSommet[arc->sommet]->id);
        delete_successeurs(graphe,graphe->pSommet[arc->sommet]->arc,num);
        arc = arc->arc_suivant;
    }
}

int get_nb (Graphe *graphe,int num, int nb) {
    for(int i = 0; i < graphe->ordre; i ++) {
        if (graphe->pSommet[i]->station == num) {
            nb ++;
        }
    }
    return nb;
}

int get_value (Graphe *graphe, int tab_pred[], int num) {
    for (int i =0; i < graphe->ordre; i++){
        if (tab_pred[i] == num) {
            return i;
        }
    }
}
int placer_exclusions (Graphe *graphe, int tab_pred[],int num) {

    for(int i = 0; i < graphe->ordre; i++) {
        if (graphe->pSommet[tab_pred[i]]->station == num) {
            //printf("%d ",graphe->pSommet[tab_pred[i]]->id);
            pExclusion exclu =graphe->pSommet[tab_pred[i]]->exclusion;
            while(exclu!=NULL)
            {
                if(get_value(graphe,tab_pred,i) < get_value(graphe,tab_pred,exclu->sommet) && graphe->pSommet[exclu->sommet]->station == num) {
                    graphe->pSommet[exclu->sommet]->station = num +1;
                    //printf("%d ",graphe->pSommet[exclu->sommet]->id);
                    pArc arc = graphe->pSommet[exclu->sommet]->arc;
                    delete_successeurs(graphe,arc,num);
                }
                exclu =exclu->ex_suivant;
            }
        }
    }

}

int exclusion(Usine *usine, Graphe *graphe, int tab_pred[]) {
    // Définir les contraintes d'exclusion
    int a,b,i, fin, j =0;

    //Tableau dynamique des contraintes d'exclusions
   /* Exclusion* temp = (Exclusion*)malloc(graphe->nb_exclusions * sizeof(Exclusion));
    Exclusion* temp2= (Exclusion*)malloc(graphe->nb_exclusions * sizeof(Exclusion));

    FILE *fichier = NULL;
    fichier = fopen("../exclusions.txt", "r");
    if (fichier == NULL) {
        printf("erreur");
    }

    while (fscanf(fichier, "%d %d", &a, &b) == 2) {
        i = 0, fin = 0;
        do {
            if (a == graphe->pSommet[i]->id) {
                a = i;
                fin++;
            }
            if (b == graphe->pSommet[i]->id) {
                b = i;
                fin++;
            }
            i++;
        } while (fin !=2);
        temp[j].op1 = a;
        temp[j].op2 = b;
        temp2[j].op1 = a;
        temp2[j].op2 = b;
        j++;

    }
    fclose(fichier);
    int c = 0;
    Exclusion* exclusions= (Exclusion*)malloc(graphe->nb_exclusions * sizeof(Exclusion));

    for (int k = 0; k < graphe->ordre; k ++) {
        for(int l = 0; l < graphe->nb_exclusions; l ++) {
            if (temp[l].op1 == tab_pred[k] ) {
                exclusions[c].op1 = temp[l].op1;
                exclusions[c].op2 = temp[l].op2;
                c++;
            }
        }
    }

    */

    int num = 1, nb =0;

    // Créer les groupes en respectant les contraintes d'exclusion
    do {
        placer_exclusions(graphe,tab_pred,num);
        nb = get_nb(graphe,num,nb);
        num +=1;
    }  while (nb < graphe->ordre);
    //creergroupe(exclusions, graphe->nb_exclusions,graphe);
    return 0;

}