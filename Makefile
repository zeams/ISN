jeu : balle.o balle.h main.o pi.o main.h pi.h affichage.o affichage.h jeu.o jeu.h evenement.o evenement.h
	gcc -g -o3 balle.o balle.h evenement.h evenement.o jeu.o jeu.h constante.h affichage.o affichage.h main.o pi.o pi.h main.h -o jeu `sdl-config --libs --cflags` -Wall -Wextra -Werror 
	rm *.o

balle.o : balle.h
	gcc -g -c balle.c -o balle.o -Wall -Wextra -Werror
evenement.o : evenement.c evenement.h constante.h
	gcc -g -c evenement.c -o evenement.o -Wall -Wextra -Werror

main.o : main.c main.h constante.h
	gcc -g -c main.c -o main.o `sdl-config --libs --cflags` -Wall -Wextra -Werror

pi.o : pi.c pi.h main.h constante.h
	gcc -g -c pi.c -o pi.o `sdl-config --libs --cflags` -Wall -Wextra -Werror

affichage.o : affichage.c main.h affichage.h constante.h
	gcc -g -c affichage.c -o affichage.o `sdl-config --libs --cflags` -Wall -Wextra -Werror

jeu.o : jeu.c jeu.h constante.h
	gcc -g -c jeu.c -o jeu.o `sdl-config --libs --cflags` -Wall -Wextra -Werror

