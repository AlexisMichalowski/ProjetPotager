#include "interfaceGraphique.h"

void quitteSDL(SDL_Window *window,SDL_Renderer *renderer){
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit(); 
}


void damier(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 120);
	SDL_Rect rects[450];
	size_t i = 0;
	for(i = 0; i < 450; i++){   
		rects[i].w = 30;
		rects[i].h = 30;
		rects[i].x = 60*(i%15) +30 * ((i / 15) % 2); 
		rects[i].y = 30 * (i / 15);
	}
	SDL_RenderFillRects(renderer, rects, 450); 
}

void affichePotagerGraphique(SDL_Renderer *renderer,int maturite[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE]){
    int direction;
    SDL_Rect rect;
    rect.w = 25;
    rect.h = 25;

    for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
            //Gradient de rouge pour la tomate
            rect.x = i*30 +2;
            rect.y = j*30 +2;
            SDL_SetRenderDrawColor(renderer, 255, 255-(10*(maturite[i][j])+55), 255-(10*(maturite[i][j])+55), 255);
			SDL_RenderFillRect(renderer,&rect); 


			if(matriceCoccinelle[i][j]!=NULL){ //si c'est une coccinelle on affiche une coccinnelle
				direction=(*matriceCoccinelle[i][j]).directionC;
                

			}else if(matricePuceron[i][j]!=NULL){ //si c'est un puceron du vert
                direction=(*matricePuceron[i][j]).directionP;
				
			}
                        

			}
		}

}

int main()
{
	//Initialisation
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO)){
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    
     //creation fenetre
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,   //fenetre carrée pour potager, SIZE*20 par exemple
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
    if(0 != SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)){ //set la couleur sur blanc
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }
    
    if(0 != SDL_RenderClear(renderer)){
        //le renderer avec la couleur courante
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        goto Quit;
    }
   
	//Damier 30x30
    damier(renderer);    //Initialisation de la fenêtre
	SDL_RenderPresent(renderer);//MaJ de l'écran
    



   
    SDL_Delay(5000); //attente de 5 sec
    
    
    statut = EXIT_SUCCESS;
Quit:
    quitteSDL(window,renderer);
    return statut;
}