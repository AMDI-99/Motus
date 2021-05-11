#ifndef MAIN_H
#define MAIN_H

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 650


int Menu(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font);
int fct_regle(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture);
int fct_N(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture);
int fct_Time(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture);
int Init_Jeu(int N, int Time, char* mot, int* score, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font);


#endif