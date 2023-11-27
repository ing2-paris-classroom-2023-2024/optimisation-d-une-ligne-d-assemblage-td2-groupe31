#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "header.h"

int main () {
    Graphe *graphe;
    graphe = initGraphe();
    precedence(graphe);
    return 0;
}