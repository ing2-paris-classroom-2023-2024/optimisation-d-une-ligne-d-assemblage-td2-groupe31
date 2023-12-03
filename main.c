#include <stdio.h>
#include "graphe.h"
#include <stdlib.h>
#include "header.h"
#include <unistd.h>
#include <windows.h>
int main () {

    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);
    menu();

    //precedence(graphe);

    return 0;
}