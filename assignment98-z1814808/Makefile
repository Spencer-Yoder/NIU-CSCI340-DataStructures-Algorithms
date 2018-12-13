.DEFAULT_GOAL := assignment98.exe

assignment98.o: assignment98.cc
	g++ -c assignment98.cc -Wall -std=c++11

assignment98.exe: assignment98.o
	g++ -o assignment98.exe assignment98.o -Wall -std=c++11

clean:
	rm *.o assignment98.exe
