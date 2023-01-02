# ifndef HEADER_INTERFACEGRAPHIQUE
# define HEADER_INTERFACEGRAPHIQUE

#include "fonctionsPotager.h"
#include "fonctionsPucerons.h"
#include "fonctionsCoccinelles.h"

#include <SDL2/SDL.h>

void quitteSDL(SDL_Window *window,SDL_Renderer *renderer);
/*Quitte SQL et detruit la fenetre et le renderer passé en argument*/

void damier(SDL_Renderer *renderer);
/*Dessine un damier de taille 30x30 avec chaque case ayant pour taille 30x30*/

void placeImage(SDL_Renderer* renderer, char* path,int x,int y);
/*place l'image "path" a la position (x,y) du renderer*/

void affichePotagerGraphique(SDL_Renderer *renderer,int maturite[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE]);
/*Affiche le potager dans le renderer avec les bonnes images a chaque case et les tomates avec un gradient de rouge*/

void affichePotagerGraphiqueTomates(SDL_Renderer *renderer,int maturite[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE]);

void affichePotagerGraphiqueEntites(SDL_Renderer *renderer,int maturite[SIZE][SIZE],Puceron* matricePuceron[SIZE][SIZE],Coccinelle* matriceCoccinelle[SIZE][SIZE]);
#endif