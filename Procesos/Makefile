#Makefile de archivos de procesos
SRCS = fork1 fork2 fork3
OBJS = fork1 fork2 fork3

all: $(SRCS)

fork1: fork1.c
	gcc -o fork1 fork1.c

fork2: fork2.c
	gcc -o fork2 fork2.c

fork3: fork3.c
	gcc -o fork3 fork3.c
	
clean:
	rm -f $(OBJS)