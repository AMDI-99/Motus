#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "main.h"


int main(int argc, char *argv[])
{
	int i;
	int j;
	//Lancement de la SDL et TTF
	SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
	//Declaration des pointeurs qu'on va utiliser dans la SDL et TTF
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;
	TTF_Font *Font = NULL;
	//Création fenêtre
	window = SDL_CreateWindow("MOTUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	//Création rendu
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	//LET BEGIN
	char* mot;
	int* score;
	score = (int*)malloc(sizeof(int));
	mot = (char*)malloc(sizeof(char));
	int Jouer = 0;
	int Regle;
	int N;
	int Time;
	int Not_Yet;
	int Go1 = 0;
	do
	{
		Jouer = Menu(renderer, image, texture, Font);
		if(Jouer == 1) break;
		if(Jouer == 2)
		{	
			Regle = fct_regle(renderer, image, texture);
			if(Regle == 1) break;
			if(Regle == 0) 
			{
				Jouer = 0;
				continue;
			}
		}
		if(Jouer == 0)
		{
			do
			{
				Go1 = 0;
				N = fct_N(renderer, image, texture);
				if(N==1) break;
				if(N==-1) break;
				Time = fct_Time(renderer, image, texture);
				if(Time == 1) break;
				if(Time == -1) break;
				if(Time == 0)
				{
					Go1 = 1;
				}
			}while (Go1 != 0);
			if(N == 1 || Time == 1) break;
			if(N == -1 || Time == -1) continue;
        	*score = 0;
        	FILE *Fread;
			Fread=fopen("score.txt","r");
			int ss;
			fscanf(Fread,"%d", &ss);
			fclose(Fread);
    		do
    		{
    			mot = (char*)realloc(mot, (N+1)*sizeof(char));
    			Not_Yet = Init_Jeu(N, Time, mot, score, renderer, image, texture, Font);
    			if(Not_Yet == 1) break;
    		}while (Not_Yet == 2);
    		FILE *Fwrite;
			Fwrite=fopen("score.txt","w");
			int sc;
			if(ss >= *score)
				sc = ss;
			else
				sc = *score;
			fprintf(Fwrite, "%d", sc);
			fclose(Fwrite);
    		if(Not_Yet == 1) break;
		}
	} while (Jouer == 0);
	free(mot); free(score);
	//Libérer la surface
	SDL_FreeSurface(image);
	//Destruction
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//Quitter SDL et TTF
	TTF_Quit();
	SDL_Quit();
	//Fin
	return 0;
}
//gcc src/*.c -o bin/MOTUS -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
