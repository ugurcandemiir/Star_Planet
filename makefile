# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -Wall -Wextra -DDEBUG -g -std=c++14

all: run

lab2: star.o lab2.o
	$(CC) $(CFLAGS) star.o lab2.o -o lab2

star.o: Star.cpp Star.h
	$(CC) $(CFLAGS) -c Star.cpp -o star.o

lab2.o: lab2.cpp Star.cpp Star.h
	$(CC) $(CFLAGS) -c lab2.cpp -o lab2.o

clean:
	rm *.o lab2
run: 
	valgrind ./lab2
