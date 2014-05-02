#ifndef DEF_MAIN
	#define DEF_MAIN
	#include<SDL/SDL.h>
	typedef enum Type Type;
	enum Type{
		NORMAL,CHERCHE
	};
	typedef struct player player;//definit une structure 
	struct player{
		SDL_Rect rectangle;  	//structure qui contient des coordonnées du sommet d'un cube x et y, et la largeur et hauteur : w et h
		SDL_Surface *surface;	//pointeur vers SDL_Surface qui pointera vers la surface representant chaque joueur
		int cooldown;
		Type type;
	 };	
	/*
	 *		player : | - rectangle :      | - x
	 *                                            | - y
	 *                                            | - w
	 *                                            | - h
	 *                       | - *surface ------> | - format (format de couleur de la surface)
	 *                                            | - w (largeur de la surface)
	 *                                            | - h (hauteur de la surface)
	 *                                            | - ...
	 *                       | -nb
	 *
	 *
	 * La structure player contient une structure rectangle qui contient une variable x qui est la coordonnée x du sommet haut gauche d'un rectangle
	 *								     une variable y qui est la coordonnée y du sommet haut gauche d'un rectangle
	 *								     une variable w qui est la largeur d'un rectangle
	 *								     une variable h qui est la hauteur d'un rectangle
	 *				un pointeur vers une structure de type SDL_Surface qui contient une variable format qui est le codage des couleurs
	 *												une varible w qui est la largeur de la surface
	 *												une varible h qui est la hauteur de la surface
	 *												d'autres variables dont les pixels de la surface
	 *				une varible nb qui est un nombre (qui sert à rien)
	 *
	 */
	
	typedef struct balle balle;
	struct balle{
		SDL_Rect position;
		int deplacement;
		SDL_Surface *pointeur;
		Type type;
	};
	
	#include"constante.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<time.h>
	#include"affichage.h"
	#include"balle.h"
	#include"evenement.h"
	#include"pi.h"
	#include"jeu.h"
	#include<stdbool.h>
#endif

