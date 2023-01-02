#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <C:\Users\Rachel\Documents\M1\Info 1\projet\SDL-release-2.26.1\include\SDL.h>
 
#define TAILLE_FENETRE 900
#define DIVISEUR 1
 
int main(int argc, char *argv[])
{
    FILE *init = NULL;
 
    int bloc = 0;
    int continuer = 1;
    double cote = 0;
 
    int i = 0;
    int j = 0;
 
    SDL_Rect posBloc;
    SDL_Surface *ecran = NULL;
    SDL_Surface *square = NULL;
    SDL_Event event;
 
    posBloc.x = 0;
    posBloc.y = 0;
 
    init = fopen("init.txt", "r");
    if(init != NULL)
    {
        fscanf(init, "%d", &bloc);
        bloc += (bloc - 1);
        cote = TAILLE_FENETRE / bloc;
        fclose(init);
    }
    else
        exit(EXIT_FAILURE);
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(cote * bloc, (cote * bloc) / DIVISEUR, 3, SDL_HWSURFACE);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 3));
    if(ecran == NULL)
        exit(EXIT_FAILURE);
 
    square = SDL_CreateRGBSurface(SDL_HWSURFACE, cote, cote / DIVISEUR, 3, 0, 0, 0, 0);
    SDL_FillRect(square, NULL, SDL_MapRGB(ecran->format, 3, 0, 0));
    if(square == NULL)
        exit(EXIT_FAILURE);
 
    for(i = 0 ; i <= bloc; i ++)
    {
        for(j = 0 ; j <= bloc; j++)
        {
            if(abs(i + j) % 2 == 0)
            {
                posBloc.x = j * cote;
                posBloc.y = i * cote / DIVISEUR;
                SDL_BlitSurface(square, NULL, ecran, &posBloc);
            }
        }
    }
    SDL_Flip(ecran);
 
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
     
    SDL_FreeSurface(square);
    SDL_Quit();
    return 0;
}