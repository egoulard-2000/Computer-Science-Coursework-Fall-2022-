/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 3

    Summary:
        This is the main method to run from the MakeFile. 

        It takes in 2 other arguments, both of which are text files: 

            -The 1st text file has a word on each line which will be read in order to
            add those into the Trie.
            
            -The 2nd text file is a query that has a word on each line and checks if 
            the words are real words in the Trie (from the 1st text file). It will also
            check for prefixes and suggest words closest to that prefix input

        Lastly, it prints out Rule-Of-Three tests from "Trie.cpp"
*/
#include "Trie.h"
#include <fstream>

int main(int argc, char* argv[]) {

    //Check correct number of arguments
    const int numberOfArguments = 3;
    if(argc != numberOfArguments) {
        std::cout << "Must have 3 arguments (Compile, File1, and File2)" << std::endl;
        return -1;
    }

    Trie testTrie;

//----- Begin reading from words to add to Trie
    std::string wordFileName = argv[1];
    std::ifstream wordFile (wordFileName);
    std::string line;

    //Check if file exists and open it
    if(wordFile.is_open()) {
        while(std::getline(wordFile, line)) {
            testTrie.addAWord(line);
        }

        wordFile.close();

    }
    else {
        std::cout << "Input file1 does not exist. Re-enter existing file" << std::endl;
        return -1; //Invalid FileName
    }

//----- Begin reading from queries to check if these are words in the Trie
    std::string wordQueriesFileName = argv[2];
    std::ifstream wordQueryFile (wordQueriesFileName);
    std::string word;
    
    //Check if file exists and open it
    if(wordQueryFile.is_open()) {
        while(std::getline(wordQueryFile, word)) {

            if(testTrie.isAWord(word)) {
                std::cout << word << " is found" << std::endl;
            }
            else {
                //We haven't found any words, but we can suggest them if the characters are similar enough
                std::vector<std::string> words = testTrie.allWordsBeginningWithPrefix(word);

                if(words.size() == 0) {
                    std::cout << " no alterantives found" << std::endl;
                }
                std::cout << word << " is not found, did you mean:" << std::endl;
                for(unsigned int i = 0; i < words.size(); i++) {
                    std::cout << words.at(i) << std::endl;
                }
            }
        }

        wordQueryFile.close();
    }
    else {
        std::cout << "Input file2 does not exist. Re-enter existing file" << std::endl;
        return -1; //Invalid FileName
    }

// ----------------- Extra Rule of Three Tests -------------------

    std::cout << " " << std::endl;
    std::cout << "----------------Rule Of Three Tests----------------" << std::endl;
    std::cout << " " << std::endl;

    Trie c(testTrie);
    Trie c2(c);

    Trie t = testTrie;
    t = c2;

    return 0;
}