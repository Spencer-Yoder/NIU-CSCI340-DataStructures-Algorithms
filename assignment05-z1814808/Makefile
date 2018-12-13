.DEFAULT_GOAL := assignment05.exe

assignment05.cc:

assignment05.o: assignment05.cc
	g++ -c assignment05.cc -Wall -std=c++11 -I.

assignment05.exe: assignment05.o
	g++ -o assignment05.exe assignment05.o -Wall -std=c++11

clean:
	rm *.o assignment05.exe