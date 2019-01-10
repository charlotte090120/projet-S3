all: test

test :
	gcc -g -Wall element_liste.c liste.c squelette.c utils_sd.c mainfile.c -o casino

