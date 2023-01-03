CC=gcc
flag= -Wall
SDL_CFLAGS=`sdl2-config --cflags --libs`

all:main


main:main.o fonctionsPotager.o fonctionsPucerons.o fonctionsCoccinelles.o interfaceGraphique.o
	$(CC) $(flag) main.o fonctionsPotager.o fonctionsPucerons.o fonctionsCoccinelles.o interfaceGraphique.o $(SDL_CFLAGS) -o main

main.o: main.c 
	$(CC) $(flag) -c main.c $(SDL_CFLAGS)

interfaceGraphique.o: interfaceGraphique.c fonctionsCoccinelles.o fonctionsPucerons.o fonctionsPotager.o 
	$(CC) $(flag) -c interfaceGraphique.c $(SDL_CFLAGS)

fonctionsCoccinelles.o: fonctionsCoccinelles.c fonctionsPucerons.o fonctionsPotager.o 
	$(CC) $(flag) -c fonctionsCoccinelles.c
	
fonctionsPucerons.o: fonctionsPucerons.c fonctionsPotager.o 
	$(CC) $(flag) -c fonctionsPucerons.c

fonctionsPotager.o: fonctionsPotager.c 
	$(CC) $(flag) -c fonctionsPotager.c

clean:
	rm -f *.o
	
mrpropr: clean
	rm -f main
	
