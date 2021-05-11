#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "header.h"


int Menu(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font)
{
	Image("MENU.bmp", 0, 0, renderer, image, texture);
	FILE *Fread;
	Fread=fopen("score.txt","r");
	int t;
	fscanf(Fread,"%d", &t);
	fclose(Fread);
  	char str[10];
  	sprintf(str, "%d", t);
  	char* c;
  	c = str;
  	Ecrire(2, c, "alger.ttf", 255, 242, 0, 0, 110, renderer, image, texture, Font, 50);
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
						if(X >= 90 && X <= (90 + 320) && Y >= 480 && Y <= (480 + 80))
						{
							return 0;
						}
						if(X >= 430 && X <= (430 + 50) && Y >= 20 && Y <= (20 + 50))
						{
							return 2;
						}
						break;
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

int fct_regle(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture)
{
	Image("regle.bmp", 0, 0, renderer, image, texture);
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
						if(X >= 10 && X <= (10 + 200) && Y >= 590 && Y <= (590 + 50))
						{
							return 0;
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

int fct_N(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture)
{
	Image("N.bmp", 0, 0, renderer, image, texture);
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
						if(X >= 70 && X <= (70 + 120) && Y >= 200 && Y <= (200 + 60))
						{
							return 6;
						}
						if(X >= 310 && X <= (310 + 120) && Y >= 200 && Y <= (200 + 60))
						{
							return 7;
						}
						if(X >= 70 && X <= (70 + 120) && Y >= 300 && Y <= (300 + 60))
						{
							return 8;
						}
						if(X >= 310 && X <= (310 + 120) && Y >= 300 && Y <= (300 + 60))
						{
							return 9;
						}
						if(X >= 190 && X <= (190 + 120) && Y >= 400 && Y <= (400 + 60))
						{
							return 10;
						}
						if(X >= 20 && X <= (20 + 210) && Y >= 582 && Y <= (582 + 60))
						{
							return -1;
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

int fct_Time(SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture)
{
	Image("Time.bmp", 0, 0, renderer, image, texture);
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
						if(X >= 190 && X <= (190 + 120) && Y >= 175 && Y <= (175 + 60))
						{
							return 10;
						}
						if(X >= 190 && X <= (190 + 120) && Y >= 275 && Y <= (275 + 60))
						{
							return 15;
						}
						if(X >= 190 && X <= (190 + 120) && Y >= 375 && Y <= (375 + 60))
						{
							return 20;
						}
						if(X >= 20 && X <= (20 + 210) && Y >= 507 && Y <= (507 + 60))
						{
							return 0;
						}
						if(X >= 20 && X <= (20 + 210) && Y >= 582 && Y <= (582 + 60))
						{
							return -1;
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

int Init_Jeu(int N, int Time, char* mot, int* score, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font)
{
	int i;
	int j;
	mot = Choix_mot(N);
    mot[N] = '\0';
	printf("%s\n", mot);
	int AddScore = 10 * N;
	switch(Time)
	{
		case 10:
			AddScore += (AddScore*25)/100;
			break;
		case 20:
			AddScore -= (AddScore*25)/100;
			break;
		default: break;
	}
	char* proposition;
	proposition = (char*) malloc((N+1)*sizeof(char));
	for (i=0; i<=N; i++)
		proposition[i] = '\0';
	char* lettre_trouvees;
	lettre_trouvees = (char*) malloc((N+1)*sizeof(char));
	for (i=0; i<N; i++)
		lettre_trouvees[i] = '.';
	lettre_trouvees[N] = '\0';
	lettre_trouvees[0] = mot[0];
	int** MX;
	int** MY;
	MX=(int**)malloc(N*sizeof(int*));
	MY=(int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++)
	{
		MX[i]=(int*)malloc(N*sizeof(int));
		MY[i]=(int*)malloc(N*sizeof(int));
	}
	//Création de la grille
	Grille(N, mot, renderer, image, texture, Font, MX, MY);
	int I = 0;
	int J = 0;
	int Congrats;
	int startTime = 0;
	startTime = SDL_GetTicks();
	int compt = 1;
	int currentTime = 0;
	int start;
	char str[10];
  	sprintf(str, "%d", Time);
  	char* t;
  	t = str;
  	Ecrire_temps(t, renderer, image, texture, Font);
	SDL_bool program_launched = SDL_TRUE;
	while(program_launched)
	{
		//Créer un evenement
		SDL_Event event;
		currentTime = SDL_GetTicks();
		if (currentTime - startTime >= compt*1000)
		{
			char str[10];
  			sprintf(str, "%d", Time - compt);
  			char* t;
  			t = str;
  			Ecrire_temps(t, renderer, image, texture, Font);
			compt += 1;
		}
		if (Time - compt + 1 == 0)
		{
			I += 1;	J = 0;
			char* c;
			c = (char*) malloc(2*sizeof(char));
			c[1] = '\0';
			if (I == N-1)
			{
				for (j=0; j<N; j++)
				{
					*c = mot[j];
					Image("rouge.bmp", MX[I][j], MY[I][j], renderer, image, texture);
					Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I][j], MY[I][j], renderer, image, texture, Font, 50);
				}
				//Temps Visualisation
				SDL_Delay(2000);
				free(proposition); free(lettre_trouvees); free(MX); free(MY);
    			return Continuer(3, mot, score, renderer, image, texture, Font);
				break;
			}
			for (j=0; j<N; j++)
			{
				*c = lettre_trouvees[j];
				Image("bleu.bmp", MX[I][j], MY[I][j], renderer, image, texture);
				Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I][j], MY[I][j], renderer, image, texture, Font, 30);
				proposition[j] = '\0';
			}
			proposition[N] = '\0';
			startTime = SDL_GetTicks();
			compt = 1;
			char str[10];
  			sprintf(str, "%d", Time);
  			char* t;
  			t = str;
		  	Ecrire_temps(t, renderer, image, texture, Font);
		}
        int X;
        int Y;
		//Lire tout les evenements
		while(SDL_PollEvent(&event))
		{
			//Traiter les types d'evenements qui nous interessent
			switch(event.type)
			{
				case SDL_MOUSEBUTTONUP:
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						X = event.button.x;
						Y = event.button.y;
						if(X >= 20 && X <= (20 + 210) && Y >= 582 && Y <= (582 + 60))
						{
							return -1;
						}
						continue;
					}
					else continue;
				case SDL_KEYUP:
					switch(event.key.keysym.sym)
					{
						case SDLK_a:
							if (J < N && I < N)
							{
								proposition[J] = 'a';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "A", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_b:
							if (J < N && I < N)
							{
								proposition[J] = 'b';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "B", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_c:
							if (J < N && I < N)
							{
								proposition[J] = 'c';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "C", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_d:
							if (J < N && I < N)
							{
								proposition[J] = 'd';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "D", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_e:
							if (J < N && I < N)
							{
								proposition[J] = 'e';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "E", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_f:
							if (J < N && I < N)
							{
								proposition[J] = 'f';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "F", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_g:
							if (J < N && I < N)
							{
								proposition[J] = 'g';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "G", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_h:
							if (J < N && I < N)
							{
								proposition[J] = 'h';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "H", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_i:
							if (J < N && I < N)
							{
								proposition[J] = 'i';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "I", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_j:
							if (J < N && I < N)
							{
								proposition[J] = 'j';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "J", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_k:
							if (J < N && I < N)
							{
								proposition[J] = 'k';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "K", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_l:
							if (J < N && I < N)
							{
								proposition[J] = 'l';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "L", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_m:
							if (J < N && I < N)
							{
								proposition[J] = 'm';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "M", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_n:
							if (J < N && I < N)
							{
								proposition[J] = 'n';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "N", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_o:
							if (J < N && I < N)
							{
								proposition[J] = 'o';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "O", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_p:
							if (J < N && I < N)
							{
								proposition[J] = 'p';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "P", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_q:
							if (J < N && I < N)
							{
								proposition[J] = 'q';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "Q", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_r:
							if (J < N && I < N)
							{
								proposition[J] = 'r';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "R", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_s:
							if (J < N && I < N)
							{
								proposition[J] = 's';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "S", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_t:
							if (J < N && I < N)
							{
								proposition[J] = 't';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "T", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_u:
							if (J < N && I < N)
							{
								proposition[J] = 'u';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "U", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_v:
							if (J < N && I < N)
							{
								proposition[J] = 'v';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "V", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_w:
							if (J < N && I < N)
							{
								proposition[J] = 'w';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "W", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_x:
							if (J < N && I < N)
							{
								proposition[J] = 'x';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "X", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_y:
							if (J < N && I < N)
							{
								proposition[J] = 'y';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "Y", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_z:
							if (J < N && I < N)
							{
								proposition[J] = 'z';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, "Z", "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 50);	J += 1;
							}
							continue;
						case SDLK_BACKSPACE:
							if(J > 0)
							{
								J -= 1;
								char* c;
								c = (char*) malloc(2*sizeof(char));
								c[0] = lettre_trouvees[J];
								c[1] = '\0';
								proposition[J] = '\0';	Image("bleu.bmp", MX[I][J], MY[I][J], renderer, image, texture);	Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I][J], MY[I][J], renderer, image, texture, Font, 30);
							}
							continue;
						case SDLK_RETURN:
							Congrats = Verification(N, mot, proposition, lettre_trouvees, renderer, image, texture, Font, MX, MY, I);
							if (Congrats == 0)
							{
								*score += AddScore;
								//Temps Visualisation
								SDL_Delay(2000);
								free(proposition); free(lettre_trouvees); free(MX); free(MY);
    							return Continuer(2, mot, score, renderer, image, texture, Font);
								break;
							}
							I += 1;	J = 0;
							if (I == N-1)
							{
								char* c;
								c = (char*) malloc(2*sizeof(char));
								c[1] = '\0';
								for (j=0; j<N; j++)
								{
									*c = mot[j];
									Image("rouge.bmp", MX[I][j], MY[I][j], renderer, image, texture);
									Ecrire(1, c, "college.ttf", 0, 0, 0, MX[I][j], MY[I][j], renderer, image, texture, Font, 50);
								}
								//Temps Visualisation
								SDL_Delay(2000);							
								free(proposition); free(lettre_trouvees); free(MX); free(MY);
    							return Continuer(3, mot, score, renderer, image, texture, Font);
								break;
							}
							char str[10];
  							sprintf(str, "%d", Time);
  							char* t;
  							t = str;
  							Ecrire_temps(t, renderer, image, texture, Font);
							startTime = SDL_GetTicks();
							compt = 1;
							for (i=0; i<=N; i++)
								proposition[i] = '\0';
							continue;
						default:
							continue;
					}
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				default:
					break;
			}
		}
	}
	return 1;
}
