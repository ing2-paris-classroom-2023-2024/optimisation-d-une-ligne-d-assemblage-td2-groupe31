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

/* Structure d'un sommet*/
struct Sommet
{
    int etat;
    int precedence;
    int valeur;
    struct Arc* arc;
};

/* Alias de pointeur sur un Sommet */
typedef struct Sommet* pSommet;

/* Alias d'un Graphe */
typedef struct Graphe
{
    int taille;
    int ordre;
    pSommet* pSommet;
} Graphe;

#endif //PROJET_GRAPHE_H
