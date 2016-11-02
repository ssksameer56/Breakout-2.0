project : Initialization.o Main.o Misc.o MoveandInput.o Physics2.o Quit.o RenderAndGameUpdate.o Text.o
	gcc -g Initialization.o Main.o Misc.o MoveandInput.o Physics2.o Quit.o RenderAndGameUpdate.o Text.o -lSDL2 -lSDL2_image -lSDL2_ttf -lm -o project
Initialization.o: Initialization.c define.h
	gcc -c Initialization.c -lSDL2 -lSDL2_image -lSDL2_ttf 
Main.o: Main.c define.h
	gcc -c Main.c -lSDl2 -lSDL2_image -lSDL2_ttf
Misc.o: Misc.c define.h
	gcc -c Misc.c -lSDL2 -lSDL2_image -lSDL2_ttf
MoveandInput.o: MoveandInput.c define.h
	gcc -c MoveandInput.c -lSDL2 -lSDL2_image -lSDL2_ttf
Physics2.o: Physics2.c define.h
	gcc -c Physics2.c -lSDL2 -lSDL2_image -lSDL2_ttf -lm
Quit.o: Quit.c define.h
	gcc -c Quit.c -lSDL2 -lSDL2_image -lSDL2_ttf
RenderAndGameUpdate.o: RenderAndGameUpdate.c define.h
	gcc -c RenderAndGameUpdate.c -lSDL2 -lSDL2_image -lSDL2_ttf
Text.o: Text.c define.h
	gcc -c Text.c -lSDL2 -lSDL2_image -lSDL2_ttf

