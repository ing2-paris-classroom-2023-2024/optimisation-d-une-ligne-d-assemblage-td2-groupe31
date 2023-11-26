#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
/* affichage des successeurs du sommet num*/
/* affichage des successeurs du sommet num*/
void afficher_successeurs(pPred * sommet, int num)
{

    printf(" sommet %d :\n",num);

    pArc arc=sommet[num]->arc;

    while(arc!=NULL)
    {
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }

}

void graphe_afficher(Graphe *graphe) {
    printf("---------------------- Graphe --------------------------\n");


    printf("ordre = %d\n", graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i = 0; i < graphe->ordre; i++) {
        afficher_successeurs(graphe->pPred, i);
        printf("\n");
    }
}



// Ajouter l'arête entre les sommets s1 et s2 du graphe
pPred *CreerArete(pPred *sommet, int s1, int s2) {
    if (sommet[s1]->arc == NULL) {
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->arc_suivant = NULL;
        sommet[s1]->arc = Newarc;
        return sommet;
    } else {
        pArc temp = sommet[s1]->arc;
        while (!(temp->arc_suivant == NULL)) {
            temp = temp->arc_suivant;
        }
        pArc Newarc = (pArc) malloc(sizeof(struct Arc));
        Newarc->sommet = s2;
        Newarc->arc_suivant = NULL;
        temp->arc_suivant = Newarc;
        return sommet;
    }
}

// créer le graphe
Graphe *CreerGraphe(int ordre) {
    Graphe *Newgraphe = (Graphe *) malloc(sizeof(Graphe));
    Newgraphe->pPred = (pPred *) malloc(ordre * sizeof(pPred));

    for (int i = 0; i <= ordre; i++) {
        Newgraphe->pPred[i] = (pPred) malloc(sizeof(struct Pred));
        Newgraphe->pPred[i]->valeur = i;
        Newgraphe->pPred[i]->arc = NULL;
    }
    return Newgraphe;
}
int trouver_ordre (int *ordre, int *taille ) {
    int s1, s2;
    *ordre = 0;
    *taille = 0;
    FILE *fichier = NULL;
    fichier = fopen("../precedences.txt", "r");
    if (fichier == NULL) {
        printf("erreur");
    }

    while (fscanf(fichier, "%d%d", &s1, &s2) != EOF) {
        *taille +=1;
        if (s1 > *ordre) {
            *ordre = s1;
        } else if (s2 > *ordre) {
            *ordre = s2;
        }
    }
    fclose(fichier);
}

Graphe *lire_graphe(int ordre, int taille) {
    Graphe *graphe;
    int s1, s2;

    graphe = CreerGraphe(ordre); // créer le graphe d'ordre sommets

    graphe->ordre = ordre;
    graphe->taille = taille;

    FILE *fichier = NULL;
    fichier = fopen("../precedences.txt", "r");
    if (fichier == NULL) {
        printf("erreur");
    }
    // créer les arêtes du graphe
    for (int i = 0; i < taille; ++i) {
        fscanf(fichier, "%d%d", &s1, &s2);
        graphe->pPred=CreerArete(graphe->pPred, s2, s1);

    }

    return graphe;
}

Graphe *initGraphe () {
    int ordre, taille;
    Graphe *g;
    trouver_ordre(&ordre, &taille);
    g = lire_graphe(ordre, taille);
    graphe_afficher(g);
    return g;
}