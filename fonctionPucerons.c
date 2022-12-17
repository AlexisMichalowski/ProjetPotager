void ensemblePuceronVide(EnsemblePuceron *ensembleP);
/*Modifie l'ensemble pour qu'il soit vide et ne contiennent aucun puceron*/

void ajouterPuceron(EnsemblePuceron *ensembleP,Puceron p);
/* ajoute le puceron passé en paramètre a l'ensemble */

void vieillissementPuceron(Puceron *puceron);
/* Le puceron a vécu un tour de plus et gagne un jour de vie */

Puceron *retournePuceron(EnsemblePuceron *ensembleP,int i);
/*Retourne un pointeur sur le puceron positionnée à l’index i dans le tableau de
EnsemblePuceron. Si l’index en paramètre est plus élevé que le cardinal de l’ensemble, retourne
le pointeur NUL.*/

void mortPuceron(EnsemblePuceron *ensembleP,Puceron *puceron);
/*Retire le puceron en paramètre de l’ensemble de puceron en paramètre*/

void ensemblePuceronVide(EnsemblePuceron *ensembleP){
	(*ensembleP).nombreP =0;
	}

void vieillissementPuceron(Puceron *puceron){
	(puceron*).ageP ++;
	if ((puceron*).ageP >= 10){
		mortPuceron(&puceron);
	}
	
void ajouterPuceron(EnsemblePuceron *ensembleP,Puceron p){
	if((*ensembleP).nombreP <MAXP){
		p.index = (*ensembleP).nombreP;
		(*ensembleP).tabP[(*ensembleP).nombreP] = p;
		(*ensembleP).nombreP ++;
	}
}

Puceron *retournePuceron(EnsemblePuceron *ensembleP,int i){
	Puceron *puceronIndex = NULL;
	if (i< (*ensembleP).nombreP){
		*puceronIndex= (*puceronIndex).tabP[i];
		}
	return *puceronIndex;
	}


void mortPuceron(EnsemblePuceron *ensembleP,Puceron *puceron){
	
	


}




























