#include"main.h"
int main()
{
	srand(time(NULL));
	initAffichage();//initialise SDL
	#if JOYSTICK	//si JOYSTICK !=0, alors on initialise les broches
		initPin();
	#endif
	pause();	
	SDL_Quit();
	return EXIT_SUCCESS;
}
