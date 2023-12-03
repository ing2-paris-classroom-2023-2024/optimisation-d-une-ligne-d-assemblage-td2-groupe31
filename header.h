#include "graphe.h"
#include "stations.h"
#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H


Graphe *initGraphe ();
int get_max_stations (Graphe *graphe);
void station (Graphe *graphe, int tab_contraintes[],int nb_contraintes);
void cycle (Graphe *graphe,int tab_pred[], int simple);
void precedence(Graphe* graphe,int tab[]);
void menu();
int exclusion(Usine *usine,Graphe *graphe, int tab[graphe->ordre]);
#endif //PROJET_HEADER_H
