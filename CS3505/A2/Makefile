#	Emile Goulard
#	uID: u1244855
#	CS3505 - Assignment 2

#	Summary:
#		This is a MakeFile meant to compile spiralPDF.cpp (the main file) and its included helpers.
#		You must be in directory containing these files for compilation.

# ---- Variables ---- 
CC = g++
CFLAGS = -std=c++11 -g -Wall
LIBHARU = ./libharu
LIBHARUINCLUDE = $(LIBHARU)/include
LIBHARUDIR = $(LIBHARU)/src
ALL = spiralPDF *.o *.pdf

# ---- This is the target to call in terminal: 'make spiralPDF' in order to compile this assignment ----
spiralPDF : spiralPDF.o Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o -L$(LIBHARUDIR) -lhpdfs

# ---- Object Files ----
spiralPDF.o : spiralPDF.cpp
	$(CC) $(CFLAGS) -I$(LIBHARUINCLUDE) -c spiralPDF.cpp

Spiral.o : Spiral.h Spiral.cpp
	$(CC) $(CFLAGS) -c Spiral.cpp

HaruPDF.o : HaruPDF.h HaruPDF.cpp
	$(CC) $(CLFAGS) -I$(LIBHARUINCLUDE) -c HaruPDF.cpp

# This command cleans out all files created during execution -- (Call it with 'make clean' in terminal).
clean:
	rm -f $(ALL)

# This command runs the executable spiralPDF -- (Call it with 'make test' in terminal after compiling spiralPDF).
test:
	./spiralPDF "This is a biiiiiiig test, I don't think someone can handle this spiral-age to the extreme!"