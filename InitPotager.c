#include <stdio.h>

#define SIZE 30

void initialiserPotager();
/* Crée un Potager Initialisé, avec des tomates Grosses à Chaque Cases*/


void affichePotager(char mat[SIZE][SIZE]);
/*Afficher une Matrice de char de taille SIZExSIZE*/


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

/*
int main(){

char potager[SIZE][SIZE];

initialiserPotager(potager);
affichePotager(potager);

return 0;

}
*/

	




