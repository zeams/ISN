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
		Balle->position.w=Balle->pointeur->w;
		Balle->position.h=Balle->pointeur->h;
		Balle->deplacement=direction;
		tab[i]=Balle;
	}
}

void deplacementBalle(balle *tab[],player joueur1,player joueur2)
{
	int i,var;
	SDL_Rect murG={0,0,1,HAUTEUR}, murD={0,LARGEUR,1,HAUTEUR};
	for(i=0;i<100;i++)
	{
		if(tab[i]!=NULL)
		{
			if(testCollision(tab[i]->position,murG)||testCollision(tab[i]->position,murD))
			{
				detruireBalle(tab,i);				
			}	
			else if(!collisionBalle(tab,i))
			{
				if(tab[i]->type==CHERCHE)
				{
					var=joueur1.rectangle.y+joueur1.rectangle.h/2;
					if(tab[i]->deplacement==-1)
					{
						var=joueur2.rectangle.y+joueur2.rectangle.h/2;
					}
					else if(tab[i]->deplacement==1)
					{
						var=joueur1.rectangle.y+joueur1.rectangle.h/2;
					}
					if(tab[i]->position.y+tab[i]->pointeur->h/2>var)
					{
						tab[i]->position.y--;
					}
					else 
					{
						tab[i]->position.y++;	
					}
				}
				tab[i]->position.x+=tab[i]->deplacement*D_BALLE;
			}
		}
	}
}
int collision(balle *tab[],player *j1, player *j2)
{
	int i;
	int a=0;
	for(i=0;i<100;i++)
	{
		if(tab[i]!=NULL)
		{
			if(tab[i]->deplacement==-1 && testCollision(tab[i]->position,j2->rectangle))
			{
					SDL_FreeSurface(tab[i]->pointeur);
					tab[i]->pointeur=SDL_LoadBMP("images/explosion.bmp");
					tab[i]->position.x-=j2->rectangle.w/2;
					tab[i]->position.y-=j2->rectangle.h/2;
					SDL_SetColorKey(tab[i]->pointeur, SDL_SRCCOLORKEY, SDL_MapRGB(tab[i]->pointeur->format, 255,255, 255));
					SDL_FreeSurface(j2->surface);
					j2->surface=SDL_LoadBMP("images/tank1br.bmp");
					a=2;
			}
			else if(tab[i]->deplacement==1 && testCollision(tab[i]->position,j1->rectangle))
			{
				SDL_FreeSurface(tab[i]->pointeur);
				tab[i]->pointeur=SDL_LoadBMP("images/explosion.bmp");
				tab[i]->position.x-=j2->rectangle.w/2;
				tab[i]->position.y-=j2->rectangle.h/2;
				SDL_SetColorKey(tab[i]->pointeur, SDL_SRCCOLORKEY, SDL_MapRGB(tab[i]->pointeur->format, 255,255, 255));
				SDL_FreeSurface(j1->surface);
				j1->surface=SDL_LoadBMP("images/tank2br.bmp");
				a=1;
			}
		}
	}
	return a;
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
			surface=SDL_LoadBMP("images/balle.bmp");
			break;
		case CHERCHE:
			if(direction==1)
			{
				surface=SDL_LoadBMP("images/missileR.bmp");
			}
			else if(direction==-1)
			{
				surface=SDL_LoadBMP("images/missileL.bmp");
			}
			break;
	}
	return surface;
}

int collisionBalle(balle *tab[],int i)
{
	int j,a=0;
	SDL_Rect position;
	for(j=0;j<100;j++)
	{
		if(tab[j]!=NULL)
		{
			if((testCollision(tab[j]->position,tab[i]->position))&&i!=j)
			{
				position.x=(tab[i]->position.x+tab[i]->pointeur->w/2+tab[j]->position.x+tab[j]->pointeur->w/2)/2;
				position.y=(tab[i]->position.y+tab[i]->pointeur->h/2+tab[j]->position.y+tab[j]->pointeur->h/2)/2;
				detruireBalle(tab,j);
				detruireBalle(tab,i);
				a=1;
				affichageEx(&position);
				SDL_Delay(10);
				break;
			}
		}
	}
	return a;
}
void freeTab(balle *tab[])
{
	int i;
	for(i=0;i<100;i++)
	{
		if(tab[i]!=NULL)
		{
			SDL_FreeSurface(tab[i]->pointeur);
			free(tab[i]);
			tab[i]=NULL;
		}
	}
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
