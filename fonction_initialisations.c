#include "fonctionsPucerons.h"
#include "fonctionsCoccinelles.h"

void initialiserPotager();
/* Crée un Potager Initialisé, avec des tomates Grosses à Chaque Cases*/

void affichePotager(char mat[SIZE][SIZE]);
/*Affiche une Matrice de char de taille SIZExSIZE*/

void maturiteTomate(int maturite[SIZE][SIZE]);
/* Ajoute 1 tour de maturité a chaque tomate*/

void apparanceTomate(int maturite[SIZE][SIZE],char potager[SIZE][SIZE]);
/* Change l'apparence de la tomate selon sa maturité*/

void initialiserMaturite (int maturite[SIZE][SIZE]);
/*initialise le tableau de maturité des tomates à 5*/

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

void initialiserMaturite (int maturite[SIZE][SIZE]){
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			maturite[i][j]=20;
			}
		}


}

/* fonction qui ajoute 1 tour de maturité a chaque tomate*/
void maturiteTomate(int maturite[SIZE][SIZE]){               
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
            if (maturite[i][j]<20){
                    maturite[i][j]++;
                }
            }
        }
    }

/* fonction qui change l'apparence de la tomate selon sa maturité*/   
void apparanceTomate(int maturite[SIZE][SIZE],char potager[SIZE][SIZE]) {
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
            if (maturite[i][j] < 5){
                potager[i][j]='.';
            } else if (4<maturite[i][j] && maturite[i][j]<20){
                potager[i][j]='o';
            } else {
                potager[i][j]='O';
            }
        }
    }
}



/* initialise les coccinelles*/
/* fonction deplacementC */
/* reproC */
/*mortC */
/* fonction CmangeP*/


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




