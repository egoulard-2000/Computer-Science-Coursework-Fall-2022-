/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 3

    Summary:
        This class defines a Trie. Each node represents a character 
        from the alphabet given the branch it came from "Node.h". 
        
        This trie is responsible for adding words and checking if 
        words are defined yet from a "".txt" file.

*/
#ifndef TRIE_H
#define TRIE_H
#include "Node.h"

class Trie
{
    private:
        Node* _rootNode;
        std::vector<std::string> allWordsAfterPrefix;

    public:
        //Rule-Of-Three
        Trie();
        ~Trie(); //Destructor
        Trie(const Trie& other); //Copy Constructor
        Trie& operator=(Trie other); //Assignment Overload

        void addAWord(std::string word);
        bool isAWord(std::string word);
        std::vector<std::string> allWordsBeginningWithPrefix(std::string prefixWord);
        void searchWord(Node* node, std::string word);
};

#endif
