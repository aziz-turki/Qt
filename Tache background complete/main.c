#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"


int main()
{
    SDL_Surface *screen,*image;
    mouvement M;
    background b;
    int continuer = 1;    
    Mix_Music *music;


////////////////////////////////////// musique continue/////////////////////////
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	music = Mix_LoadMUS("music.mp3") ;
	Mix_PlayMusic(music,-1);
//////////////////////////////



    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);//// initialisation de SDL 
    SDL_WM_SetIcon(IMG_Load("icon.png"), NULL);/// image de l'icon
    screen = SDL_SetVideoMode(1300, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//// creation de fenetre 
    SDL_WM_SetCaption("Castle-Break", NULL); /// nom de fenetre 


    init_Mouvement(&M); // appel fonction initialisation des deplacement
    initBack(&b);// appel fonction initialisation de background 1 et 2



///////////////////////////////////////////////// evenement////////////////////////////////////////
    SDL_Event event;
    SDL_EnableKeyRepeat(1, 0);//curseur continue
    while (continuer)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                continuer = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;

                case SDLK_RIGHT:
                    M.right = 1;
                    break;

                case SDLK_LEFT:
                    M.left = 1;
                    break;

                case SDLK_d:
                    M.d = 1;
                    break;

                case SDLK_q:
                    M.q = 1;
                    break;
    }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    M.right = 0;
                    break;

                case SDLK_LEFT:
                    M.left = 0;
                    break;

                case SDLK_d:
                    M.d = 0;
                    break;

                case SDLK_q:
                    M.q = 0;
                    break;

                }
                break;
            }
//////////////////////////////////////////////////////////////////




//////////////////////////// appele fonction scrolling ////////////////////////// 
                scrolling_right(&b, 10, screen, M);
		scrolling_right_partage(&b, 10,screen,M);
                scrolling_left(&b, 10, screen, M);
		scrolling_left_partage(&b, 10,screen,M);
////////////////////


        }

        aficherBack(screen, &b);/// appel fonction affichage back 1
	aficherBack_partage(screen,&b);/// appel fonction affichage back 2 avec partage d'ecran
        SDL_Flip(screen);// mise a jour de l'ecran

    }

    SDL_FreeSurface(screen);
    SDL_FreeSurface(image);
    Mix_FreeMusic(music); 
    SDL_Quit();
    return 0;
}
