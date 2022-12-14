/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 3

    Summary:
        This class defines a Node in a Trie. Each node represents a character 
        from the alphabet given the branch it came from. It can also add words
        from a list and define what a word is using these characters.

*/
#ifndef NODE_H
#define NODE_H
#include <vector>
#include <iostream>
#include <string>

const int AlphabetSize = 26;

class Node {
    private:
        Node* _nodeLetters[AlphabetSize];
        bool _isWordFlag;

    public:
        //Rule-Of-Three
        Node();
        ~Node(); //Destructor
        Node(const Node& other); //Copy Constructor
        Node& operator=(Node other); //Assignment Overload

        bool getIsWordFlag();
        void setWordFinished();
        void addLetter(int index);
        Node** getLettersList();
};

#endif