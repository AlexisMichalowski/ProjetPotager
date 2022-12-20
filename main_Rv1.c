#include "fonctionsPucerons.h"


int main(){

srand(time(NULL));  //seed pour les nombres aléatoires


//initialisation
char potager[SIZE][SIZE];
int maturite[SIZE][SIZE];

initialiserMaturite(maturite);
apparanceTomate(maturite,potager);
//Affichage du potager avant introduction des pucerons
printf("Etat Initial \n");
affichePotager(potager);
//creation des pucerons vide
EnsemblePuceron ensemblePuceron;
ensemblePuceronVide(&ensemblePuceron);

Puceron* matricePuceron[SIZE][SIZE];    //Contient des pointeurs sur les pucerons  
initialiserMatricePuceron(matricePuceron);

insertionPuceron(matricePuceron,&ensemblePuceron,20);       //20 trop eleve, >200 000 tours   + changer cette fonction pour choisir precisement le nombre de puceron a inserer 

int tour=0; //comptabilise le nombre de tours
while (ensemblePuceron.nombreP >0){    //on simule tant qu'il y a des pucerons    
    //NIVEAU 1

    //mise a jour etat Tomate, toutes les tomates grandissent

    maturiteTomate(maturite); 
    apparanceTomate(maturite,potager); //Le potager ne contient que les tomates au debut du tour, les pucerons seront ajouté un par un

    for(int i=0;i<ensemblePuceron.nombreP;i++){    //Pour chaque pucerons present dans l'ensemble au début du tour, les naissants s'activeront a partir du prochain tour
        //Deplacement Pucerons
        deplacementPuceron(matricePuceron,&ensemblePuceron.tabP[i]);
                        
        //nourrissement puceron
        puceronMangeTomate(&ensemblePuceron.tabP[i],maturite);

        //reproduction Puceron
        reproductionPuceron(&ensemblePuceron,&ensemblePuceron.tabP[i],matricePuceron);

        //Mourir /Vieillissement puceron
        vieillissementPuceron(&ensemblePuceron,&ensemblePuceron.tabP[i],matricePuceron);

        //s'orienter? 
        orientationPuceron(&ensemblePuceron,&ensemblePuceron.tabP[i],matricePuceron,maturite);
        //Si le puceron n'as pas manger de tomates, il change de position au hasard

        //Affichage du puceron dans le potager
        potager[ensemblePuceron.tabP[i].coordP.x][ensemblePuceron.tabP[i].coordP.y]=charDirection(ensemblePuceron.tabP[i].directionP);

    }

    //NIVEAU2 
    //a nouveau une boucle pour les coccinelles


    //Affichage et fin du tour

    tour++;
    printf("Etat à la fin du tour n %d \n",tour);
    affichePotager(potager);
    
   

}












return 0;
}