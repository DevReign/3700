project1: project1.o point.o fraction.o
	g++ -o main project1.o fraction.o point.o 

project1.o: project1.cpp point.h 
	g++ -c project1.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

fraction.o: fraction.cpp fraction.h
	g++ -c fraction.cpp