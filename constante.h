#define LARGEUR 1300
#define HAUTEUR 700
#define DELAI 10
#define MARGE 10
#define TAILLE 150
#define DEPLACEMENT 4
#define D_BALLE 4
#define COOLDOWN 50
#define JOYSTICK 0
#if JOYSTICK //Si JOYSTICK, alors on définit les nuléros des broches
	#define PIN_H1 7
	#define PIN_B1 2
	#define PIN_S1 3
	#define PIN_H2 4
	#define PIN_B2 5
	#define PIN_S2 6
#endif
