

#include "fonctionsPucerons.h"

void initialiserPotager();
/* Crée un Potager Initialisé, avec des tomates Grosses à Chaque Cases*/


void affichePotager(char mat[SIZE][SIZE]);
/*Affiche une Matrice de char de taille SIZExSIZE*/


void maturiteTomate(int maturite[SIZE][SIZE]);
/* Ajoute 1 tour de maturité a chaque tomate*/

void apparanceTomate(int maturite[SIZE][SIZE],char potager[SIZE][SIZE]);
/* Change l'apparence de la tomate selon sa maturité*/

void puceronMangeTomate(Puceron *puceron, int maturite[SIZE][SIZE]);
/* Lorsque le puceron est sur la meme case qu'une tomate mature, remet la maturité de la tomate à 0 et compte le nombre de tomates consécutives mangées*/

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

/* initialise les pucerons*/
/* fonction deplacementP */
/* fonction reproP */

void reproductionPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE]);
void reproductionPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE]){
    if ((*puceron).tourSuccessifTomate == 5) {
        int x=(*puceron).coordP.x;
        int y=(*puceron).coordP.y;
       

        Puceron puceron2;
        puceron2.ageP=0;
        puceron2.directionP=rand()%8;
        puceron2.tourSuccessifTomate=0;
        
        //gerer les coordonnées du nouveau né
        puceron2.coordP = caseAdjacenteLibreAleatoire(matricePuceron,x,y);
           
        if(puceron2.coordP.x != -1){    //Si il y a une case adjacente vide, sinon pas de naissance
            ajouterPuceron(ensembleP,puceron2);  //l'index du puceron est gérer dans cette fonction
            /*Récupère le pointeur sur la puceron qui vient d’être ajouté*/
            matricePuceron[x][y]= retournePuceron(ensembleP,(*ensembleP).nombreP-1); 
        }
        (*puceron).tourSuccessifTomate = 0; //on reinitialise le compteur si le puceron s'est reproduit
    }
}

/* fonction qui ajoute 1 tour de maturité a chaque tomate*/
void maturiteTomate(int maturite[SIZE][SIZE]){               
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
            if (maturite[i][j]<20) {
                    maturite[i][j]++;
                }
            }
        }
    }

/* fonction qui change l'apparence de la tomate selon sa maturité*/   
void apparanceTomate(int maturite[SIZE][SIZE],char potager[SIZE][SIZE]) {
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
            if (maturite[i][j] < 5) {
                potager[i][j]='.';
            } else if (4<maturite[i][j] && maturite[i][j] <20) {
                potager[i][j]='o';
                } else potager[i][j]='O';
            }
        }
    }



/* fonction mortP */
/* orientationP   */

/* fonction PmangeT*/
void puceronMangeTomate(Puceron *puceron, int maturite[SIZE][SIZE]){    
    if (maturite[(*puceron).coordP.x][(*puceron).coordP.y] == 20){                           /* le puceron mange la tomate uniquement si elle est mature*/
        maturite[(*puceron).coordP.x][(*puceron).coordP.y] = 0;
        (*puceron).tourSuccessifTomate++ ;           /*on ajoute +1 au nombre de tomates consécutives mangées*/
    }else{
    (*puceron).tourSuccessifTomate = 0;   /* il n'a pas mangé de tomate ce tour ci, donc compteur retourne a 0*/
    }        
}





/* initialise les coccinelles*/
/* fonction deplacementC */
/* reproC */
/*mortC */
/* fonction CmangeP*/
void coccinelleMangePuceron(EnsemblePuceron *ensembleP,Puceron *puceron, Coccinelle *coccinelle,Puceron* matricePuceron[SIZE][SIZE]);
void coccinelleMangePuceron(EnsemblePuceron *ensembleP,Puceron *puceron, Coccinelle *coccinelle,Puceron* matricePuceron[SIZE][SIZE]){       
    if ((*puceron).coordP.x == (*coccinelle).coordC.x) {
        if ((*puceron).coordP.y == (*coccinelle).coordC.y) {
            mortPuceron(ensembleP, *puceron,matricePuceron);    
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




