
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Quit();
    return EXIT_SUCCESS;
}

/*permet d'initialiser la console, de vérifier que ca s'est bien passé puis de quitter, sinon afficher message d'erreur*/  



#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int statut = EXIT_FAILURE;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        goto Quit;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        goto Quit;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        goto Quit;
    }
    
    statut = EXIT_SUCCESS;
    SDL_Delay(3000);

Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}

/*pareil mais code complété pour ouvrir une fenetere graphique, important de toujours détruire la fenetre après */

/* création du potager par un rectangle avec la fonction SDL_RECT qui a 4 arguments 
x représente l’abscisse du coin en haut à gauche du rectangle ;
y représente l’ordonnée du coin en haut à gauche du rectangle ;
w représente la largeur du rectangle ;
h représente la hauteur du rectangle.*/

/*dès qu'on passe 1 tour il faut systematiquement mettre a jour le render avec SDL_RenderPresent */

SDL_Rect rect = {0,30,30,30};
SDL_RenderDrawRect(renderer, &rect); 
SDL_RenderPresent(renderer);

/*le code pour initialiser le potager comme un rectangle de 30*30 et mettre a jour la fenetre*/


SDL_Rect rect[50];
size_t i = 0;
for(i = 0; i < 50; i++)
{   
    rect[i].w = 50;
    rect[i].h = 50;
    rect[i].x = 100 * (i % 5) + 50 * ((i / 5) % 2);
    rect[i].y = 50 * (i / 5);
}
SDL_RenderFillRects(renderer, rect, 50); 
SDL_RenderPresent(renderer);

/*création d'un damier 500*500 en initialisant 100 cases de 50*50 */
            
SDL_Rect rect[3];
size_t i = 0;
for(i = 0; i < 3; i++)
{   
    rect[i].w = 3;
    rect[i].h = 3;
    rect[i].x = 10 * (i % 0.3) + 3 * ((i / 0.3) % 2);
    rect[i].y = 3 * (i / 0.3);
}
SDL_RenderFillRects(renderer, rect, 3); 
SDL_RenderPresent(renderer);            
/*j'ai essayé de faire pareil pour notre 30*30 */



/*permet de charger une image dans la fenetre, pour ca on est obligés de l'associer a une texture */
/*on doit pouvoir en changer les dimensions mais j'ai pas trop compris comment, c'est expliqué après*/
SDL_Surface *tmp = NULL; 
SDL_Texture *texture = NULL;
tmp = SDL_LoadBMP("nom_de_l_image");
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





/*EVENEMENTS*/


void SDL_PumpEvents(void)    /*ajoute les evenements dans une file*/

SDL_WINDOWEVENT(window)            /*gère un evenement sur notre fenetre*/

SDL_SYSWMEVENT(syswm)            /*gère un evenement sur l'état de la fenetre*/


int SDL_WaitEvent(SDL_Event* event)  /*fonction bloquante ; attend un evenement avant de faire autre chose*/

int SDL_PollEvent(SDL_Event* event) /*pareil mais ne bloque pas*/
