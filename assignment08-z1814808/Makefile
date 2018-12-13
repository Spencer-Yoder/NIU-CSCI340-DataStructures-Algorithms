.DEFAULT_GOAL := assignment08.exe

assignment08.cc:

assignment08.o: assignment08.cc
	g++ -c assignment08.cc -Wall -std=c++11 -I.

assignment08.exe: assignment08.o
	g++ -o assignment08.exe assignment08.o -Wall -std=c++11 -I.

clean:
	rm *.o assignment08.exe