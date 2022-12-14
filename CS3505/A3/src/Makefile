#	Emile Goulard
#	uID: u1244855
#	CS3505 - Assignment 3

#	Summary:
#		This is a MakeFile meant to compile TrieTest.cpp (the main file) and its included helpers.

# ---- Variables ---- 
CC = g++
CFLAGS = -std=c++11 -g -Wall
ALL = TrieTest *.o 

TrieTest : Node.o Trie.o TrieTest.o
	$(CC) $(CFLAGS) -o TrieTest Node.o Trie.o TrieTest.o

Node.o : Node.h Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp

Trie.o : Trie.h Trie.cpp
	$(CC) $(CFLAGS) -c Trie.cpp

TrieTest.o : TrieTest.cpp
	$(CC) $(CFLAGS) -c TrieTest.cpp

clean : 
	rm -f $(ALL)

test : 
	./TrieTest "words.txt" "prefixWords.txt"