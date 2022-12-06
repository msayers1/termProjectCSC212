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

struct dataNode {
    int wordListCount;
    float insertTime;
    float recursiveInsertTime;
    float visualizationTime;
};

void readFile(std::string filename, std::vector<std::string>*wordList);
void writeFile(std::vector<dataNode>* dataVector, std::string filename);

int main(int argc, char* argv[]){
    //Initializes the Trie trees for the different word list and insert function combinations. 
    Trie *TrieTree = new Trie();

  bool running = true;
    bool result = false;
    
    // Initialize vector of nodes for the time values. 
    std::vector<dataNode> dataVector;
    //initialize the state and stop times. 
    unsigned long cStart , cEnd ;
    float time;
    int index;
    dataNode currentData;
    //Word: 33
    std::vector<std::string> wordList;
    std::vector<std::string> wordListForLoop;
    //Reads the file for the word list. 
    readFile("wordledictionarylist.txt", &wordList); 
    //Starts the clock for the insert function.
    int i = 1000;
    while(i < 1000001){
        index = 0;
        currentData.wordListCount = i; 
        for(int j = 1; j <= i; j++){
            wordListForLoop.push_back(wordList[index]);
            if(index  < (wordList.size() - 1)){
                index++;
            } else {
                index = 0;
            }
        }
 
        cStart = std::clock();
        for(int k = 0; k < wordListForLoop.size(); k++){
            //runs the insert function. 
            TrieTree->insert(wordListForLoop[k]);
        }
        
        //Stops the clock for the insert function. 
        cEnd = std::clock();
        //intialize and multiplies the difference of the start and stop, divides by clocks per second. 
        time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
        //Pushes the time value on the insert vector. 
        currentData.insertTime = time;
        TrieTree->destroy();
        //Starts the clock for the recursive insert function. 
        cStart = std::clock();
        for(int k = 0; k < wordListForLoop.size(); k++){
            //std::cout << wordList[i] << std::endl;
            //runs the insert function. 
            TrieTree->recursiveInsert(wordListForLoop[k]);
        }
        //Stops the clock for the insert function.
        cEnd = std::clock();
        //intialize and multiplies the difference of the start and stop, divides by clocks per second. 
        time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
        //Pushes the time value on the recursive insert vector. 
        currentData.recursiveInsertTime = time;
    
        //Starts the clock for the visualization function. 
        cStart = std::clock();
        //runs the visualization insert function. 
        TrieTree->visualize("graph_Visualization.dot");
        //Stops the clock for the visualization function.
        cEnd = std::clock();
        //intialize and multiplies the difference of the start and stop, divides by clocks per second. 
        time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
        //Pushes the time value on the visualization vector. 
        currentData.visualizationTime = time;
        TrieTree->destroy();
        wordListForLoop.clear();
        dataVector.push_back(currentData);
        i = i + 3000;
        std::cout << i << std::endl;
    }
 
    writeFile(&dataVector, "output.csv");

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
 
void writeFile(std::vector<dataNode>* dataVector, std::string filename){
    std::ofstream output_file(filename);
    for(std::vector<dataNode>::const_iterator i = dataVector->begin(); i != dataVector->end(); ++i){
        // Use an interator to traverse the inner dimention
            output_file << i->wordListCount << "," << i->insertTime << "," <<i->recursiveInsertTime << "," << i->visualizationTime << "\n";
    }
}