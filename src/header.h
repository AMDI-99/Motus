#ifndef HEADER_H
#define HEADER_H

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 650


int generateur_index(int MIN, int MAX);
char* Choix_mot(int N);
void Ecrire(int m, char* text, char* ttf, int R, int G, int B, int X, int Y, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font, int Taille);
void Image(char* picture, int X, int Y, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture);
void Grille(int N, char* mot, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font, int** MX, int** MY);
void Ecrire_temps(char* c, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font);
int Verification(int N, char* mot, char* proposition, char* lettre_trouvees, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font, int** MX, int** MY, int I);
int Continuer(int Win, char* mot, int* score, SDL_Renderer *renderer, SDL_Surface *image, SDL_Texture *texture, TTF_Font *Font);


#endif