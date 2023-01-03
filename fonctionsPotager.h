# ifndef HEADER_FONCTIONSPOTAGER
# define HEADER_FONCTIONSPOTAGER

#include <stddef.h>   //utile pour le pointeur NULL

#include <time.h>     //pour les nombres aléatoires
#include <stdlib.h>

#include <stdio.h>

#define SIZE 30     //Largeur du potager

typedef struct Coord
   {
   int x;
   int y;
   } Coord;


void affichePotager(char mat[SIZE][SIZE]);
/*Affiche une Matrice de char de taille SIZExSIZE*/

void maturiteTomate(int maturite[SIZE][SIZE]);
/* Ajoute 1 tour de maturité a chaque tomate*/

void apparanceTomate(int maturite[SIZE][SIZE],char potager[SIZE][SIZE]);
/* Change l'apparence de la tomate selon sa maturité*/

void initialiserMaturite (int maturite[SIZE][SIZE]);
/*initialise le tableau de maturité des tomates à 5*/

int bordsSuppr(int x);
/*Gere les bords supprimés, renvois 0 si x>(SIZE -1) et (SIZE -1) si x<0*/

char charDirection(int direction);
/*renvois le charactère associé à une direction, fonctionne pour les pucerons et les coccinnelles*/

void red();
void green();
void black();
/*met la couleur respectivement sur rouge,vert et noir*/

#endif