//
// Created by pauld on 26/11/2023.
//

#ifndef PROJET_GRAPHE_H
#define PROJET_GRAPHE_H

/* Structure d'un arc*/
typedef struct Parcours {
    int pred;
    int poids;
}Parcours;


struct Arc
{
    int sommet; // numéro de sommet d'un arc adjacent au sommet initial
    struct Arc* arc_suivant;
};

/* Alias de pointeur sur un Arc */
typedef struct Arc* pArc;

struct Exclusion {
    int sommet;
    struct Exclusion* ex_suivant;
};

typedef struct Exclusion* pExclusion;

/* Structure d'un sommet*/
struct Sommet
{
    int precedence;
    int id;
    struct Exclusion* exclusion;
    float duree;
    struct Arc* arc;
    int station;
};

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe
{
    int taille;
    int ordre;
    int cycle;
    int nb_exclusions;
    pSommet* pSommet;
} Graphe;

#endif //PROJET_GRAPHE_H
