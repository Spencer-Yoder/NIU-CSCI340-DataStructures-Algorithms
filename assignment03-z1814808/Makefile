#  Spencer Yoder
#    Z1814808
#    CSCI 340-2
#
#    I certify that this is my own work and where appropriate an extension
#    of the starter code provided for the assignment.

.DEFAULT_GOAL := assignment03.exe

assignment03.o: assignment03.cc
	g++ -c assignment03.cc -Wall -std=c++11

assignment03.exe: assignment03.o
	g++ -o assignment03.exe assignment03.o -Wall -std=c++11

clean:
	rm *.o assignment03.exe
