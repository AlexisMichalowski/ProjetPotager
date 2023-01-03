CC=gcc
flag= -Wall
SDL_CFLAGS=$(sdl2-config --cflags --libs)

all:main


main:main.o fonctionsPotager.o fonctionsPucerons.o fonctionsCoccinelles.o interfaceGraphique.o
	$(CC) $(flag) main.o fonctionsPotager.o fonctionsPucerons.o fonctionsCoccinelles.o interfaceGraphique.o $(SDL_CFLAGS) -o main

main.o: main.c 
	$(CC) $(flag) -c main.c $(SDL_CFLAGS)

fonctionsPotager.o: fonctionsPotager.c 
	$(CC) $(flag) -c fonctionsPotager.c

fonctionsPucerons.o: fonctionsPucerons.c fonctionsPotager.o 
	$(CC) $(flag) -c fonctionsPucerons.c

fonctionsCoccinelles.o: fonctionsCoccinelles.c fonctionsPucerons.o fonctionsPotager.o 
	$(CC) $(flag) -c fonctionsCoccinelles.c

interfaceGraphique.o: interfaceGraphique.c fonctionsCoccinelles.o fonctionsPucerons.o fonctionsPotager.o 
	$(CC) $(flag) -c interfaceGraphique.c $(SDL_CFLAGS)

clean:
	rm -f *.o
	
mrpropr: clean
	rm -f main
	