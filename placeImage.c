#include "SDL2/SDL_image.h"

void analysePotager(char potager[SIZE][SIZE]); 
void placeImage(SDL_Renderer* renderer,char* path,int x,int y);


void analysePotager(char potager[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE],SDL_Renderer* renderer){
  for (int i=0;i<SIZE;i++){
     for (int j=0;j<SIZE;j++){
       if(matriceCoccinelle[i][j]!=NULL){ //si c'est une coccinelle
	  if (matriceCoccinelle[i][j]->direction = 0) {
              placeImage(renderer,"path/to/image/coccinelle/direction0",i*30,j*30)
          }   /* continuer pour les directions*/
	else if(matricePuceron[i][j]!=NULL){ //si c'est un puceron
	 placeImage(renderer,"path/to/image/puceron",i*30,j*30)
       }           /*equivalent pour tomate*/
     }
  }
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
