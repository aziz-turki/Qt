#ifndef bg_H_INCLUDED
#define bg_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


////////// structure de background
typedef struct
{

    SDL_Surface *image;
    SDL_Rect positionbackground;
    SDL_Rect positionback_partage;

    SDL_Rect camera1;
    SDL_Rect camera2;

} background;

///// structure de deplacement
typedef struct
{

    int left, right,d,q;

} mouvement;


void initBack(background *b);
void aficherBack(SDL_Surface *screen, background *b);
void aficherBack_partage(SDL_Surface *screen,background *b);
void scrolling_right(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_right_partage(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_left(background *b, float velocity, SDL_Surface *screen, mouvement M);
void scrolling_left_partage(background *b, float velocity, SDL_Surface *screen, mouvement M);
void init_Mouvement(mouvement *M);

#endif
