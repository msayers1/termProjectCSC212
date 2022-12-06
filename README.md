# Trie Data Structure
## Group member names:
###### Michael Sayers msayers1, Vanessa Melgar vmelgar9272, Linda Tran lindaqtran, Shina Adewumi fa-adewumi

### Dependencies
- dot viewer ( such as https://products.groupdocs.app/viewer/dot which will process the wordledictionary to a 918 page document of the trie data structure.)
or
- graphviz ( or other dot conversion tool) to convert dot to another image format ( sample command: dot -Tsvg graph_Visualization.dot -o graph_visualization.jpeg if using graphviz )


### Required files
- Trie.cpp 
- Trie.h
- Node.cpp
- Node.h
- main.cpp
- MobeyDick.txt
- scrabbleWords.txt
- visualizationWordList.txt
- wordledictionarylist.txt
- dictionary.txt


### Extra files
- acknowledgements.txt - source for the word lists. 
- *.dot are the dot files representing the different word lists in our trie data structure. 
- graph_visualization.jpeg - graph of the one list small enough to be converted to a jpeg.
- output.csv - the graph data for the time vs word list size graph.
- MapTrie folder contains the the class using the map data structure vice a vector. 


### Command line to compile and run at the same time
Test all function: g++ -g -std=c++11 main.cpp trie.cpp node.cpp -o output && ./output  
Create graph csv: g++ -g -std=c++11 main_graph.cpp trie.cpp node.cpp -o output && ./output
Use the Scrabble word implementation (will print out instructions, and prompt the user for input): g++ -g -std=c++11 main_scrabble.cpp trie.cpp node.cpp -o output && ./output

### Files needed to compile ( only one of the three files which start with main are required.)
- main.cpp - main file, runs through all the functions
- main_graph.cpp - Generates a csv file which was used to create a graph of time vs word list size. 
- main_scrabble.cpp - Runs the scrabble word checker algorithim. 
- trie.cpp - trie class file
- node.cpp - node class file

### No arguments are given. A simple command line input is given to recieve a possible Scrabble word for the Scrabble main. Once you quit from the Scrabble algorithm, it stops the program. The main simply runs through the different functions to show correct implementation. The main graph cycles thru from 1000 to 1 million by 3000 increments and outputs the timing of for the different functions at the different word list sizes into an output.csv. 