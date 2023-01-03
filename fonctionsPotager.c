#include "fonctionsPotager.h"

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


void maturiteTomate(int maturite[SIZE][SIZE]){               
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
            if (maturite[i][j]<20){
                    maturite[i][j]++;
                }
            }
        }
    }

   
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


char charDirection(int direction){
	char symbole;
	switch (direction){           //La position du puceron change en fonction de sa direction
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


void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[0;32m");
}

void black () {
  printf("\033[0m");
}


