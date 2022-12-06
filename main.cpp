//main.cpp:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
#include "trie.h"

void readFile(std::string filename, std::vector<std::string>*wordList);

int main(int argc, char* argv[]){
    //Initializes the Trie trees for the different word list and insert function combinations. 
    Trie *TrieTree = new Trie();
   
    //initializes the input. 
    std::string input;
    
    //Word: 33
    std::vector<std::string> wordList;
    //Reads the file for the word list. 
    readFile("visualizationWordList.txt", &wordList); 
    //Loop to go throught the word list. 
    for(int i = 0; i < wordList.size(); i++){
        //Inserts each word. 
        TrieTree->recursiveInsert(wordList[i]);
    }
    //Announces the ascend display.
    std::cout << "This is the ascend function output:" << std::endl;
    //runs the ascend function
    TrieTree->ascend();

    //Puts a new line in for spacing.
    std::cout  << std::endl;

    //Puts a new line in for the next function.
    std::cout  << std::endl;


    TrieTree->destroy();
    //Announces the ascend display.
    std::cout << "This shows the destroy function emptied the Trie for the recursive Insert:" << std::endl;
    //Puts a new line in for spacing.
    std::cout  << std::endl;

    //runs the ascend function
    TrieTree->ascend();
    //Puts a new line in for the next function.
    std::cout  << std::endl;

    for(int i = 0; i < wordList.size(); i++){
        //runs the recursive insert function. 
        TrieTree->insert(wordList[i]);
    }
    //Announces the ascend display.
    std::cout << "This is the ascend function again to show proper recursive insertation:" << std::endl;
    //runs the ascend function
    TrieTree->ascend();
    //Puts a new line in for the next function.
    std::cout  << std::endl;
    //Puts a new line in for spacing.
    std::cout  << std::endl;

    //Announces the descend display.
    std::cout << "This is the descend function output:" << std::endl;
    //runs the descend function. 
    TrieTree->descend();
    //Puts a new line in for the next function.
    std::cout  << std::endl;


    TrieTree->remove("buzzword");

    bool output = TrieTree->search("buzzword");

    std::cout << "Buzzword was removed so it should not be found by search:(The following will be the output from search) " << (output?"true":"false") << std::endl;
    
    //Puts a new line in for spacing.
    std::cout  << std::endl;
    output = TrieTree->search("yorgurt");

    std::cout << "Yorgut was not removed so it should be found by search:(The following will be the output from search) " << (output?"true":"false") << std::endl;
    

    //runs the visualization insert function. 
    TrieTree->visualize("graph_Visualization.dot");
    
    
}


void readFile(std::string filename, std::vector<std::string>*wordList){
        // Opens the file for reading
        std::ifstream file(filename);
        // Creates a string to hold each line in temporarily
        std::string str;
        // Creates a string to hold each line in temporarily
        std::string wordTemp;

        // Iterates over the file, storing one line at a time into `str`
        while (getline(file, str)) {
            // Create a stringstream object with each line from the file
            std::istringstream ss(str); 
            //Grabs the values from the line. 
            while(ss >> wordTemp){
                //Places the word on the vector.
                (*wordList).push_back(wordTemp);
            }
            
        }
   }
 
