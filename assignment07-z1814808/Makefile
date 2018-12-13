.DEFAULT_GOAL := assignment07.exe

assignment07.cc:

assignment07.o: assignment07.cc
	g++ -c assignment07.cc -Wall -std=c++11 -I.

assignment07.exe: assignment07.o
	g++ -o assignment07.exe assignment07.o -Wall -std=c++11 -I.

clean:
	rm *.o assignment07.exe