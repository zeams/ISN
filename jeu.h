#ifndef DEF_JEU
	#define DEF_JEU
	#include"main.h"
	void pause(void);
	void deplacement(player *joueur, int direction);
	void deplacementBalle(balle* tab[],player joueur1, player joueur2);
	int collision(balle *tab[],player *j1, player *j2);
	int collisionBalle(balle *tab[],int i);
#endif
