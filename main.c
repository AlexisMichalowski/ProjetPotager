#include "fonctionsPotager.h"
#include "fonctionsPucerons.h"
#include "fonctionsCoccinelles.h"

int main(){

    //initialisation
    srand(time(NULL));  //seed pour les nombres aléatoires

    //Choix du niveau (1 ou 2)
    printf("Quel niveau voulez-vous Simulez? \n Saississez un nombre entre 1 et 2:\n");
    int niveau=0;
    scanf("%d",&niveau);
    while (!(niveau == 1 || niveau ==2)){
        printf("Veuillez saisir un nombre entre 1 et 2: \n");
        scanf("%d",&niveau);
    }
    
    //Initialisation potager et tomates
    char potager[SIZE][SIZE];
    int maturite[SIZE][SIZE];
    initialiserMaturite(maturite);
    apparanceTomate(maturite,potager);

    //Affichage du potager avant introduction des pucerons
    printf("Etat Initial \n");
    affichePotager(potager);


    //creation de l'ensemble de pucerons vide se fait pour le niveau 1 et 2
    EnsemblePuceron ensemblePuceron;
    ensemblePuceronVide(&ensemblePuceron);

    Puceron* matricePuceron[SIZE][SIZE];        //Contient des pointeurs sur les pucerons  
    initialiserMatricePuceron(matricePuceron);

    //Insertion des pucerons
    insertionPuceron(matricePuceron,&ensemblePuceron,20);      //on insere 20 pucerons

    //on peut pas mettre dans le if sinon suppression en sortant du if 
    EnsembleCoccinelle ensembleCoccinelle;
    Coccinelle* matriceCoccinelle[SIZE][SIZE];
    ensembleCoccinelleVide(&ensembleCoccinelle);
    initialiserMatriceCoccinelle(matriceCoccinelle);
    if(niveau==2){ //On insere les coccinelles ssi niveau 2
        insertionCoccinelle(matriceCoccinelle,&ensembleCoccinelle,10); //on insere 10 coccinelles
    }

    //Declaration des variables utiles

    int tour=0; //comptabilise le nombre de tours

    int i =0; //compteur pour se deplacer dans le tableau de pucerons
    int mort =0; //Permettra de savoir si un puceron va mourir ou non, fonctionne comme un booléen, 0 si puceron vivant, 1 sinon

    while (ensemblePuceron.nombreP >0 ){    //on simule tant qu'il y a des pucerons    
        //NIVEAU 1

        //mise a jour etat Tomate, toutes les tomates grandissent
        maturiteTomate(maturite); 
        apparanceTomate(maturite,potager); //Le potager ne contient que les tomates au debut du tour, les pucerons seront ajouté un par un, tout comme les coccinelles si il y en a

        i=0;
        while(i<ensemblePuceron.nombreP){    //Pour chaque pucerons present dans l'ensemble, les naissants se deplaceront des le tour ou ils arrivent
        
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
        
        if(niveau ==2){  //NIVEAU2 
            i=0;
            while(i < ensembleCoccinelle.nombreC){  //a nouveau une boucle pour les coccinelles
                //deplacement coccinelles 
                deplacementCoccinelle(matriceCoccinelle,&ensembleCoccinelle.tabC[i]);

                //Nourrissement Coccinelle
                coccinelleMangePuceron(&ensemblePuceron,&ensembleCoccinelle.tabC[i],matricePuceron);

                //reproduction Coccinelle
                reproductionCoccinelle(&ensembleCoccinelle,&ensembleCoccinelle.tabC[i],matriceCoccinelle);

                mort=vieillissementCoccinelle(&ensembleCoccinelle,&ensembleCoccinelle.tabC[i],matriceCoccinelle);

                if(mort ==0){//si la coccinelle n'est pas morte
                    //Orientation
                    orientationCoccinelle(&ensembleCoccinelle.tabC[i],matricePuceron);
                    //Affichage
                    potager[ensembleCoccinelle.tabC[i].coordC.x][ensembleCoccinelle.tabC[i].coordC.y]=charDirection(ensembleCoccinelle.tabC[i].directionC);
                    i++;
                }

            }
        }
        //Affichage et fin du tour
        tour++;
        printf("Etat à la fin du tour n %d \n",tour);
        //affichePotager(potager); 
        affichePotagerCouleur(potager,matricePuceron,matriceCoccinelle);
    }

    return 0;
}
