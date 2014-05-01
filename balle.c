#include"balle.h"
void creerBalle(player joueur,int direction,Type type, balle* tab[])
{
	int i=rechercheVide(tab);
	if(i>=0)
	{
		balle *Balle=malloc(sizeof(balle));
		Balle->type=type;
		Balle->pointeur=imageBalle(Balle->type,direction);
		if(direction==1)
		{
			Balle->position.x=joueur.rectangle.x+joueur.rectangle.w;
		}
		else if(direction==-1)
		{
			Balle->position.x=joueur.rectangle.x-Balle->pointeur->w;	
		}
		Balle->position.y=joueur.rectangle.y+joueur.rectangle.h/2-Balle->pointeur->h/2;
		Balle->deplacement=direction;
		tab[i]=Balle;
	}
}

void detruireBalle(balle *tab[],int rang)
{
	if(tab[rang]!=NULL)
	{
		SDL_FreeSurface(tab[rang]->pointeur);
		free(tab[rang]);
		tab[rang]=NULL;
	}
}

SDL_Surface* imageBalle(Type type, int direction)
{
	SDL_Surface *surface=NULL;
	switch(type)
	{
		case NORMAL:
			surface=SDL_LoadBMP("balle.bmp");
			break;
		case CHERCHE:
			if(direction==1)
			{
				surface=SDL_LoadBMP("missileR.bmp");
			}
			else if(direction==-1)
			{
				surface=SDL_LoadBMP("missileL.bmp");
			}
			break;
	}
	return surface;
}

int rechercheVide(balle *tab[])
{
	int i;
	for(i=0;i<100;i++)
	{
		if(tab[i]==NULL)
			break;
	}
	if(tab[i]!=NULL)
	{
		i=-1;
	}
	return i;
}
