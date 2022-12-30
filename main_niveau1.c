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

//creation de l'ensemble de pucerons vide
EnsemblePuceron ensemblePuceron;
ensemblePuceronVide(&ensemblePuceron);

Puceron* matricePuceron[SIZE][SIZE];    //Contient des pointeurs sur les pucerons  
initialiserMatricePuceron(matricePuceron);

//Insertion des pucerons
insertionPuceron(matricePuceron,&ensemblePuceron,20);      //on insere 20 pucerons

//Declaration des variables utiles

int tour=0; //comptabilise le nombre de tours

int i =0; //compteur pour se deplacer dans le tableau de pucerons
int mort =0; //Permettra de savoir si un puceron va mourir ou non, fonctionne comme un booléen, 0 si puceron vivant, 1 sinon

while (ensemblePuceron.nombreP >0){    //on simule tant qu'il y a des pucerons    
    //NIVEAU 1

    //mise a jour etat Tomate, toutes les tomates grandissent
    maturiteTomate(maturite); 
    apparanceTomate(maturite,potager); //Le potager ne contient que les tomates au debut du tour, les pucerons seront ajouté un par un

    i=0;
    while(i<ensemblePuceron.nombreP){    //Pour chaque pucerons present dans l'ensemble au début du tour, les naissants s'activeront a partir du prochain tour
        
        //Deplacement Pucerons
        deplacementPuceron(matricePuceron,&ensemblePuceron.tabP[i]);
                        
        //nourrissement puceron
        puceronMangeTomate(&ensemblePuceron.tabP[i],maturite);

        //reproduction Puceron
        reproductionPuceron(&ensemblePuceron,&ensemblePuceron.tabP[i],matricePuceron);

        //Mourir /Vieillissement puceron
        mort = vieillissementPuceron(&ensemblePuceron,&ensemblePuceron.tabP[i],matricePuceron);

        if(mort ==0){  //si le puceron est toujours vivant

            //orientation
            if(boolOrientationP(ensemblePuceron.tabP[i],matricePuceron,maturite)==1){     //si la case devant le puceron ,n'est pas libre ou ne contient pas de tomates mur, alors on l'oriente!
                orientationPuceron(&ensemblePuceron.tabP[i],matricePuceron,maturite);
            }
            

            //Affichage du puceron dans le potager
            potager[ensemblePuceron.tabP[i].coordP.x][ensemblePuceron.tabP[i].coordP.y]=charDirection(ensemblePuceron.tabP[i].directionP);

            /*On passe a l'indice suivant UNIQUEMENT si le puceron est vivant, si il es mort on garde le même indice, 
            car on a intervertit le puceron a l'indice ensemblePuceron.nombreP -1 avec celui a l'indice i, et il faut donc que celui a l'indice i évolue */
            i++; 

        }
        

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
