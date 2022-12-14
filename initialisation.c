#include "initialisation.h"

void creerEnsemblePuceron(ensemblePuceron *ensPuc, int n, int ligne, int colonne, Case *pointeurPotager[ligne][colonne])
{
    apparitionPuceron(n, ensPuc, ligne, colonne, pointeurPotager);
    (*ensPuc).nbPuceron = n;
}

void initialisationPotagerVide(int ligne, int colonne, Case *pointeurPotager[ligne][colonne])
{
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            (*pointeurPotager[i][j]).puceronCase = NULL;
            (*pointeurPotager[i][j]).coccinelleCase = NULL;
        }
    }
}

void remplissagePotagerTomate(int ligne, int colonne, Case potager[ligne][colonne])
{
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < ligne; j++)
        {
            potager[i][j].tomateCase = (struct Tomate){{i, j}, 20};
        }
    }
}

void apparitionPuceron(int n, ensemblePuceron *ensPuc, int ligne, int colonne, Case *pointeurPotager[ligne][colonne])
{
    for (int i = 0; i < n; i++)
    {
        Puceron nouveauPuceron;

        int coordX = rand() % ligne;
        int coordY = rand() % colonne;
        while ((*pointeurPotager[coordX][coordY]).puceronCase != NULL)
        {
            coordX = rand() % ligne;
            coordY = rand() % colonne;
        }
        nouveauPuceron = (struct Puceron){{coordX, coordY}, 0, 0, genereDirection(), i};

        (*ensPuc).tab[i] = nouveauPuceron;
        (*pointeurPotager[(*ensPuc).tab[i].coordPuceron.x][(*ensPuc).tab[i].coordPuceron.y]).puceronCase = &((*ensPuc).tab[i]);
    }
}
