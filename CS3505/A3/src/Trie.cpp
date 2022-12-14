/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 3

    Summary:
        This program uses defined methods from "Trie.h" to give functionality to the Trie.

*/
#include "Trie.h"

/*
    Constructor
*/
Trie::Trie() {
    std::cout << "Constructor Executed" << std::endl;
    _rootNode = new Node();
}

/*
    Destructor
*/
Trie::~Trie() {
    std::cout << "Destructor Executed" << std::endl;
    delete _rootNode;
}

/*
    Copy Constructor
*/
Trie::Trie(const Trie& other) {
    std::cout << "Inside Copy Constructor" << std::endl;
    _rootNode = new Node(*(other._rootNode));
}

/*
    Assignment Overload Operator
*/
Trie& Trie::operator=(Trie other) {
    std::cout << "Inside Assignment Operator" << std::endl;
    std::swap(_rootNode, other._rootNode);

    return *this;
}

/*
    Has a node iterate through an input word's characters and adds those into the Trie
*/
void Trie::addAWord(std::string word) {
    //We can't accept empty strings as words
    if(word != "") {

        Node* currentNode = _rootNode;

        for(unsigned int i = 0; i < word.length(); i++) {
            char currentLetter = word[i];
            Node** letterList = currentNode->getLettersList();
        
            //the character isn't defined yet, so we need to add that letter into the trie
            if(letterList[currentLetter - 97] == nullptr) {
                currentNode->addLetter(currentLetter - 97);
            }
            //step into next node in word
            currentNode = letterList[currentLetter - 97];
        }

        currentNode->setWordFinished();
    }
}

/*
    Has a node iterate through an input word's characters to see if those characters form a word that is in the Trie
*/
bool Trie::isAWord(std::string word) {
    //We can't accept empty strings as words
    if(word != "") {

        Node* currentNode = _rootNode;

        for(unsigned int i = 0; i < word.length(); i++) {
            char currentLetter = word[i];
            Node** letterList = currentNode->getLettersList();

            //the character isn't defined yet, so it isn't a word in the trie
            if(letterList[currentLetter - 97] == nullptr) {
                return false;
            }
            //step into next node in word
            currentNode = letterList[currentLetter - 97];
        }

        return currentNode->getIsWordFlag();
    }

    return false;
}

/*
    Begins iterating over the prefix input and then recursively goes down the Trie to find words that follow the prefix
*/
std::vector<std::string> Trie::allWordsBeginningWithPrefix(std::string prefixWord) {
    Node* currentPrefixNode = _rootNode;
    
    //Iterate down prefix's letters such that we can begin looking for words after prefix
    for(unsigned int i = 0; i < prefixWord.length(); i++) {
        //Grab this node's letters in the branch
        Node** prefixLettersList = currentPrefixNode->getLettersList();
        char currentPrefixLetter = prefixWord[i];
        //Ensures that prefix letters aren't branching to undefined characters in an index
        if(prefixLettersList[currentPrefixLetter - 97] != nullptr) {
            currentPrefixNode = prefixLettersList[currentPrefixLetter - 97];
        }
    }

    //start looking from scratch
    allWordsAfterPrefix.clear();

    searchWord(currentPrefixNode, prefixWord);

    return allWordsAfterPrefix;
}

/*
    Helper method to find all suggested words and add them to a vector list
*/
void Trie::searchWord(Node* node, std::string word) {
    for(int i = 0; i < AlphabetSize; i++) {
        //Grab this node's letters in the branch
        Node** letterList = node->getLettersList();

        Node* currentLetterNode = letterList[i];
        if(currentLetterNode != nullptr) {
            char currentLetter = i + 97;

            //Check if prefix is already a word
            if(isAWord(word)) {
                allWordsAfterPrefix.push_back(word);
            }

            //next word simply appends the current letter to the established word
            std::string nextWord = word + currentLetter;
            if(isAWord(nextWord)) {
                allWordsAfterPrefix.push_back(nextWord);
            }

            searchWord(currentLetterNode, nextWord);
        }
    }
}
