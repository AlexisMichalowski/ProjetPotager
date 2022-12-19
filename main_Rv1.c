#include "fonctionsPucerons.h"


int main(){

srand(time(NULL));  //seed pour les nombres aléatoires

int tour=0; //comptabilise le nombre de tours
//initialisation
char potager[SIZE][SIZE];
int maturite[SIZE][SIZE];

initialiserMaturite(maturite);
apparanceTomate(maturite,potager);
//Affichage du potager avant introduction des pucerons
affichePotager(potager);
//cretion des pucerons vide
EnsemblePuceron ensemblePuceron;
ensemblePuceronVide(&ensemblePuceron);

Puceron* matricePuceron[SIZE][SIZE];    //Contient des pointeurs sur les pucerons  
initialiserMatricePuceron(matricePuceron);



insertionPuceron(matricePuceron,&ensemblePuceron,20);













return 0;
}