#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "header.h"
#include <unistd.h>

int main () {

    //menu();
    Graphe *graphe;
    int tab_contraintes[3] = {1,1,0};
    graphe = initGraphe();
    station(graphe,tab_contraintes);
    //precedence(graphe);

    return 0;
}