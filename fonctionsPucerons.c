#include "fonctionsPucerons.h"

void ensemblePuceronVide(EnsemblePuceron *ensembleP){
	(*ensembleP).nombreP =0;
	}


void vieillissementPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE]){
	(*puceron).ageP ++ ;	
	if ((*puceron).ageP >= 10){
		mortPuceron(ensembleP, *puceron,matricePuceron);
	}
}


void ajouterPuceron(EnsemblePuceron *ensembleP,Puceron p){
	if((*ensembleP).nombreP < MAXP){
		p.index = (*ensembleP).nombreP;
		(*ensembleP).tabP[(*ensembleP).nombreP] = p;
		(*ensembleP).nombreP = (*ensembleP).nombreP + 1;



	}
}

Puceron* retournePuceron(EnsemblePuceron *ensembleP,int i){
	Puceron* puceron;
	puceron =NULL;
	if (i < (*ensembleP).nombreP){
		puceron = &((*ensembleP).tabP[i]);   //ERREUR de segmentation case 0, le & semble réspudre l'erreur, a voir par la suite, pas tout capté
		} 
	return puceron;
	}


void mortPuceron(EnsemblePuceron *ensembleP,Puceron puceron,Puceron* matricePuceron[SIZE][SIZE]){
	(*ensembleP).tabP[(puceron).index] = (*ensembleP).tabP[(*ensembleP).nombreP - 1] ;  //On remplace le puceron mort par le dernier puceron de l’ensemble
	((*ensembleP).tabP[(puceron).index]).index = (puceron).index ; 					    //On met à jour l’index du puceron déplacé
	
	(*ensembleP).nombreP = (*ensembleP).nombreP -1 ;                                          //On met a jour le nombre de puceron de l'ensemble
	matricePuceron[puceron.coordP.x][puceron.coordP.y] =NULL;
}

void initialiserMatricePuceron(Puceron* matricePuceron[SIZE][SIZE]){
	for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			matricePuceron[i][j]=NULL;
			}
		}
}


void insertionPuceron(Puceron* matricePuceron[SIZE][SIZE],EnsemblePuceron *ensembleP,int Proba){
	Puceron puceron;
	puceron.ageP =0;    			//les pucerons ont 0 tours d'age a l'initalisation
	puceron.tourSuccessifTomate=0;  //ils n'ont aussi pas manger de tomates
	int p=0;

	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			p=rand()%101;   //Nombre aléatoire entre 0 et 100
			if(p<Proba){    
				puceron.coordP.x=i;
				puceron.coordP.y=j;
				puceron.directionP = rand()%8;  //la direction initiale du puceron sera aléatoire et comprise entre 0 et 7, car il y a 8 cases autour du puceron
				ajouterPuceron(ensembleP,puceron);

				/*Récupère le pointeur sur la puceron qui vient d’être ajouté*/
				matricePuceron[i][j]= retournePuceron(ensembleP,(*ensembleP).nombreP-1);
				
			}
		}
	}

}

























