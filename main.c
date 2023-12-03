#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "header.h"
#include <unistd.h>

int main () {
    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);

    //menu();
    Graphe *graphe;
    int nb_contraintes = 3;
    int tab_contraintes[3] = {1,1,1};
    graphe = initGraphe();
    station(graphe,tab_contraintes,nb_contraintes);
    //precedence(graphe);

    return 0;
}
