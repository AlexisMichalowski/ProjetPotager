#include "fonctionsPucerons.h"

void ensemblePuceronVide(EnsemblePuceron *ensembleP){
	(*ensembleP).nombreP =0;
	}


void vieillissementPuceron(EnsemblePuceron *ensembleP,Puceron *puceron){
	(*puceron).ageP ++ ;	
	if ((*puceron).ageP >= 10){
		mortPuceron(ensembleP, *puceron);
	}
}


void ajouterPuceron(EnsemblePuceron *ensembleP,Puceron p){
	if((*ensembleP).nombreP < MAXP){
		p.index = (*ensembleP).nombreP;
		(*ensembleP).tabP[(*ensembleP).nombreP] = p;
		(*ensembleP).nombreP ++;
	}
}



Puceron *retournePuceron(EnsemblePuceron *ensembleP,int i){
	Puceron* puceron;
	puceron =NULL;
	if (i< (*ensembleP).nombreP){
		*puceron = (*ensembleP).tabP[i];
		}
	return puceron;
	}


void mortPuceron(EnsemblePuceron *ensembleP,Puceron puceron){
	(*ensembleP).tabP[(puceron).index] = (*ensembleP).tabP[(*ensembleP).nombreP - 1] ;  //On remplace le puceron mort par le dernier puceron de l’ensemble
	((*ensembleP).tabP[(puceron).index]).index = (puceron).index ; 					    //On met à jour l’index du puceron déplacé
	
	(*ensembleP).nombreP = (*ensembleP).nombreP -1 ;                                          //On met a jour le nombre de puceron de l'ensemble
}


























