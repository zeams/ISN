#include"jeu.h"
void pause(void)
{
	balle *tab[100]={NULL};
	bool continuer=1;
	SDL_Event event;
	//on crée deux structures joueurs qui contiennent les données associées aux joueurs à savoir la structure {x,y,largeur,hauteur} qu'on ne peut pas encore remplir, puis la sous-variable *surface qui vaut l'adresse de la surface qu'on charge avec SDL_LoadBMP
	player joueur2={{MARGE,0,0,0},SDL_LoadBMP("images/tank1.bmp"),0,NORMAL};
	player joueur1={{0,0,0,0},SDL_LoadBMP("images/tank2.bmp"),0,NORMAL};	  
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
	SDL_FreeSurface(joueur1.surface);	//on libère les surfaces des joueurs et le tableau de balle 
	SDL_FreeSurface(joueur2.surface);
	freeTab(tab);
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

char testCollision(SDL_Rect rectangle1, SDL_Rect rectangle2)
{
	char a=1;
	if(	(rectangle1.x+rectangle1.w<rectangle2.x)||
		(rectangle1.x>rectangle2.x+rectangle2.w)||
		(rectangle1.y>rectangle2.y+rectangle2.h)||
		(rectangle1.y+rectangle1.h<rectangle2.y))
	{
		a=0;
	}
	return a;
}
