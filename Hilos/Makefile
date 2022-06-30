#Makefile de archivos de procesos
SRCS = thread1 thread2 thread3
OBJS = thread1 thread2 thread3

all: $(SRCS)

thread1: thread1.c
	gcc -o  thread1 thread1.c -lpthread -lm

thread2: thread2.c
	gcc -o thread2 thread2.c -lpthread -lm

thread3: thread3.c
	gcc -o thread3 thread3.c -lpthread -lm

clean:
	rm -f $(OBJS)