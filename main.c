#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "header.h"

int main () {
    Graphe *graphe;
    graphe = initGraphe();
    tous_les_chemins(graphe,0,34);
    return 0;
}