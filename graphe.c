#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
/* affichage des successeurs du sommet num*/
/* affichage des successeurs du sommet num*/
void afficher_successeurs(pSommet * sommet, int num)
{

    printf(" sommet %d :\n",sommet[num]->id);

    pArc arc=sommet[num]->arc;

    while(arc!=NULL)
    {
        printf("%d ",sommet[arc->sommet]->id);
        arc=arc->arc_suivant;
    }

}

void graphe_afficher(Graphe *graphe) {
    printf("---------------------- Graphe --------------------------\n");

    printf("ordre = %d\n", graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i = 0; i < graphe->ordre; i++) {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }
}



// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet *CreerArete(pSommet *sommet, int s1, int s2) {
    int i = 0,fin =0;
    do {
        if (s1 == sommet[i]->id) {
            s1 = i;
            fin++;
        }
        if (s2 == sommet[i]->id) {
            s2 = i;
            fin++;
        }
        i++;
    } while (fin !=2);
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
    FILE *fichier;
    char caractere;
    fichier = fopen("../operations.txt", "r");

    Graphe *Newgraphe = (Graphe *) malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet *) malloc(ordre * sizeof(pSommet));

    for (int i = 0; i < ordre; i++) {
        Newgraphe->pSommet[i] = (pSommet) malloc(sizeof(struct Sommet));
        fscanf(fichier,"%d", &Newgraphe->pSommet[i]->id);
        caractere = fgetc(fichier);
        while (caractere != '\n') {
            caractere = fgetc(fichier);
        }
        Newgraphe->pSommet[i]->arc = NULL;
    }
    fclose(fichier);
    return Newgraphe;
}
int trouver_ordre (int *ordre ) {
    FILE *fichier;
    char caractere;
    int nb = 0;
    fichier = fopen("../operations.txt", "r");

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    // Compter le nombre de lignes
    while ((caractere = fgetc(fichier)) != EOF) {
        if (caractere == '\n') {
            nb++;
        }
    }
    fclose(fichier);
    *ordre = nb;
}

void lire_precedence (Graphe* graphe) {
    int s1, s2;
    FILE *fichier = NULL;
    fichier = fopen("../precedences.txt", "r");
    if (fichier == NULL) {
        printf("erreur");
    }
    // créer les arêtes du graphe
    for (int i = 0; i < graphe->taille; ++i) {
        fscanf(fichier, "%d%d", &s1, &s2);
        graphe->pSommet=CreerArete(graphe->pSommet, s2, s1);

    }
    fclose(fichier);
}

void lire_cycle (Graphe *graphe) {
    int tmp;
    FILE *fichier = NULL;
    fichier = fopen("../operations.txt", "r");
    if (fichier == NULL) {
        printf("erreur");
    }
    for(int i = 0; i < graphe->ordre; i++) {
        fscanf(fichier,"%d", &tmp);
        fscanf(fichier,"%f", &graphe->pSommet[i]->duree);
    }
    fclose(fichier);

}


Graphe *lire_graphe(int ordre, int taille) {
    Graphe *graphe;
    graphe = CreerGraphe(ordre); // créer le graphe d'ordre sommets
    graphe->ordre = ordre;
    graphe->taille = taille;
    lire_precedence(graphe);
    lire_cycle(graphe);
    return graphe;
}

int trouver_taille () {
    int s1, s2, taille = 0;
    FILE *fichier = NULL;
    fichier = fopen("../precedences.txt", "r");
    if (fichier == NULL) {
        printf("erreur");
    }

    while (fscanf(fichier, "%d%d", &s1, &s2) != EOF) {
        taille +=1;
    }
    fclose(fichier);
    return taille;
}

void afficher_duree (Graphe *graphe) {
    for(int i = 0; i < graphe->ordre; i++) {
        printf("sommet %d durre %f\n", graphe->pSommet[i]->id, graphe->pSommet[i]->duree);
    }
}

Graphe *initGraphe () {
    int ordre, taille;
    Graphe *g;
    trouver_ordre(&ordre);
    taille = trouver_taille();
    g = lire_graphe(ordre, taille);
    //graphe_afficher(g);
    //afficher_duree(g);
    return g;
}