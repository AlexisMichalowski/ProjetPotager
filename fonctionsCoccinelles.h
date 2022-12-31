# ifndef HEADER_FONCTIONSCOCCINELLES
# define HEADER_FONCTIONSCOCCINELLES

#include "fonctionsPotager.h"
#include "fonctionsPucerons.h"


#define MAXC 900    //Nombre max de coccinelle 


typedef struct Coccinelle
    {
    int ageC;           //Age de la coccinelle
    int directionC;     //Direction de la coccinelle
    int nbPuceronsMange;    //Le nombre de pucerons mangé par la coccinelle, utile pour la reproduction
    Coord coordC;              //position de la coccinelle dans le potager 
    int index; //position de la coccinelle dans le tableau de EnsembleCoccinelle
    } Coccinelle;



typedef struct EnsembleCoccinelle
    {
    int nombreC;
    Coccinelle tabC[MAXC];
    } EnsembleCoccinelle;

void ensembleCoccinelleVide(EnsembleCoccinelle *ensembleC);
/*Modifie l'ensemble pour qu'il soit vide et ne contienne aucune coccinelle*/

void ajouterCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle c);
/* ajoute la Coccinelle passé en paramètre a l'ensemble */

int vieillissementCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle *coccinelle,Coccinelle* matriceCoccinelle[SIZE][SIZE]);
/* La coccinelle a vécu un tour de plus et gagne un jour de vie et meurt si elle atteind l'age de 20 tours
    Renvoie 1 si la coccinelle meurt, 0 sinon*/

void mortCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle coccinelle,Coccinelle* matriceCoccinelle[SIZE][SIZE]);
/*Retire la coccinelle en paramètre de l’ensemble de coccinelle en paramètre*/

void initialiserMatriceCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE]);
/*Initialiser la matrice Coccinelle avec des pointeurs NULL*/

void insertionCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE],EnsembleCoccinelle *ensembleC,int nbCoccinelles);
/*Remplit la matrice de coccinelles de telle manière qu’il y ait nbCoccinelels dedans.
Remplit l’ensemble de pucerons en même temps.*/ 

Coccinelle* retourneCoccinelle(EnsembleCoccinelle *ensembleC,int i);
/*Retourne un pointeur sur la coccinelle positionné à l’index i dans le tableau de
EnsembleCoccinelle. Si l’index en paramètre est plus élevé que le cardinal de l’ensemble, retourne
le pointeur NULL.*/

int coccinelleMangePuceron(EnsemblePuceron *ensembleP, Coccinelle *coccinelle,Puceron* matricePuceron[SIZE][SIZE]);
/*renvois 1 si la coccinelle a mangé un puceron,0 sinon.
Si elle mange un puceron, le tue*/

void deplacementCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE],Coccinelle *coccinelle);
/*Une coccinelle se deplace si elle le peut, d'une case dans sa direction */

void reproductionCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle *coccinelle,Coccinelle* matriceCoccinelle[SIZE][SIZE]);
/*si la coccinelle a mangé 3 pucerons, ajoute une coccinelle adjacente*/

Coord caseAdjacenteLibreAleatoireCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE],int x,int y);
/*Renvois une case adjacente sans Coccinelle aléatoire*/

//Orientation


#endif