#include"jeu.h"
void pause(void)
{
	balle *tab[100]={NULL};
	bool continuer=1;
	SDL_Event event;
	//on crée deux structures joueurs qui contiennent les données associées aux joueurs à savoir la structure {x,y,largeur,hauteur} qu'on ne peut pas encore remplir, puis la sous-variable *surface qui vaut l'adresse de la surface qu'on charge avec SDL_LoadBMP
	player joueur2={{MARGE,0,0,0},SDL_LoadBMP("tank1.bmp"),0,NORMAL};
	player joueur1={{0,0,0,0},SDL_LoadBMP("tank2.bmp"),0,NORMAL};	  
	//on remplie la sous structure rectangle de chaque joueur avec les bonnes valeurs
	joueur2.rectangle.w=joueur2.surface->w;		
	joueur2.rectangle.h=joueur2.surface->h;
	joueur1.rectangle.w=joueur1.surface->w;
	joueur1.rectangle.h=joueur1.surface->h;
	joueur1.rectangle.x=LARGEUR-MARGE-joueur1.surface->w;
	joueur1.rectangle.y=rand()%(HAUTEUR-joueur1.surface->h);
	joueur2.rectangle.y=rand()%(HAUTEUR-joueur2.surface->h);
	SDL_EnableKeyRepeat(10,10);
	while(continuer)
	{
		//on enregistre l'évenement qui a lieu à ce moment dans la structure event.
		SDL_PollEvent(&event);		
		//si event.type vaut quitter, on met continuer à 0, donc la boucle s'arrètera
		if(event.type==SDL_QUIT)	
		{
			continuer=0;
		}
		else
		{
			evenement(&joueur1,&joueur2,event,tab);
		}
		joueur1.cooldown--;
		joueur2.cooldown--;
		//on appelle la fonction qui remplit l'ecran de blanc et qui colle les images des joueurs aux bonnes positions
		if(collision(tab,&joueur1,&joueur2))
		{
			continuer=0;
			displayPlayer(joueur1,joueur2);
			afficherBalle(tab);
			SDL_Delay(2000);
		}
		deplacementBalle(tab, joueur1,joueur2);
		displayPlayer(joueur1,joueur2);
		afficherBalle(tab);
		event.key.keysym.sym=SDLK_q;
	}
	SDL_FreeSurface(joueur1.surface);	//on libère les surfaces des joueurs qui sont des places mémoires qui ont été demandées à l'ordi lors de SDL_LoadBMP
	SDL_FreeSurface(joueur2.surface);

}

void deplacement(player *joueur, int direction)
{
	if(direction==1)
	{
		if(joueur->rectangle.y+joueur->rectangle.w<HAUTEUR)
		{
			joueur->rectangle.y+=DEPLACEMENT;
		}
	}
	else if(direction==-1)
	{
		if(joueur->rectangle.y>0)
		{
			joueur->rectangle.y-=DEPLACEMENT;
		}
	}
}

void deplacementBalle(balle *tab[],player joueur1,player joueur2)
{
	int i,var;
	for(i=0;i<100;i++)
	{
		if(tab[i]!=NULL)
		{
			if(tab[i]->position.x+tab[i]->deplacement*D_BALLE<=0||tab[i]->position.x+tab[i]->deplacement*D_BALLE>=LARGEUR)
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
int collisionBalle(balle *tab[],int i)
{
	int j,a=0;
	SDL_Rect position;
	for(j=0;j<100;j++)
	{
		if(tab[j]!=NULL)
		{
			if((tab[j]->position.x+tab[j]->pointeur->w<tab[i]->position.x)||(tab[j]->position.x>tab[i]->position.x+tab[i]->pointeur->w)||(tab[j]->position.y>tab[i]->position.y+tab[i]->pointeur->h)||(tab[j]->position.y+tab[j]->pointeur->h<tab[i]->position.y))
			{

			}
			else if(i!=j)
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
int collision(balle *tab[],player *j1, player *j2)
{
	int i;
	int a=0;
	for(i=0;i<100;i++)
	{
		if(tab[i]!=NULL)
		{
			if(tab[i]->deplacement==-1)
			{
				if(tab[i]->position.x<2*(MARGE+j2->rectangle.w)/3)
				{
					if(tab[i]->position.y>j2->rectangle.y&&tab[i]->position.y<j2->rectangle.y+j2->rectangle.h)
					{
						SDL_FreeSurface(tab[i]->pointeur);
						tab[i]->pointeur=SDL_LoadBMP("explosion.bmp");
						tab[i]->position.x-=j2->rectangle.w/2;
						tab[i]->position.y-=j2->rectangle.h/2;
						SDL_SetColorKey(tab[i]->pointeur, SDL_SRCCOLORKEY, SDL_MapRGB(tab[i]->pointeur->format, 255,255, 255));
						SDL_FreeSurface(j2->surface);
						j2->surface=SDL_LoadBMP("tank1br.bmp");
						a=2;

					}
				}
			}
			else if(tab[i]->deplacement==1)
			{
				if(tab[i]->position.x>LARGEUR-MARGE-j1->rectangle.w+j1->rectangle.w/3)
				{
					if(tab[i]->position.y>j1->rectangle.y&&tab[i]->position.y<j1->rectangle.y+j1->rectangle.h)
					{
						SDL_FreeSurface(tab[i]->pointeur);
						tab[i]->pointeur=SDL_LoadBMP("explosion.bmp");
						tab[i]->position.x-=j2->rectangle.w/2;
						tab[i]->position.y-=j2->rectangle.h/2;
						SDL_SetColorKey(tab[i]->pointeur, SDL_SRCCOLORKEY, SDL_MapRGB(tab[i]->pointeur->format, 255,255, 255));

						SDL_FreeSurface(j1->surface);
						j1->surface=SDL_LoadBMP("tank2br.bmp");
						a=1;
					}
				}
			}
		}
	}
	return a;
}

