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

void deplacementPuceron(Puceron* matricePuceron[SIZE][SIZE],Puceron *puceron){
	int x = (*puceron).coordP.x;
	int y = (*puceron).coordP.y;
	int direction =(*puceron).directionP;

	//calcul de la futur position
	switch (direction){           //La position du puceron change en fonction de sa position
		case 0:   
			x=x-1;            
			y=y-1;
			break;
		case 1: 
			y=y-1;
			break;
		case 2:
			x++;
			y=y-1;
			break;
		case 3:
			x++;
			break;
		case 4:
			x++;
			y++;
			break;
		case 5:
			y++;
			break;
		case 6:
			x=x-1;
			y++;
			break;
		case 7:
			x=x-1;
			break;
		
		default:
			printf("ERROR, direction non comprise entre 0 et 7");
			break;
		}

	
	//Verification que la nouvelle position se situe bien dans le potager, BONUS 1, il n'y a pas de bords
	if(x>29){    //30 case donc derniere case indice a pour indice 29
		x=0;
	}else if(x<0){
		x=29;
	}
	
	if(y>29){
		y=0;
	}else if(y<0){
		y=29;
	}

	//Les coordonnées du puceron et la matrice sont mis à jour seulement si l'emplacement est libre, sinon le deplacement n'aura pas lieu
	if(matricePuceron[x][y] ==NULL){   
	matricePuceron[(*puceron).coordP.x][(*puceron).coordP.y] =NULL;  //Le puceron bouge, son ancienne place devient libre
	(*puceron).coordP.x =x;
	(*puceron).coordP.y =y;
	matricePuceron[x][y] =puceron;
	}

}





Coord caseAdjacenteLibreAleatoire(Puceron* matricePuceron[SIZE][SIZE],int x,int y){    
	Coord coordTab[9];
	Coord coord;
	coord.x=-1;
	coord.y=-1;
	int nbCaseLibre =0;


	int i=-1;
	int j=-1;
	while(i<2){
		while(j<2){
			if(matricePuceron[x+i][y+i]==NULL){
					coord.x=x+i;
                    coord.y=y+i;
					coordTab[nbCaseLibre]=coord;
					nbCaseLibre ++;
                }	
			j++;
		}
		i++;
	}
	if (coord.x !=-1){
		coord=coordTab[rand()%nbCaseLibre];
	}
	

	return coord;
}


char charDirection(int directon){
	char symbole;
	switch (directon){           //La position du puceron change en fonction de sa position
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


void orientationPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE],int maturite[SIZE][SIZE]){
	int direction =(*puceron).directionP;
	//On recupere toute les case adjacentes libres (sans pucerons)
	Coord coordTab[9];
	Coord coord;
	coord.x=-1;
	coord.y=-1;


	int x = (*puceron).coordP.x;
	int y = (*puceron).coordP.y;
	int nbCaseLibre =0;
	
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			if(matricePuceron[x+i][y+i]==NULL){
					coord.x=x+i;
                    coord.x=y+i;
					coordTab[nbCaseLibre]=coord;
					nbCaseLibre ++;
                }	
		}
	}

	
	if(nbCaseLibre ==0){ //Si il n'y a pas de case adjacente libre sans puceron, on prend une direction au hasard
		direction = rand()%8;
	}else{
	//on choisis une ou il y a une tomate mure parmis celles ou il y a une tomate mure
		int nbCaseTomates = 0;
		for(int i=0;i<nbCaseLibre;i++){
			if(maturite[coordTab[i].x][coordTab[i].y] ==5){
				coordTab[nbCaseTomates]=coordTab[i];
				nbCaseTomates ++;
			}

		}
		if(nbCaseTomates == 0){
			direction=rand()%nbCaseLibre;  //Si aucune case libre ne contient de tomates, le puceron d'orientent vers une case libre au hasard
		}else{
			Coord casePointe = coordTab[rand()%nbCaseTomates];
			x=x - casePointe.x;
			y=y - casePointe.y;
		

			switch (x){
			case -1:
				if (y==-1){
					direction =0;
				}else if(y==0){
					direction =7;
				}else if(y==1){
                	direction =6;
				}
				break;
			case 0:
				if (y==-1){
					direction =1;
				}else if(y==1){
					direction =5;
				}			
				break;
			case 1:
				if (y==-1){
					direction =2;
				}else if(y==0){
					direction =3;
				}else if(y==1){
                	direction =4;
				}
				break;

			}

		}
	
	}
//On met a jour la direction
(*puceron).directionP = direction;

}












