#include "SDL2/SDL_image.h"

void analysePotager(char potager[SIZE][SIZE]); 
void placeImage(SDL_Renderer* renderer,char* path,int x,int y);


void analysePotager(char potager[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE],SDL_Renderer* renderer){
  for (int i=0;i<SIZE;i++){
     for (int j=0;j<SIZE;j++){
       if(matriceCoccinelle[i][j]!=NULL){ //si c'est une coccinelle
	  if (matriceCoccinelle[i][j]->direction = 0) {
              placeImage(renderer,"path/to/image/coccinelle/direction0",i*30,j*30)
          }
			 }else if(matricePuceron[i][j]!=NULL){ //si c'est un puceron
				 if 
         placeImage(renderer,"path/to/image/puceron",i*30,j*30)
       }
     }
  }
}

void placeImage(SDL_Renderer* renderer, char* path,int x,int y) {    
  tmp = IMG_Load("nom_de_l_image");
  if(NULL == tmp)
   {
    fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
    goto Quit;
}
texture = SDL_CreateTextureFromSurface(renderer, tmp);
SDL_FreeSurface(tmp); /* On libère la surface, on n’en a plus besoin */
if(NULL == texture)
{
    fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
    goto Quit;
}
SDL_Rect destination;
destination.x = xPos;
destination.y = yPos;
destination.w = yourImageWidth;
destination.h = yourImageHeight;
SDL_RenderCopy(renderer, texture, NULL, &destination);
}
