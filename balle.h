#ifndef DEF_BALLE
	#define DEF_BALLE
	#include"main.h"
	int rechercheVide(balle *tab[]);
	SDL_Surface* imageBalle(Type type, int direction);
	void creerBalle(player joueur,int direction,Type type, balle* tab[]);
	void detruireBalle(balle *tab[],int rang);
	int collisionBalle(balle *tab[],int i);
	int collision(balle *tab[],player *j1, player *j2);
	void deplacementBalle(balle* tab[],player joueur1, player joueur2);
	void freeTab(balle *tab[]);
#endif
