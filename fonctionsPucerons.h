# ifndef HEADER_FILE_NAME
# define HEADER_FILE_NAME

#include <stddef.h>   //utile pour le pointeur NULL

#include <time.h>     //pour les nombres aléatoires
#include <stdlib.h>

#include <stdio.h>


#define MAXP 900    //Nombre max de pucerons
#define MAXC 900    //Nombre max de coccinelle 
#define SIZE 30     //Largeur du potager

typedef struct Coord
   {
   int x;
   int y;
   } Coord;


typedef struct Puceron
    {
    int ageP ;                                  
    int directionP;              
    Coord coordP;
    int index;                  //La position du puceron dans le tableau de ensemble puceron
    int tourSuccessifTomate;	//Le nombre de tour d'affilé pendant lesquels le Puceron a manger des tomates, utile pour leur reproduction
    } Puceron;



typedef struct EnsemblePuceron
    {
    int nombreP ;
    Puceron tabP[MAXP];
    } EnsemblePuceron;

//Pour plus tard (Niveau 2)

typedef struct Coccinelle
    {
    int ageC;
    int directionC;
    int nbPuceronsMange;    //Le nombre de pucerons mangé par la coccinelle, utile pour la reproduction
    Coord coordC;
    } Coccinelle;



typedef struct EnsembleCoccinelle
    {
    int nombreP ;
    Coccinelle tabC[MAXC];
    } EnsembleCoccinelle;


void ensemblePuceronVide(EnsemblePuceron *ensembleP);
/*Modifie l'ensemble pour qu'il soit vide et ne contiennent aucun puceron*/

void ajouterPuceron(EnsemblePuceron *ensembleP,Puceron p);
/* ajoute le puceron passé en paramètre a l'ensemble */

int vieillissementPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE]);
/* Le puceron a vécu un tour de plus et gagne un jour de vie et meurt si il attend l'age de 10 tours
    Renvois 1 si le puceron meurt, 0 sinon*/

Puceron* retournePuceron(EnsemblePuceron *ensembleP,int i);
/*Retourne un pointeur sur le puceron positionnée à l’index i dans le tableau de
EnsemblePuceron. Si l’index en paramètre est plus élevé que le cardinal de l’ensemble, retourne
le pointeur NULL.*/

void mortPuceron(EnsemblePuceron *ensembleP,Puceron puceron,Puceron* matricePuceron[SIZE][SIZE]);
/*Retire le puceron en paramètre de l’ensemble de puceron en paramètre*/

void initialiserMatricePuceron(Puceron* matricePuceron[SIZE][SIZE]);
/*Initialiser la mtrice Puceron avec des pointeurs NULL*/

void insertionPuceron(Puceron* matricePuceron[SIZE][SIZE],EnsemblePuceron *ensembleP,int Proba);
/*Remplit la matrice de pucerons de telle manière qu’il y ait Proba% de chances pour chaque case
de contenir un puceron. Remplit l’ensemble de pucerons en même temps.*/ 

void deplacementPuceron(Puceron* matricePuceron[SIZE][SIZE],Puceron *puceron);
/*Un Puceron se deplace si il le peut, d'une case dans sa direction */

Coord caseAdjacenteLibreAleatoire(Puceron* matricePuceron[SIZE][SIZE],int x,int y);
/*renvois les coordonnées au hasard d'une case adjacente libre, si une telle case n'existe pas renvois (-1,-1)*/

char charDirection(int directon);
/*renvois le charactère associé à une direction, fonctionne pour les pucerons et les coccinnelles*/

void orientationPuceron(Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE],int maturite[SIZE][SIZE]);
/* change l'orientation du puecron si il n'y a pas de tomates dans sa direction et si il y a un puceron dans sa direction*/

int bordsSuppr(int x);
/*Gere les bords supprimés, renvois 0 si x>(SIZE -1) et (SIZE -1) si x<0*/

int boolOrientationP(Puceron puceron,Puceron* matricePuceron[SIZE][SIZE],int maturite[SIZE][SIZE]);
/*renvois 1 si le puceron doit se réorienter (il n'y a pas de tomate mure dans sa direction ou elle n'est pas libre), 0 sinon*/
#endif