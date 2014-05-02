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
char testCollision(SDL_Rect rectangle1, SDL_Rect rectangle2)
{
	char a=1;
	if((rectangle1.x+rectangle1.w<rectangle2.x)||(rectangle1.x>rectangle2.x+rectangle2.w)||(rectangle1.y>rectangle2.y+rectangle2.h)||(rectangle1.y+rectangle1.h<rectangle2.y))
	{
		a=0;
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
