# ifndef HEADER_FONCTIONSPUCERON
# define HEADER_FONCTIONSPUCERON

#include "fonctionsPotager.h"

#include <stddef.h>   //utile pour le pointeur NULL

/*
#include <time.h>     //pour les nombres aléatoires
#include <stdlib.h>

#include <stdio.h>
*/


#define MAXP 900    //Nombre max de pucerons

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


void ensemblePuceronVide(EnsemblePuceron *ensembleP);
/*Modifie l'ensemble pour qu'il soit vide et ne contienne aucun puceron*/

void ajouterPuceron(EnsemblePuceron *ensembleP,Puceron p);
/* ajoute le puceron passé en paramètre a l'ensemble */

int vieillissementPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE]);
/* Le puceron a vécu un tour de plus et gagne un jour de vie et meurt si il attend l'age de 10 tours
    Renvoie 1 si le puceron meurt, 0 sinon*/

Puceron* retournePuceron(EnsemblePuceron *ensembleP,int i);
/*Retourne un pointeur sur le puceron positionné à l’index i dans le tableau de
EnsemblePuceron. Si l’index en paramètre est plus élevé que le cardinal de l’ensemble, retourne
le pointeur NULL.*/

void mortPuceron(EnsemblePuceron *ensembleP,Puceron puceron,Puceron* matricePuceron[SIZE][SIZE]);
/*Retire le puceron en paramètre de l’ensemble de puceron en paramètre*/

void initialiserMatricePuceron(Puceron* matricePuceron[SIZE][SIZE]);
/*Initialiser la matrice Puceron avec des pointeurs NULL*/

void insertionPuceron(Puceron* matricePuceron[SIZE][SIZE],EnsemblePuceron *ensembleP,int nbPucerons);
/*Remplit la matrice de pucerons de telle manière qu’il y ait nbPucerons dedans. Remplit l’ensemble de pucerons en même temps.*/ 

void deplacementPuceron(Puceron* matricePuceron[SIZE][SIZE],Puceron *puceron);
/*Un Puceron se deplace si il le peut, d'une case dans sa direction */

Coord caseAdjacenteLibreAleatoire(Puceron* matricePuceron[SIZE][SIZE],int x,int y);
/*renvois les coordonnées au hasard d'une case adjacente libre, si une telle case n'existe pas renvois (-1,-1)*/

void orientationPuceron(Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE],int maturite[SIZE][SIZE]);
/* change l'orientation du puecron vers une case libre avec tomate mure si possible*/

int boolOrientationP(Puceron puceron,Puceron* matricePuceron[SIZE][SIZE],int maturite[SIZE][SIZE]);
/*renvois 1 si le puceron doit se réorienter (il n'y a pas de tomate mure dans sa direction ou elle n'est pas libre), 0 sinon*/

void puceronMangeTomate(Puceron *puceron, int maturite[SIZE][SIZE]);
/* Lorsque le puceron est sur la meme case qu'une tomate mature, remet la maturité de la tomate à 0 et compte le nombre de tomates consécutives mangées*/

void reproductionPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE]);
/*si le puceron a mangé des tomates pendant 5 tours consécutif, ajoute un puceron adjacent*/
#endif
