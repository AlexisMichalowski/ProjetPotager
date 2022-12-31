#include "fonctionsPotager.h"

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

int bordsSuppr(int x){
	if(x>(SIZE -1)){    
		x=0;
	}else if(x<0){
		x=(SIZE -1);
	}

	return x;
}


char charDirection(int directon){
	char symbole;
	switch (directon){           //La position du puceron change en fonction de sa direction
		case 0:   
			symbole='\\';
			break;
		case 1: 
			symbole='^';
			break;
		case 2:
			symbole='/';
			break;
		case 3:
			symbole='>';
			break;
		case 4:
			symbole='\\';
			break;
		case 5:
			symbole='v';
			break;
		case 6:
			symbole='/';
			break;
		case 7:
			symbole='<';
			break;

	}
return symbole;
}