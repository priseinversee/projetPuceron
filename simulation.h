#ifndef simulation
#define simulation

typedef struct Coordonnee {
    int abscisse;
    int ordonnee;
} Coordonnee;

typedef struct Case {
    Tomate* tomateCase;
    Puceron* puceronCase;
    Coccinelle* coccinelleCase;
} Case;

typedef struct Tomate {
    Coordonnees coordTomates;
    int etatCroissance;
} Tomate;

typedef struct Puceron {
    Coordonnees coordPuceron;
    int compteurReproduction;    
    int compteurVie;
    int direction;
} Puceron;

typedef struct Coccinelle {
    Coordonnees coordCoccinelle;
    int compteurReproduction;
    int compteurVie;
    int direction;
} Coccinelle;


//Fonctions relatives aux tomates
void pousseTomate(Tomate* tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met à jour l'état de croissance de cette tomate. Si l'état est compris entre 0 et 4, alors ajoute +1 à celui-ci. Sinon ne fait rien.*/

void mortTomate(Tomate* tomate);
/*Prend en entrée un pointeur sur un objet de type Tomate et met son état de croissance à 0.*/


//Fonctions relatives aux pucerons
void deplacementPuceron(Puceron* puceron) ;
/*Direction donnée jusqu’à ce qu’ils ne trouvent plus de tomates, auquel cas ils se dirigeront dans une case attenante au hasard contenant une tomate. Si ils n’en trouvent pas, ils se d´eplaceront sur une case au hasard.*/

void vieillissementPuceron(Puceron* puceron);
void reproductionPuceron(Puceron* puceron);
void mortPuceron(Puceron* puceron);


//Fonctions relatives aux coccinelles
void deplacementCoccinelle(Coccinelle* coccinelle);
void vieillissementCoccinelle(Coccinelle* coccinelle);
void reproductionCoccinelle(Coccinelle* coccinelle);
void mortCoccinelle(Coccinelle* coccinelle);