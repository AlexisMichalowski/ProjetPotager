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

#endif