#include "fonctionsCoccinelles.h"

void ensembleCoccinelleVide(EnsembleCoccinelle *ensembleC){
	(*ensembleC).nombreC =0;
	}

void ajouterCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle c){
    if((*ensembleC).nombreC < MAXC){
	    	c.index = (*ensembleC).nombreC;
		    (*ensembleC).tabC[(*ensembleC).nombreC] = c;
		    (*ensembleC).nombreC = (*ensembleC).nombreC + 1;
	}

}

int vieillissementCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle *coccinelle,Coccinelle* matriceCoccinelle[SIZE][SIZE]){
	(*coccinelle).ageC ++ ;
	int mort = 0;   //booleen qui vaut 0 si la coccinelle reste en vie, 1 sinon
	if ((*coccinelle).ageC >= 20){
		mortCoccinelle(ensembleC, *coccinelle,matriceCoccinelle);
		mort =1;
	}
	return mort;
}

void mortCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle coccinelle,Coccinelle* matriceCoccinelle[SIZE][SIZE]){
	(*ensembleC).tabC[(coccinelle).index] = (*ensembleC).tabC[(*ensembleC).nombreC - 1] ;  //On remplace la coccinelle morte par la derniere coccinelle de l’ensemble
	((*ensembleC).tabC[(coccinelle).index]).index = (coccinelle).index ; 					    //On met à jour l’index de la coccinelle déplacée
	
	(*ensembleC).nombreC = (*ensembleC).nombreC -1 ;                                    //On met a jour le nombre de coccinelle de l'ensemble
	matriceCoccinelle[coccinelle.coordC.x][coccinelle.coordC.y] =NULL;							//On enleve la coccinelle de la matrice de coccinelles				
}

void initialiserMatriceCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE]){
    for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			matriceCoccinelle[i][j]=NULL;
			}
		}
}

void insertionCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE],EnsembleCoccinelle *ensembleC,int nbCoccinelles){
    int nbCoccinelleAjoute=0;
	int i=0;
	int j=0;
	Coccinelle coccinelle;
	coccinelle.ageC =0;    			//les pucerons ont 0 tours d'age a l'initalisation
	coccinelle.nbPuceronsMange=0;  //ils n'ont aussi pas manger de tomates

	while(nbCoccinelleAjoute < nbCoccinelles){  //Tant qu'il n'y a pas le nombre de pucerons voulus
		//On prend une position au hasard dans le potager
		i=rand()%30;
		j=rand()%30;
		//si il n'y a pas de pucerons a la position indiqué on en ajoute un
		if(matriceCoccinelle[i][j] == NULL){
			coccinelle.coordC.x=i;
			coccinelle.coordC.y=j;
			coccinelle.directionC = rand()%8;  //la direction initiale du puceron sera aléatoire et comprise entre 0 et 7, car il y a 8 cases autour du puceron
			ajouterCoccinelle(ensembleC,coccinelle);
			nbCoccinelleAjoute ++;

			/*Récupère le pointeur sur la puceron qui vient d’être ajouté*/
			matriceCoccinelle[i][j]= retourneCoccinelle(ensembleC,(*ensembleC).nombreC-1);
		}
	}
}

Coccinelle* retourneCoccinelle(EnsembleCoccinelle *ensembleC,int i){
    Coccinelle* coccinelle;
	coccinelle =NULL;
	if (i < (*ensembleC).nombreC){
		coccinelle = &((*ensembleC).tabC[i]);   
		} 
	return coccinelle;
}

int coccinelleMangePuceron(EnsemblePuceron *ensembleP, Coccinelle *coccinelle,Puceron* matricePuceron[SIZE][SIZE]){  
    int aMange =0;
    if((matricePuceron[(*coccinelle).coordC.x][(*coccinelle).coordC.y])!=NULL){ //Si il y a un puceron à la même position que la coccinelle
    
        mortPuceron(ensembleP,*matricePuceron[(*coccinelle).coordC.x][(*coccinelle).coordC.y],matricePuceron); 
        (*coccinelle).nbPuceronsMange ++;   
        aMange=1;
    }
    return aMange;

}

void deplacementCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE],Coccinelle *coccinelle){
    int x = (*coccinelle).coordC.x;
	int y = (*coccinelle).coordC.y;
	int direction =(*coccinelle).directionC;

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

	//Les coordonnées de la coccinelle et la matrice sont mis à jour seulement si l'emplacement est libre, sinon le deplacement n'aura pas lieu
	if(matriceCoccinelle[x][y] ==NULL){   
		matriceCoccinelle[(*coccinelle).coordC.x][(*coccinelle).coordC.y] =NULL;  //Le puceron bouge, son ancienne place devient libre
		(*coccinelle).coordC.x =x;
		(*coccinelle).coordC.y =y;
		matriceCoccinelle[x][y] =coccinelle;
	}

}

void reproductionCoccinelle(EnsembleCoccinelle *ensembleC,Coccinelle *coccinelle,Coccinelle* matriceCoccinelle[SIZE][SIZE]){
    if ((*coccinelle).nbPuceronsMange == 3) {
        int x=(*coccinelle).coordC.x;
        int y=(*coccinelle).coordC.y;
       

        Coccinelle coccinelle2;
        coccinelle2.ageC=0;
        coccinelle2.directionC=rand()%8;
        coccinelle2.nbPuceronsMange=0;
        
        //gerer les coordonnées du nouveau né
        coccinelle2.coordC = caseAdjacenteLibreAleatoireCoccinelle(matriceCoccinelle,x,y);
           
        if(coccinelle2.coordC.x != -1){    //Si il y a une case adjacente vide, sinon pas de naissance
            ajouterCoccinelle(ensembleC,coccinelle2);  //l'index du puceron est gérer dans cette fonction
            /*Récupère le pointeur sur la puceron qui vient d’être ajouté*/
            matriceCoccinelle[x][y]= retourneCoccinelle(ensembleC,(*ensembleC).nombreC-1);
        }
        (*coccinelle).nbPuceronsMange = 0; //on reinitialise le compteur si le puceron s'est reproduit
    }

}

Coord caseAdjacenteLibreAleatoireCoccinelle(Coccinelle* matriceCoccinelle[SIZE][SIZE],int x,int y){    
	Coord coordTab[9];
	Coord coord;
	coord.x=-1;
	coord.y=-1;
	int nbCaseLibre =0;
	
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			if(matriceCoccinelle[bordsSuppr(x+i)][bordsSuppr(y+j)]==NULL){  //gere les bords supprimés
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

void orientationCoccinelle(Coccinelle* coccinelle,Puceron* matricePuceron[SIZE][SIZE]){
	int direction= (*coccinelle).directionC;
	int x = (*coccinelle).coordC.x;
	int y = (*coccinelle).coordC.y;
	Coord cible;
	cible.x=5+x;
	cible.y=5+y;


	int rayon =3;
	int distance =0;
	//on parcourt toutes les cases dans un rayon de 3 blocs de la coccinelle
	for(int i=-3;i<4;i++){
		for(int j=-3;j<4;j++){
			if((matricePuceron[bordsSuppr(x+i)][bordsSuppr(y+j)] != NULL) && ((x!=x+i)||(y!=y+j))){ 
			/*si il y a un puceron dans une des cases a un rayon de 3 blocs, gestion des bords supprimés + on ne regarde pas la case ou se situe la coccinnelle*/
				distance= (abs(i)+abs(j)/2)+1/2;   //comme la distance est un int, vas prendre la valeur entière seulement, permettant d'avoir la valeur correspondant à l'écart entre la case de la coccinelle et du puceron

				if(rayon >= distance){
					rayon = distance;
					cible.x=x+i;
					cible.y=y+j;
				}
			}
		}
	}

	//Position relative du puceron par rapport a la coccinelle
	x=cible.x -x;
	y=cible.y-y;
	//Calcul de la direction en fonction de la position du puceron cible, direction en fonction de la postion du pucerons 
	if(x==5){
		direction =rand()%8;  //Si x est toujours ==5, il n'y a pas de puceron dans un rayon de 3 case, donc la coccinelle s'oriente au hasard
	}else if((x<=-2 && y<=-2) || ((x == -1 ) && (y == -1))){
		direction = 0;
	}else if((x>=2 && y<=-2) || ((x == 1 ) && (y == -1))){
		direction =2;
	}else if((x>=2 && y>=2) || ((x == 1 ) && (y == 1))){
		direction = 4;
	}else if((x<=-2 && y>=2) || ((x == -1 ) && (y == 1))){
		direction = 6;
	}else if((y<=-2) || ((x == 0 ) && (y == -1))){
		direction = 1;
	}else if((x>=2) || ((x == 1 ) && (y == 0))){
		direction = 3;
	}else if((y>=2) || ((x == 0 ) && (y == 1))){
		direction =5;
	}else{
		direction =7;
	}

//On met a jour la direction
(*coccinelle).directionC = direction;

}

void affichePotagerCouleur(char potager[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE]){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(matriceCoccinelle[i][j]!=NULL){ //si c'est une coccinelle on met du rouge
				red();
			}else if(matricePuceron[i][j]!=NULL){ //si c'est un puceron du vert
				green();
			}
			printf("%c ",potager[i][j]);   //on affiche le charactère
			black();                      //on remet la couleur en noir
			}
			printf("\n");
		}

	}