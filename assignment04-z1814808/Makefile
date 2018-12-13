.DEFAULT_GOAL := assignment04.exe

assignment04.o: assignment04.cc
	g++ -c assignment04.cc -Wall -std=c++11

assignment04.exe: assignment04.o
	g++ -o assignment04.exe assignment04.o -Wall -std=c++11

clean:
	rm *.o assignment04.exe