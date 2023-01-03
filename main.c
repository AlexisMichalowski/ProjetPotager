#include "fonctionsPotager.h"
#include "fonctionsPucerons.h"
#include "fonctionsCoccinelles.h"
#include "interfaceGraphique.h"

int main(int argc, char* argv[]){

    //initialisation
    srand(time(NULL));  //seed pour les nombres aléatoires

    //Choix du niveau (1 ou 2)
    printf("Quel niveau voulez-vous simuler? \n Saississez un nombre entre 1 et 2:\n");
    int niveau=0;
    scanf("%d",&niveau);
    while (!(niveau == 1 || niveau ==2)){
        printf("Veuillez saisir un nombre entre 1 et 2: \n");
        scanf("%d",&niveau);
    }
    //Choix de l'affichage
    printf("Quel affichage souhaitez-vous?\n 1)Console \n 2)Graphique\n");
    int affichage =0;
    scanf("%d",&affichage);
    while (!(affichage == 1 || affichage ==2)){
        printf("Veuillez saisir un nombre entre 1 et 2: \n");
        scanf("%d",&affichage);
    }
    //Si affichage graphique souhaité, initialisation et création de la fenetre
    SDL_Window *window = NULL; //on doit declaré en dehors du if sinon variable interne au if
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;
    if(affichage ==2){
        if(0 != SDL_Init(SDL_INIT_VIDEO)){
            fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
            goto Quit;
        }
    
        //creation fenetre
        window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,   //fenetre carrée pour potager
                                    900,900, SDL_WINDOW_SHOWN);
        //gestion erreur creation
        if(NULL == window){
            fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
            goto Quit;
        }   
        //Creation renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        //erreur renderer
        if(NULL == renderer){
            fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
            goto Quit;
        }
        //remplissage
        if(0 != SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)){ //set la couleur sur noir
            fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
            goto Quit;
        }
    
        if(0 != SDL_RenderClear(renderer)){
            //colorie le renderer avec la couleur courante
            fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
            goto Quit;
        }
    }




    //Initialisation potager et tomates
    char potager[SIZE][SIZE];
    int maturite[SIZE][SIZE];
    initialiserMaturite(maturite);
    apparanceTomate(maturite,potager);

    //Initialisation des ensembles
    //Pucerons
    EnsemblePuceron ensemblePuceron;       
    Puceron* matricePuceron[SIZE][SIZE]; //Contient des pointeurs sur les pucerons  
    ensemblePuceronVide(&ensemblePuceron);         
    initialiserMatricePuceron(matricePuceron);
    //Coccinelles
    EnsembleCoccinelle ensembleCoccinelle;
    Coccinelle* matriceCoccinelle[SIZE][SIZE];  //contient des pointeurs sur les coccinelles
    ensembleCoccinelleVide(&ensembleCoccinelle);
    initialiserMatriceCoccinelle(matriceCoccinelle);

    //Affichage du potager avant introduction des pucerons
    
    if(affichage ==1){
        printf("Etat Initial \n");
        affichePotager(potager);
    }else{
        damier(renderer);    //Initialisation de la fenêtre
        affichePotagerGraphiqueTomates(renderer,maturite,matricePuceron,matriceCoccinelle);
        SDL_RenderPresent(renderer);//MaJ de l'écran
        SDL_Delay(2000); //attente de 2 sec
    }

    //Insertion des pucerons
    insertionPuceron(matricePuceron,&ensemblePuceron,20);      //on insere 20 pucerons
    //Insertions Coccinelles
    if(niveau==2){ //On insere les coccinelles ssi niveau 2
        insertionCoccinelle(matriceCoccinelle,&ensembleCoccinelle,10); //on insere 10 coccinelles
    }

    //Declaration des variables utiles
    int tour=0; //comptabilise le nombre de tours
    int i =0; //compteur pour se deplacer dans les tableaux d'ensembles
    int mort =0; //Permettra de stocker la mort ou non des individus(pucerons et coccinelles), fonctionne comme un booléen, 0 si vivant, 1 sinon

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
        if(affichage ==1){
            printf("Etat à la fin du tour n %d \n",tour);
            //affichePotager(potager); 
            affichePotagerCouleur(potager,matricePuceron,matriceCoccinelle);
        }else{
            damier(renderer);    //Support du potager
            affichePotagerGraphiqueTomates(renderer,maturite,matricePuceron,matriceCoccinelle);
            affichePotagerGraphiqueEntites(renderer,maturite,matricePuceron,matriceCoccinelle);
            SDL_RenderPresent(renderer);//MaJ de l'écran
            SDL_Delay(2000); //attente de 2 sec
        }
    }

    statut = EXIT_SUCCESS;
    Quit:
    quitteSDL(window,renderer);
    return statut;
}
