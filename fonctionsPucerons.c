#include "fonctionsPucerons.h"

void ensemblePuceronVide(EnsemblePuceron *ensembleP){
	(*ensembleP).nombreP =0;
	}


int vieillissementPuceron(EnsemblePuceron *ensembleP,Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE]){
	(*puceron).ageP ++ ;
	int mort = 0;   //booleen qui vaut 0 si le puceron reste en vie, 1 sinon
	if ((*puceron).ageP >= 10){
		mortPuceron(ensembleP, *puceron,matricePuceron);
		mort =1;
	}
	return mort;
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
		puceron = &((*ensembleP).tabP[i]);   
		} 
	return puceron;
	}


void mortPuceron(EnsemblePuceron *ensembleP,Puceron puceron,Puceron* matricePuceron[SIZE][SIZE]){
	(*ensembleP).tabP[(puceron).index] = (*ensembleP).tabP[(*ensembleP).nombreP - 1] ;  //On remplace le puceron mort par le dernier puceron de l’ensemble
	((*ensembleP).tabP[(puceron).index]).index = (puceron).index ; 					    //On met à jour l’index du puceron déplacé
	
	(*ensembleP).nombreP = (*ensembleP).nombreP -1 ;                                    //On met a jour le nombre de puceron de l'ensemble
	matricePuceron[puceron.coordP.x][puceron.coordP.y] =NULL;							//On enleve le puceron de la matrice de	pucerons				
}

void initialiserMatricePuceron(Puceron* matricePuceron[SIZE][SIZE]){
	for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			matricePuceron[i][j]=NULL;
			}
		}
}


void insertionPuceron(Puceron* matricePuceron[SIZE][SIZE],EnsemblePuceron *ensembleP,int nbPucerons){
	int nbPuceronsAjoute=0;
	int i=0;
	int j=0;
	Puceron puceron;
	puceron.ageP =0;    			//les pucerons ont 0 tours d'age a l'initalisation
	puceron.tourSuccessifTomate=0;  //ils n'ont aussi pas manger de tomates

	while(nbPuceronsAjoute < nbPucerons){  //Tant qu'il n'y a pas le nombre de pucerons voulus
		//On prend une position au hasard dans le potager
		i=rand()%30;
		j=rand()%30;
		//si il n'y a pas de pucerons a la position indiqué on en ajoute un
		if(matricePuceron[i][j] == NULL){
			puceron.coordP.x=i;
			puceron.coordP.y=j;
			puceron.directionP = rand()%8;  //la direction initiale du puceron sera aléatoire et comprise entre 0 et 7, car il y a 8 cases autour du puceron
			ajouterPuceron(ensembleP,puceron);
			nbPuceronsAjoute ++;

			/*Récupère le pointeur sur la puceron qui vient d’être ajouté*/
			matricePuceron[i][j]= retournePuceron(ensembleP,(*ensembleP).nombreP-1);
		}
	}

}

void deplacementPuceron(Puceron* matricePuceron[SIZE][SIZE],Puceron *puceron){
	int x = (*puceron).coordP.x;
	int y = (*puceron).coordP.y;
	int direction =(*puceron).directionP;

	//calcul de la future position
	switch (direction){           //La direction du puceron change en fonction de sa position
		case 0:   
			x=x-1;            
			y=y-1;
			break;
		case 1: 
			x=x-1;
			break;
		case 2:
			y++;
			x=x-1;
			break;
		case 3:
			y++;
			break;
		case 4:
			x++;
			y++;
			break;
		case 5:
			x++;
			break;
		case 6:
			y=y-1;
			x++;
			break;
		case 7:
			y=y-1;
			break;
		
		default:
			printf("ERROR, direction non comprise entre 0 et 7");
			break;
		}

	
	//Verification que la nouvelle position se situe bien dans le potager, BONUS 1, il n'y a pas de bords
	x=bordsSuppr(x);
	y=bordsSuppr(y);

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
	
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			if(matricePuceron[bordsSuppr(x+i)][bordsSuppr(y+j)]==NULL){  //gere les bords supprimés
					coord.x=bordsSuppr(x+i);
                    coord.y=bordsSuppr(y+j);
					coordTab[nbCaseLibre]=coord;
					nbCaseLibre ++;
                }	
		}
	}

	if (coord.x !=-1){
		coord=coordTab[rand()%nbCaseLibre];
	}
	

	return coord;
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


void orientationPuceron(Puceron *puceron,Puceron* matricePuceron[SIZE][SIZE],int maturite[SIZE][SIZE]){  
	int direction =(*puceron).directionP;
	//On recupere toute les case adjacentes libres (sans pucerons)
	Coord coordTab[9];
	Coord coord;
	coord.x=-1;
	coord.y=-1;

	int x = (*puceron).coordP.x;
	int y = (*puceron).coordP.y;
	int nbCaseLibre =0;  //compteur du nombre de cases libres adjacentes au puceron
	
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			if(matricePuceron[bordsSuppr(x+i)][bordsSuppr(y+j)]==NULL){   //gestion des bords supprimés
					//On ne prend pas les vrais positions des cases, pour pouvoir calculer la direction plus tard (pas de bordsSuppr ici)
					coord.x=(x+i);
                    coord.y=(y+j);
					coordTab[nbCaseLibre]=coord;
					nbCaseLibre ++;
                }	
		}
	}

	
	if(nbCaseLibre ==0){ //Si il n'y a pas de case adjacente libre sans puceron, on prend une direction au hasard
		direction = rand()%8;
	}else{				//on choisis une ou il y a une tomate mure parmis les cases libres contenant une tomate mure
		int nbCaseTomates = 0;
		for(int i=0;i<nbCaseLibre;i++){
			if(maturite[bordsSuppr(coordTab[i].x)][bordsSuppr(coordTab[i].y)] ==20){  //bordsSuppr pour la calcul mais pas pour l'assignation, facilite les calculs ensuites
				coordTab[nbCaseTomates]=coordTab[i];
				nbCaseTomates ++;
			}
		}
		Coord casePointe; //Case vers laquelle le puceron sera dirigé

		if(nbCaseTomates == 0){
			//Si aucune case libre ne contient de tomates, le puceron s'orientent vers une case libre au hasard
			casePointe=coordTab[rand()%nbCaseLibre];  //recuperation des coordonnées de la case vers laquelle il s'oriente

		}else{
			//le puceron s'orientent vers une case libre contenant une tomate au hasard
			casePointe = coordTab[rand()%nbCaseTomates];
		}
			//Calcul de la direction en fonction de la position relative de la case vers laquelle le puceron s'oriente
		x=x - casePointe.x;
		y=y - casePointe.y;
		switch (x){
		case -1:
			if (y==-1){
				direction =0;
			}else if(y==0){
				direction =1;
			}else if(y==1){
               	direction =2;
			}
			break;
		case 0:
			if (y==-1){
				direction =7;
			}else if(y==1){
				direction =3;
			}			
			break;
		case 1:
			if (y==-1){
				direction =6;
			}else if(y==0){
				direction =5;
			}else if(y==1){
               	direction =4;
			}
			break;
			}
		}
//On met a jour la direction
(*puceron).directionP = direction;
}

int bordsSuppr(int x){
	if(x>(SIZE -1)){    
		x=0;
	}else if(x<0){
		x=(SIZE -1);
	}

	return x;
}

int boolOrientationP(Puceron puceron,Puceron* matricePuceron[SIZE][SIZE],int maturite[SIZE][SIZE]){
	int orientation =0;

	int x=(puceron).coordP.x;
	int y=(puceron).coordP.y;


	switch ((puceron).directionP){           //on recupere la case devant le puceron, dépend de sa position et de sa direction
		case 0:   
			x=x-1;            
			y=y-1;
			break;
		case 1: 
			x=x-1;
			break;
		case 2:
			y++;
			x=x-1;
			break;
		case 3:
			y++;
			break;
		case 4:
			x++;
			y++;
			break;
		case 5:
			x++;
			break;
		case 6:
			y=y-1;
			x++;
			break;
		case 7:
			y=y-1;
			break;
		}

	x=bordsSuppr(x);
	y=bordsSuppr(y);

	if((maturite[x][y]!=20)||(matricePuceron[x][y]!=NULL)){   //Si il n'y a pas de tomate mure dans sa direction ou la case n'est pas libre
		orientation =1;										 //Il faut le réorienter
	}


	return orientation;
}






