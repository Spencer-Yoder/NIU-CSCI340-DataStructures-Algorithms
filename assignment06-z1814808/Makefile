#  Spencer Yoder
#    Z1814808
#    CSCI 340-2
#
#    I certify that this is my own work and where appropriate an extension
#    of the starter code provided for the assignment.
.DEFAULT_GOAL := assignment06.exe

assignment06main.cc:

assignment06.o: assignment06main.cc
	g++ -c assignment06main.cc -Wall -std=c++11 -I.

assignment06.exe: assignment06.o
	g++ -Wall -g -std=c++11 assignment05.cc assignment06.cc assignment06main.cc -o assignment06.exe
clean:
	rm *.o assignment06.exe
