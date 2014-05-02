#ifndef DEF_JEU
	#define DEF_JEU
	#include"main.h"
	void pause(void);
	void deplacement(player *joueur, int direction);
	char testCollision(SDL_Rect rectangle0, SDL_Rect rectangle2);
#endif
