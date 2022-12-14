/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 3

    Summary:
        This program uses defined methods from "Node.h" to give functionality to Nodes in a Trie.

*/
#include "Node.h"

/*
    Constructor
*/
Node::Node() {
    for(int i = 0; i < 26; i++) {
        _nodeLetters[i] = nullptr;
    }

    _isWordFlag = false;
}

/*
    Destructor
*/
Node::~Node() {
    for(int i = 0; i < 26; i++) {
        delete _nodeLetters[i];
    }
}

/*
    Copy Constructor
*/
Node::Node(const Node& other) {
    for(int i = 0; i < 26; i++) {
       _nodeLetters[i] = other._nodeLetters[i];
    }

    _isWordFlag = other._isWordFlag;
}

/*
    Assignment Overload Operator
*/
Node& Node::operator=(Node other) {
    std::swap(_nodeLetters, other._nodeLetters);
    std::swap(_isWordFlag, other._isWordFlag);

    return *this;
}

/*
    Add the letter node at an index
*/
void Node::addLetter(int index) {
    _nodeLetters[index] = new Node();
}

/*
    Grab the nodes
*/
Node** Node::getLettersList() {
    return _nodeLetters;
}

/*
    Returns if this node sequence is a word
*/
bool Node::getIsWordFlag() {
    return _isWordFlag;
}

/*
    Defines a word in a node sequence
*/
void Node::setWordFinished() {
    _isWordFlag = true;
}