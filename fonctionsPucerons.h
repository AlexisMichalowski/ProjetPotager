# ifndef HEADER_FILE_NAME
# define HEADER_FILE_NAME

#include <stddef.h>

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
    int reproductionP;
    Coord coordP;
    int index;                  //La position du puceron dans le tableau de ensemble puceron
    int tourSuccessifTomate;	//Le nombre de tour d'affilé pendant lesquels le Puceron a manger des tomates
    } Puceron;



typedef struct EnsemblePuceron
    {
    int nombreP ;
    Puceron tabP[MAXP];
    } EnsemblePuceron;

//Pour plus tard (Niveau 2)

typedef struct coccinelle
    {
    int ageC;
    int directionC;
    int reproductionC;
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

void vieillissementPuceron(EnsemblePuceron *ensembleP,Puceron *puceron);
/* Le puceron a vécu un tour de plus et gagne un jour de vie */

Puceron *retournePuceron(EnsemblePuceron *ensembleP,int i);
/*Retourne un pointeur sur le puceron positionnée à l’index i dans le tableau de
EnsemblePuceron. Si l’index en paramètre est plus élevé que le cardinal de l’ensemble, retourne
le pointeur NULL.*/

void mortPuceron(EnsemblePuceron *ensembleP,Puceron puceron);
/*Retire le puceron en paramètre de l’ensemble de puceron en paramètre*/




#endif