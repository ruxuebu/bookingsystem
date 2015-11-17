booking: Source.o Record.o
	g++ -o booking Source.o Record.o
Source.o: Source.cpp Record.h
	g++ -c Source.cpp
Record.o: Record.cpp Record.h
	g++ -c Record.cpp