
#include <stdio.h>
#include "fonctionsPucerons.h"

void initialiserPotager();
/* Crée un Potager Initialisé, avec des tomates Grosses à Chaque Cases*/


void affichePotager(char mat[SIZE][SIZE]);
/*Affiche une Matrice de char de taille SIZExSIZE*/


void maturiteTomate(int maturite[SIZE][SIZE]);
/* Ajoute 1 tour de maturité a chaque tomate*/

void affichageTomate(int maturite[SIZE][SIZE],char potager[SIZE][SIZE]);
/* Change l'apparence de la tomate selon sa maturité*/

void puceronMangeTomate(Puceron *puceron, int maturite[SIZE][SIZE]);
/* Lorsque le puceron est sur la meme case qu'une tomate mature, remet la maturité de la tomate à 0 et compte le nombre de tomates consécutives mangées*/



void initialiserPotager(char potager[SIZE][SIZE]){
	for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			potager[i][j]='O';
			}
		}
	}
	
void affichePotager(char mat[SIZE][SIZE]){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			printf("%c ",mat[i][j]);
			}
			printf("\n");
		}
	}


/* initialise les pucerons*/
/* fonction deplacementP */
/* fonction reproP */
void reproductionPuceron(EnsemblePuceron *ensembleP,Puceron *puceron);
void reproductionPuceron(EnsemblePuceron *ensembleP,Puceron *puceron){
    if ((*puceron).tourSuccessifTomate == 5) {
        ajouterPuceron(ensembleP,*puceron);
        }
    }

/* fonction qui ajoute 1 tour de maturité a chaque tomate*/
void maturiteTomate(int maturite[SIZE][SIZE]){               /*ajouter le booléen de PmangeT dans les parametres*/
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
            if (maturite[i][j]<5) {
                    maturite[i][j]++;
                }
            }
        }
    }

/* fonction qui change l'apparence de la tomate selon sa maturité*/
void affichageTomate(int maturite[SIZE][SIZE],char potager[SIZE][SIZE]) {
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
            if (maturite[i][j] == 0) {
                potager[i][j]='O';
            } else if (2<maturite[i][j]<4) {
                potager[i][j]='o';
                } else potager[i][j]='.';
            }
        }
    }



/* fonction mortP
/* orientationP

/* fonction PmangeT*/
void PuceronMangeTomate(Puceron *puceron, int maturite[SIZE][SIZE]){     /* appelle coordonnées, le puceron pour ajoiuter le tour successif et la table des maturité*/
    for (int i=0;i<SIZE;i++){
	    for (int j=0;j<SIZE;j++){   
            if ((*puceron).coordP.x == i ){
                if ((*puceron).coordP.y == j) {
                    if (maturite[i][j] == 5) {                           /* le puceron mange la tomate uniquement si elle est mature*/
                        maturite[i][j] = 0;
                        (*puceron).tourSuccessifTomate++ ;           /*on ajoute +1 au nombre de tomates consécutives mangées*/
                    } else (*puceron).tourSuccessifTomate = 0;            /* il n'a pas mangé de tomate ce tour ci, donc compteur retourne a 0*/
                }
            }
        }
    }
}




/* initialise les coccinelles*/
/* fonction deplacementC */
/* reproC */
/*mortC */
/* fonction CmangeP*/
void coccinelleMangePuceron(EnsemblePuceron *ensembleP,Puceron *puceron, Coccinelle *coccinelle);
void coccinelleMangePuceron(EnsemblePuceron *ensembleP,Puceron *puceron, Coccinelle *coccinelle){       
    if ((*puceron).coordP.x == (*coccinelle).coordC.x) {
        if ((*puceron).coordP.y == (*coccinelle).coordC.y) {
            mortPuceron(ensembleP, *puceron);    
            }
        }
    }

/*orientationC*/


/* ORDRE DU TOUR
MAJ maturité tomates


déplacement puceron
déplacement coccinelle
CmangeP
PmangeT
reproP
mortP
orientationP
reproC
mortC
orientationC

FIN DU TOUR
*/




