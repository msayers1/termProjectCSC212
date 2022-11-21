#include "trie.h"

// Inserts an std::string into the trie
void insert(Node* root, std::string entry){
    // If the trie is empty, return CBT
    if (root == nullptr) {
        std::cout << "Trie empty." << std::endl;
        return;
    }
    // Create a temporary node that will iterate through the trie
    Node* currentNode = root;
    // Loop through the length of the string being inserted
    for (int i = 0; i < entry.length(); i++) {
        // Initialize the index variable, representing the location of the character
        int index;
        if(entry[i] >= 'A' && entry[i] <= 'Z'){
            index = entry[i] - 'A';
        }
        if(entry[i] >= 'a' && entry[i] <= 'z'){
            index = entry[i] - 'a';
        }
        // If the node reached is empty...
        if (currentNode->children[index] == nullptr) {
            // Create a new node at that index
            currentNode->children[index] = newNode(entry[i]);
            // Update the node's generation
            currentNode->children[index]->generation = i;
            // Add the node's value
            currentNode->children[index]->key = entry[i];
        }
        // Travel to the next node
        currentNode = currentNode->children[index];
    }
    // Mark the last letter as the end of a word
    currentNode->isWord = true;
}

void Trie::preorder(Node* root, std::ostream& os){
}

void Trie::inorder(Node* root, std::ostream& os){
}

void Trie::postorder(Node* root, std::ostream& os){
}

void Trie::destroy(Node* root){

}

bool Trie::search(std::string data, Node* root){
    
    //
    int location = 0; 
    
    // If the trie is empty
    if (root == nullptr) {
        std::cout << "Trie empty." << std::endl;
        return false;
    }
    
     // Create a temporary node that will iterate through the trie
    TrieNode* currentNode = root;
    
    // loops through data string 
    for(int i = 0; i < data.length(); i++){
        
    
   return 
}

bool Trie::remove(std::string data, Node* root){

}
/*
 * Public Functions
*/

Trie::Trie(){

}

Trie::~Trie(){

}

void Trie::insert(std::string data){
    

}


void Trie::preorder(std::ostream& os){

}

void Trie::inorder(std::ostream& os){

}

void Trie::postorder(std::ostream& os){

}

bool Trie::search(std::string data){

}

bool Trie::remove(std::string data){

}
