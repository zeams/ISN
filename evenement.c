#include"evenement.h"
void evenement(player *joueur1, player *joueur2, SDL_Event event, balle *tab[])
{
	#if JOYSTICK
		if(digitalRead(PIN_H1))
		{
			deplacement(joueur1,-1);
		}
		if(digitalRead(PIN_B1))
		{
			deplacement(joueur1,1);
		}
		if(digitalRead(PIN_H2))
		{
			deplacement(joueur2,-1);
		}
		if(digitalRead(PIN_B2))
		{
			deplacement(joueur2,1);
		}
		if(digitalRead(PIN_S1))
		{
			if(joueur1->cooldown<0)
			{
				creerBalle(*joueur1,1,joueur1->type,tab);
				joueur1->cooldown=COOLDOWN;
			}
		}
		if(digitalRead(PIN_S2))
		{
			if(joueur2->cooldown<0)
			{
				creerBalle(*joueur2,-1,joueur2->type,tab);
				joueur2->cooldown=COOLDOWN;
			}
		}
	#else 
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:
				deplacement(joueur1,-1);
				break;
			case SDLK_DOWN:
				deplacement(joueur1,1);
				break;
			case SDLK_z:
				deplacement(joueur2,-1);
				break;
			case SDLK_s:
				deplacement(joueur2,1);
				break;
			case SDLK_n:
				if(joueur1->cooldown<0)
				{
					creerBalle(*joueur1,-1,joueur1->type,tab);
					joueur1->cooldown=COOLDOWN;
				}
				break;
			case SDLK_d:
				if(joueur2->cooldown<0)
				{
					creerBalle(*joueur2,1,joueur2->type,tab);
					joueur2->cooldown=COOLDOWN;
				}
				break;
			default:
				break;
		}	
	#endif
}
