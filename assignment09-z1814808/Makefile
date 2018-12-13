.DEFAULT_GOAL := assignment9.exe

assignment9.cc:

assignment9.o: assignment9.cc
	g++ -c assignment9.cc -Wall -std=c++11 -I.

assignment9.exe: assignment9.o
	g++ -o assignment9.exe assignment9.o -Wall -std=c++11 -I.

clean:
	rm *.o assignment9.exe
