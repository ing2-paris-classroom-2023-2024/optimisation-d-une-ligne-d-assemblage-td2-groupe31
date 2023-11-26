#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "header.h"

int main () {
    Graphe *graphe;
    graphe = initGraphe();
    printf("%d ", graphe->ordre);
    printf("%d ", graphe->taille);

    return 0;
}