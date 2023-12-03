//#include <stdio.h>

// systeme qui pose simplement un compteur afin de raccourcir le temps le plus possible 
// afin de réaliser l'hueristique on utilise un algorithme qui permet de realsier que les options demander en utilisant des algorithmes de contraintes de goupes beaucoup plus cours qui sont simplifié au maximum comme ici 
void creerGroupes(const char fichierOperations, const charfichierTempsCible) {
    FILE fichierOp = fopen(fichierOperations, "r");
    int numero, nbGroupes = 0;
    float temps, tempsCible;

    FILEfichierTemps = fopen(fichierTempsCible, "r");
    fscanf(fichierTemps, "%*s %f", &tempsCible);
    fclose(fichierTemps);

    float tempsGroupe = 0;
    int nbOperationsGroupe = 0;

    while (fscanf(fichierOp, "%d %f", &numero, &temps) == 2) {
        if (tempsGroupe + temps <= tempsCible) {
            printf("Ajouter opération %d au groupe\n", numero);
            tempsGroupe += temps;
            nbOperationsGroupe++;
        } else {
            printf("Groupe %d - Temps total : %.2f\n", nbOperationsGroupe, tempsGroupe);
            tempsGroupe = temps;
            nbOperationsGroupe = 1;
            printf("Ajouter opération %d au nouveau groupe\n", numero);
            nbGroupes++;
        }
    }

    printf("Groupe %d - Temps total : %.2f\n", nbOperationsGroupe, tempsGroupe);
    fclose(fichierOp);
}

//int main() {
//    creerGroupes("proceduretemps.txt", "temps.txt");
//    return 0;
//}
