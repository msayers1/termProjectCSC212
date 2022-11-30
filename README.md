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


### Command line to compile and run at the same time
g++ -g -std=c++11 main.cpp trie.cpp node.cpp -o output && ./output

### Files needed to compile
- main.cpp - main file 
- trie.cpp - trie class file
- node.cpp - node class file

### No arguments are given. A simple command line input is given to recieve a possible Scrabble word and test. Then loops again until the quit command is given. Once you quit from the Scrabble algorithm, it runs through different scenarios with the trie class. and outputs the timing of those scenarios. 