#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#include <SDL_ttf.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 650


int generateur_index(int MIN, int MAX)
{
	int index = 0;
	srand(time(NULL));
	index = (rand() % (MAX - MIN + 1)) + MIN;
	return index;
}

char* Choix_mot(int N)
{
	int i;
	int j;
	char** mots;
	mots=(char**)malloc(3400*sizeof(char*));
	for(i=0;i<3400;i++)
	{
		mots[i]=(char*)malloc((N+1)*sizeof(char));
	}
	for(i=0; i<3400; i++)
	{
		for (j=0; j<=N; j++)
		{
			mots[i][j] = '\0';
		}
	}
	FILE *Fread;
	char* file;
	if(N == 6) file = "mot_6p.txt";
	if(N == 7) file = "mot_7p.txt";
	if(N == 8) file = "mot_8p.txt";
	if(N == 9) file = "mot_9p.txt";
	if(N == 10) file = "mot_10p.txt";
	Fread=fopen(file,"r");
	for (i=0; i<3400; i++)
	{
		for (j=0; j<=N; j++)
		{
			fscanf(Fread,"%c",&mots[i][j]);
			if(mots[i][0] == '/') break;
			if(mots[i][j] == '\n') 
			{
				mots[i][j] = '\0';
				break;
			}
		}
		if(mots[i][0] == '/') break;
	}
	fclose(Fread);
	int len = i;
	int index = generateur_index(0, len-1);
	char* c;
	c = (char*)malloc((N+1)*sizeof(char));
	c = mots[index];
	c[N] = '\0';
	free(mots);
	return c;
}

void Ecrire(int m, char* text, char* ttf, int R, int G, int B, int X, int Y, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font, int Taille)
{
	Font = TTF_OpenFont(ttf, Taille);
	SDL_Color textColor = { R, G, B };
	image = TTF_RenderText_Solid( Font, text, textColor );
	//Créer la texture
	texture = SDL_CreateTextureFromSurface(renderer, image);
	//Charger la texture en memoire
	SDL_Rect rectangle;
	SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);
	rectangle.x = X;
	rectangle.y = Y;
	if(m == 1)
	{
		rectangle.x += (47 - rectangle.w) / 2;
		rectangle.y += (47 - rectangle.h) / 2;
	}
	if(m == 2) rectangle.x += (WINDOW_WIDTH - rectangle.w) / 2;
	//Afficher la texture
	SDL_RenderCopy(renderer, texture, NULL, &rectangle);
	//Afficher le rendu
	SDL_RenderPresent(renderer);
}

void Image(char* picture, int X, int Y, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture)
{
	//Charger une image
	image = SDL_LoadBMP(picture);
	//Créer la texture
	texture = SDL_CreateTextureFromSurface(renderer, image);
	//Charger la texture en memoire
	SDL_Rect rectangle;
	rectangle.x = X;
	rectangle.y = Y;
	SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);
	//Afficher la texture
	SDL_RenderCopy(renderer, texture, NULL, &rectangle);
	//Afficher le rendu
	SDL_RenderPresent(renderer);
}

void Grille(int N, char* mot, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font, int** MX, int** MY)
{
    int i;
    int j;
	Image("jeu.bmp", 0, 0, renderer, image, texture);
	//Création de la grille
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			MX[i][j] = (WINDOW_WIDTH - 50*N)/2 + 1 + 50*j;
			MY[i][j] = (WINDOW_HEIGHT - 50*N)/2 + 1 + 50*i;
			Image("bleu.bmp", MX[i][j], MY[i][j], renderer, image, texture);
		}
	}
	//Remplissage avec des '.'
	for (i=0; i<N-1; i++)
	{
		for (j=0; j<N; j++)
		{
			Ecrire(1, ".", "college.ttf", 0, 0, 0, MX[i][j], MY[i][j], renderer, image, texture, Font, 30);
		}
	}
	//Ecriture du premier caratère
	Image("bleu.bmp", MX[0][0], MY[0][0], renderer, image, texture);
	char* init;
	init = (char*) malloc(2*sizeof(char));
	init[0] = mot[0];
	init[1] = '\0';
	Ecrire(1, init, "college.ttf", 0, 0, 0, MX[0][0], MY[0][0], renderer, image, texture, Font, 30);
	//Afficher le rendu
	SDL_RenderPresent(renderer);
}

void Ecrire_temps(char* c, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font)
{
	//Modifier la couleur du dessin en RGB
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//Création de la grille
	SDL_Rect black;
	black.w = 150;
	black.h = 60;
	black.x = 248;
	black.y = 5;
	//Dessiner la grille remplie
	SDL_RenderFillRect(renderer, &black);
	Ecrire(0, c, "alger.ttf", 0, 255, 0, 270, 6, renderer, image, texture, Font, 50);
	//Afficher le rendu
	SDL_RenderPresent(renderer);
}

int Verification(int N, char* mot, char* proposition, char* lettre_trouvees, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font, int** MX, int** MY, int I)
{
	int j;
	char* c;
	c = (char*) malloc(2*sizeof(char));
	c[1] = '\0';
	if (strcmp(proposition, mot) == 0)
	{
		for (j=0; j<N; j++)
		{
			*c = proposition[j];
			Image("rouge.bmp", MX[I][j], MY[I][j], renderer, image, texture);
			Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I][j], MY[I][j], renderer, image, texture, Font, 50);
		}
		return 0;
	}
	if (strlen(proposition) != strlen(mot) || proposition[0] != mot[0])
	{
		for (j=0; j<N; j++)
		{
			*c = lettre_trouvees[j];
			Image("bleu.bmp", MX[I+1][j], MY[I+1][j], renderer, image, texture);
			Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I+1][j], MY[I+1][j], renderer, image, texture, Font, 30);
		}
		return 1;
	}
	for (j=0; j<N; j++)
	{
		*c = proposition[j];
		if (proposition[j] == mot[j])
		{
			lettre_trouvees[j] = mot[j];
			Image("rouge.bmp", MX[I][j], MY[I][j], renderer, image, texture);
			Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I][j], MY[I][j], renderer, image, texture, Font, 50);
		}
		else if (strchr(mot, proposition[j]) != NULL)
		{
			Image("jaune.bmp", MX[I][j], MY[I][j], renderer, image, texture);
			Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I][j], MY[I][j], renderer, image, texture, Font, 50);
		}
		*c = lettre_trouvees[j];
		Image("bleu.bmp", MX[I+1][j], MY[I+1][j], renderer, image, texture);
		Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I+1][j], MY[I+1][j], renderer, image, texture, Font, 30);
	}
	return 1;
}

int Continuer(int Win, char* mot, int* score, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font)
{
	//Charger une image
	if(Win == 2)
	{
		image = SDL_LoadBMP("vrai.bmp");
	}
	if(Win == 3)
	{
		image = SDL_LoadBMP("faux.bmp");
	}
	//Créer la texture
	texture = SDL_CreateTextureFromSurface(renderer, image);
	//Charger la texture en memoire
	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h);
	//Afficher la texture
	SDL_RenderCopy(renderer, texture, NULL, &rectangle);
	//Afficher le rendu
	SDL_RenderPresent(renderer);
	int R, G;
	if(Win == 2)
	{
		R = 0; G = 255;
	}
	if(Win == 3)
	{
		R = 255; G = 0;
	}
	Ecrire(2, mot, "alger.ttf", R, G, 0, 0, 165, renderer, image, texture, Font, 50);
	int i = *score;
  	char str[10];
  	sprintf(str, "%d", i);
  	char* c;
  	c = str;
  	Ecrire(2, c, "alger.ttf", 0, 0, 255, 0, 315, renderer, image, texture, Font, 50);
	int X;
	int Y;
	SDL_bool program_launched = SDL_TRUE;
	while(program_launched)
	{
		//Créer un evenement
		SDL_Event event;
		//Lire tout les evenements
		while(SDL_WaitEvent(&event))
		{
			//Traiter les types d'evenements qui nous interessent
			switch(event.type)
			{
				case SDL_MOUSEBUTTONUP:
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						X = event.button.x;
						Y = event.button.y;
						if(X >= 20 && X <= (20 + 210) && Y >= 455 && Y <= (455 + 60))
						{
							return 3;
						}
						if(X >= 270 && X <= (270 + 210) && Y >= 455 && Y <= (455 + 60))
						{
							return 2;
						}
						continue;
					}
					else continue;
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					return 1;
					break;
				default:
					continue;
			}
		}
	}
}
