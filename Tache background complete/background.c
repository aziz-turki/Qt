#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

void initBack(background *b)
{

    b->image = IMG_Load("stage3.png"); /// chargement de l'image  de background 

//// initialisation position background1
    b->positionbackground.x = 0;
    b->positionbackground.y = -10;
    b->positionbackground.w = 0;
    b->positionbackground.h = 0;


//// initialisation position camera 1
    b->camera1.x = 0;
    b->camera1.y = 0;
    b->camera1.w = 650;
    b->camera1.h = 1000;


//// initialisation position background 2
    b->positionback_partage.x = 650;
    b->positionback_partage.y = -10;
    b->positionback_partage.h = 0;
    b->positionback_partage.w = 0;


//// initialisation position camera 2
    b->camera2.x = 0;
    b->camera2.y = 0;
    b->camera2.w = 650;
    b->camera2.h = 1000;


}



void aficherBack(SDL_Surface *screen,background *b)
{

    SDL_BlitSurface(b->image, &b->camera1, screen, &b->positionbackground); /// blite de 1ere background

}


/*********************************************************************************/


void aficherBack_partage(SDL_Surface *screen,background *b)
{


    SDL_BlitSurface(b->image, &b->camera2, screen, &b->positionback_partage);/// blite de 2eme background avec partage

}


/*********************************************************************************/


void scrolling_right(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.right == 1 )
    {
        if (b->camera1.x < 5280)
        {
            b->camera1.x += velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_right_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.d == 1)
    {
        if (b->camera2.x < 5280)
        {
            b->camera2.x += velocity;
        }
    }
}


/*********************************************************************************/


void scrolling_left(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.left == 1)
    {
        if (b->camera1.x > 0)
        {
            b->camera1.x -= velocity;
        }
    }

}


/*********************************************************************************/


void scrolling_left_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.q == 1)
    {
        if (b->camera2.x > 0)
        {
            b->camera2.x -= velocity;
        }
    }

}



/*********************************************************************************/


///// initialisation des deplacement
void init_Mouvement(mouvement *M)
{
    M->left = 0;
    M->right = 0;

    M->q = 0;
    M->d = 0;

}
