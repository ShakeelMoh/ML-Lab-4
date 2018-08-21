#My own makefile for ML lab 4

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called finds
percep: perceptron.o
	$(CC) perceptron.o -o percep $(LIBS)

#Need to make Audio.o file though
perceptron.o: perceptron.cpp
	$(CC) -c perceptron.cpp


#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f percep

#To run program
run:
	./percep
