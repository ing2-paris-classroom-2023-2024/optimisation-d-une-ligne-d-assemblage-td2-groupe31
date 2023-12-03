#include "graphe.h"
#include "stations.h"
#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H


Graphe *initGraphe ();
void station (Graphe *graphe, int tab_contraintes[]);
void cycle (Graphe *graphe);
void precedence(Graphe* graphe,int tab[]);
void menu();
int exclusion(Usine *usine,Graphe *graphe, int tab[graphe->ordre]);
#endif //PROJET_HEADER_H
