all : sat-game

sat-game :  lecture.o affichage.o jeu.o main.o
	gcc -o sat-game lecture.o affichage.o jeu.o main.o
    
lecture.o: lecture.c lecture.h 
	gcc -c lecture.c    
    
affichage.o: affichage.c affichage.h lecture.h
	gcc  -c affichage.c
    
jeu.o: jeu.c jeu.h
	gcc  -c jeu.c
main.o: main.c 
	gcc  -c main.c
    

    

