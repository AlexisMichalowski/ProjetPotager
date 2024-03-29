#include "interfaceGraphique.h"

void quitteSDL(SDL_Window *window,SDL_Renderer *renderer){
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit(); 
}


void damier(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //set la couleur sur blanc
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

void placeImage(SDL_Renderer* renderer, char* path,int x,int y) {   
  SDL_Surface *tmp = NULL;
  SDL_Texture *texture = NULL;
  tmp = SDL_LoadBMP(path);
  if(NULL == tmp){
    fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
   }
  texture = SDL_CreateTextureFromSurface(renderer, tmp);
  SDL_FreeSurface(tmp);     
  if(NULL == texture){
    fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
  }
  SDL_Rect destination;
  destination.x = x;
  destination.y = y;
  destination.w = 30;
  destination.h = 30;
  SDL_RenderCopy(renderer, texture, NULL, &destination);
}


void affichePotagerGraphiqueTomates(SDL_Renderer *renderer,int maturite[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE]){
    SDL_Rect rect;
    rect.w = 25;
    rect.h = 25;
    for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
            //Gradient de rouge pour la tomate
            rect.y = i*30 +2;
            rect.x = j*30 +2;
            SDL_SetRenderDrawColor(renderer, 255, 255-(10*(maturite[i][j])+55), 255-(10*(maturite[i][j])+55), 255);
			SDL_RenderFillRect(renderer,&rect);          
		}
	}

}
void affichePotagerGraphiqueEntites(SDL_Renderer *renderer,int maturite[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE]){
    int direction;
    for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			if(matriceCoccinelle[j][i]!=NULL){ //si c'est une coccinelle on affiche une coccinnelle
				direction=(*matriceCoccinelle[j][i]).directionC;
                //Afficher Coccinelle correspondant a direction C à la pos (i*30,j*30)
            	switch (direction){           //La position du puceron change en fonction de sa direction
		            case 0:   
			            placeImage(renderer,"./imagesProjet/c0.bmp",i*30,j*30);
			            break;
		            case 1: 
			            placeImage(renderer,"./imagesProjet/c1.bmp",i*30,j*30);
			            break;
		            case 2:
			            placeImage(renderer,"./imagesProjet/c2.bmp",i*30,j*30);
			            break;
		            case 3:
			            placeImage(renderer,"./imagesProjet/c3.bmp",i*30,j*30);
			            break;
		            case 4:
		        	    placeImage(renderer,"./imagesProjet/c4.bmp",i*30,j*30);
		        	    break;
	                case 5:
		        	    placeImage(renderer,"./imagesProjet/c5.bmp",i*30,j*30);
			            break;
		            case 6:
			            placeImage(renderer,"./imagesProjet/c6.bmp",i*30,j*30);
			            break;
		            case 7:
			            placeImage(renderer,"./imagesProjet/c7.bmp",i*30,j*30);
			            break;   
                    }
			}else if(matricePuceron[j][i]!=NULL){ //si c'est un puceron du vert
                direction=(*matricePuceron[j][i]).directionP;
                //Afficher puceron correspondant a directionP à la pos (i*30,j*30)
                switch (direction){           //La position du puceron change en fonction de sa direction
		            case 0:   
			            placeImage(renderer,"./imagesProjet/p0.bmp",i*30,j*30);
			            break;
		            case 1: 
			            placeImage(renderer,"./imagesProjet/p1.bmp",i*30,j*30);
			            break;
		            case 2:
			            placeImage(renderer,"./imagesProjet/p2.bmp",i*30,j*30);
			            break;
		            case 3:
			            placeImage(renderer,"./imagesProjet/p3.bmp",i*30,j*30);
			            break;
		            case 4:
		        	    placeImage(renderer,"./imagesProjet/p4.bmp",i*30,j*30);
		        	    break;
	                case 5:
		        	    placeImage(renderer,"./imagesProjet/p5.bmp",i*30,j*30);
			            break;
		            case 6:
			            placeImage(renderer,"./imagesProjet/p6.bmp",i*30,j*30);
			            break;
		            case 7:
			            placeImage(renderer,"./imagesProjet/p7.bmp",i*30,j*30);
			            break;
                }
			}
                        

		}
	}

}
