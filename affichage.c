#include"affichage.h"

static SDL_Surface *ecran=NULL;
int initAffichage(void)
{	
	SDL_Init(SDL_INIT_VIDEO);
	ecran=SDL_SetVideoMode(LARGEUR,HAUTEUR,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
	SDL_WM_SetCaption("ISN",NULL);
	SDL_Flip(ecran);
	return 1;
}

void displayPlayer(player J1,player J2)
{
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
	SDL_BlitSurface(J1.surface,NULL,ecran,&J1.rectangle);
	SDL_BlitSurface(J2.surface,NULL,ecran,&J2.rectangle);
}
void afficherBalle(balle * tab[])
{
	int i;
	for(i=0;i<100;i++)
	{
		if(tab[i]!=NULL)
		{
			SDL_BlitSurface(tab[i]->pointeur,NULL,ecran,&tab[i]->position);
		}
	}
	SDL_Flip(ecran);
}
void affichageEx(SDL_Rect *position)
{
	SDL_Rect pR=*position;
	SDL_Surface *surface=SDL_LoadBMP("exp.bmp");
	pR.x-=surface->w/2;
	pR.y-=surface->h/2;
	SDL_SetColorKey(surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 255,255, 255));
	SDL_BlitSurface(surface,NULL,ecran,&pR);
	SDL_FreeSurface(surface);
	SDL_Flip(ecran);
}
