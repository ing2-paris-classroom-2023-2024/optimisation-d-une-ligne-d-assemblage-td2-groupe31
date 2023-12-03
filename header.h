#include "graphe.h"
#include "stations.h"
#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H


Graphe *initGraphe ();
int get_max_stations (Graphe *graphe);
void station (Graphe *graphe, int tab_contraintes[],int nb_contraintes);
void cycle (Graphe *graphe,int tab_pred[], int simple);
void precedence(Graphe* graphe,int tab[],int nb_contraintes);
void menu();
void gotoligcol( int lig, int col );
int exclusion(Graphe *graphe, int tab[graphe->ordre],int nb_contraintes);
#endif //PROJET_HEADER_H
