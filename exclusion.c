#include <stdio.h>
#include <stdlib.h>
#define MAX_OPERATIONS 35

// Structure pour représenter une paire d'opérations incompatibles
typedef struct {
    int op1;
    int op2;
} Exclusion;

void creergroupe(Exclusion *exclusions, int numExclusions) {
    int groups[MAX_OPERATIONS] = {0}; // init tous à 0
    int colors[MAX_OPERATIONS] = {0}; // Tab pour stocker les couleurs

    for (int op = 1; op <= MAX_OPERATIONS; ++op) {
        // Vérifier les couleurs déjà attribuées
        for (int i = 0; i < numExclusions; ++i) {
            if (exclusions[i].op1 == op) {
                colors[op - 1] |= (1 << (groups[exclusions[i].op2 - 1] - 1));
            } else if (exclusions[i].op2 == op) {
                colors[op - 1] |= (1 << (groups[exclusions[i].op1 - 1] - 1));
            }
        }


        int color = 1;
        while (colors[op - 1] & (1 << (color - 1))) {
            color++;
        }

        groups[op - 1] = color;

        for (int i = 0; i < numExclusions; ++i) {
            if (exclusions[i].op1 == op) {
                colors[exclusions[i].op2 - 1] |= (1 << (color - 1));
            } else if (exclusions[i].op2 == op) {
                colors[exclusions[i].op1 - 1] |= (1 << (color - 1));
            }
        }
    }

    // Afficher les résultats
    for (int i = 0; i < MAX_OPERATIONS; ++i) {
        printf("Operation %d dans le groupe %d\n", i + 1, groups[i]);
    }
}

int exclu() {
    // Définir les contraintes d'exclusion
    Exclusion exclusions[] = {
            {1, 4}, {1, 17}, {1, 20}, {2, 11}, {3, 24}, {4, 15}, {5, 22},
            {6, 24}, {8, 21}, {9, 22}, {10, 15}, {11, 31}, {12, 13}, {12, 20},
            {15, 17}, {16, 17}, {22, 26}, {30, 33}, {31, 32}, {33, 35}
    };

    int numExclusions = sizeof(exclusions) / sizeof(Exclusion);
    // Créer les groupes en respectant les contraintes d'exclusion
    creergroupe(exclusions, numExclusions);
    return 0;
}
