#ifndef DEF_BALLE
	#define DEF_BALLE
	#include"main.h"
	void creerBalle(player joueur,int direction,Type type, balle* tab[]);
	SDL_Surface* imageBalle(Type type, int direction);
	int rechercheVide(balle *tab[]);
	void detruireBalle(balle *tab[],int rang);
	char testCollision(SDL_Rect rectangle1, SDL_Rect rectangle2);
#endif
