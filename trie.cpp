#include "trie.h"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iomanip>

void Trie::recursiveInsert(Node* root,std::string data, int pointer){
    // If the trie is empty, return CBT
    if (root == nullptr) {
        root = new Node("root");
        this->root = root;
    }
    // Create a temporary node that will iterate through the trie
    Node* currentNode = root;
    // if the end of the word...
    if(pointer == (data.length()-1)){
        bool found;
        //Make a word Node
        for(int i = 26; i < currentNode->children.size(); i++){
            // std::cout << entry << "/" << currentNode->children[i]->key << ": " <<  (currentNode->children[i]->key == entry) << std::endl;            
            //checks to see if the key is the full word.
            if(currentNode->children[i]->key == data){
                // std::cout << entry << " " <<  currentNode->children[i]->count << std::endl;            
                //sets found to true;
                found = true;
                //
                currentNode = currentNode->children[i];
                currentNode->count = currentNode->count + 1;
            }
        }
        if(!found){
            //Finish the word. 
            Node* temp = new Node(data);
            currentNode->children.push_back(temp);
            currentNode->numChildren++;
            currentNode = temp;
            currentNode->isWord = true;
            currentNode->count = 1;
        }
        return;
    }

    int index;
    int intLetter;
    char letter;
    // Initialize the index variable, representing the location of the character
    if(data[pointer] >= 'A' && data[pointer] <= 'Z'){
        index = data[pointer] - 'A';
        intLetter  = data[pointer] + 32;
        letter = char(intLetter);
    }
    if(data[pointer] >= 'a' && data[pointer] <= 'z'){
        index = data[pointer] - 'a';
        letter = data[pointer];
    }
    // If the node reached is empty...
    if (currentNode->children[index] == nullptr) {
        // Create a new node at that index
        currentNode->children[index] = new Node(letter);
        // Increment the number of children counter
        currentNode->numChildren++;
        // Update the node's generation - there is no generation yet. 
        //currentNode->children[index]->generation = i;
        // Add the node's value - the key is setup with new Node. 
        //currentNode->children[index]->key = data[pointer];
    }
    // Travel to the next node
    pointer++;
    this->recursiveInsert(currentNode->children[index], data, pointer);

    // Mark the last letter as the end of a word 
    
    //std::cout << entry << " was entered into the trie." << std::endl;
    return;
}


// Inserts an std::string into the trie
void Trie::insert(Node* root, std::string entry){
    // If the trie is empty, return CBT
    if (root == nullptr) {
        std::cout << "Trie empty." << std::endl;
        return;
    }
    // Create a temporary node that will iterate through the trie
    Node* currentNode = root;
    // Loop through the length of the string being inserted
    int index;
    for (int i = 0; i < entry.length(); i++) {
        // Initialize the index variable, representing the location of the character
        if(entry[i] >= 'A' && entry[i] <= 'Z'){
            index = entry[i] - 'A';
        }
        if(entry[i] >= 'a' && entry[i] <= 'z'){
            index = entry[i] - 'a';
        }
        // If the node reached is empty but not the end of the word...
        if (currentNode->children[index] == nullptr && (i != (entry.length() - 1))) {
            // Create a new node at that index
            currentNode->children[index] = new Node(entry[i]);
            // Increment the number of children counter
            currentNode->numChildren++;
            // Update the node's generation - there is no generation yet. 
            //currentNode->children[index]->generation = i;
            // Add the node's value - the key is setup with new Node. 
            //currentNode->children[index]->key = entry[i];
        } 
        //if the end of the word...
        if (i == (entry.length() - 1)){
            //set up flag to tell if the word is found. 
            bool found = false;
            int index;
            //std::cout << entry << "number of children of the currentNode:" << currentNode->children.size() << std::endl;
            //Cycle through the different words at with the same first letters. 
            for(int i = 26; i < currentNode->children.size(); i++){
                // std::cout << entry << "/" << currentNode->children[i]->key << ": " <<  (currentNode->children[i]->key == entry) << std::endl;            
                //Checks if the key(value) is equal to the entry 
                if(currentNode->children[i]->key == entry){
                    // std::cout << entry << " " <<  currentNode->children[i]->count << std::endl;            
                    //Sets found to true
                    found = true;
                    //Sets the current Node to the entry node. 
                    currentNode = currentNode->children[i];
                    //Increments the count. 
                    currentNode->count = currentNode->count + 1;
                }
            }
            //Deals with if the word is not found. 
            if(!found){
                //creates a node for the whole word
                Node* temp = new Node(entry);
                //pushes it on the end of the vector;
                currentNode->children.push_back(temp);
                // Increment the number of children counter
                currentNode->numChildren++;
                //sets the temp to current. 
                currentNode = temp;
                //Sets the whole word to true
                currentNode->isWord = true;
                //Sets count to 1. 
                currentNode->count = 1;
            }
        } else {
            // Travel to the next node
            currentNode = currentNode->children[index];
        } 
        
    }
    // Mark the last letter as the end of a word 
    
    //std::cout << entry << " was entered into the trie." << std::endl;
    
}

void Trie::preorder(Node* root, std::ostream& os){
    Node* currentNode = root;
    Node*child;
    for(int i = 0; i < currentNode->children.size(); i++){
        child = currentNode->children[i];
        if(child != nullptr){
            return;
        }
        std::cout << child << " ";
        preorder(child->left);
        preorder(child->right);
    }
}

void Trie::inorder(Node* root, std::ostream& os){
    Node* currentNode = root;
    Node*child;
    for(int i = 0; i < currentNode->children.size(); i++){
        child = currentNode->children[i];
        if(child != nullptr){
            return;
        }
        inorder(child->left, os);
        std::cout << child << " ";
        preorder(child->right);
    }
}

void Trie::postorder(Node* root, std::ostream& os){
    Node* currentNode = root;
    Node*child;
    for(int i = 0; i < currentNode->children.size(); i++){
        child = currentNode->children[i];
        if(child != nullptr){
            return;
        }
        inorder(child->left);
        preorder(child->right);
        std::cout << child << " ";
    }
}

void Trie::destroy(Node* root){

}

int Trie::search(std::string data, Node* root){
    
    int count = 0;    
    int index = 0;
   
    for(int i = 0; i < data.size(); i++){
        // call insert function containing all words 
        insert(data[i]);
    }
     
    // see if the full word is there 
    if (i == (data.length() - 1)){
        for(int i = 26; i < currentNode->children.size(); i++){
               if(root -> children[i])
                   count += root -> children[i]; 
        }
    }
    
    // If the root(head) is empty
    if (root == nullptr) {
        std::cout << "Trie empty." << std::endl;
        return false;
    }
    
     // Create a temporary node that will iterate through the trie
    Node* currentNode = root;
    
    // loops through data string 
    for(int i = 0; i < data.length(); i++){
        
        // Initialize the index variable, representing the location of the character
        if(data[i] >= 'A' && data[i] <= 'Z'){
            index = data[i] - 'A';
        }
        if(data[i] >= 'a' && data[i] <= 'z'){
            index = data[i] - 'a';
        }
        
        // if current node is not valid
        if (currentNode == nullptr){
            return 0; 
        }else{
              // move to next char
                currentNode = currentNode->children[index];
                
            }
        }
    }
   return count; 
}


// Removes a word from the trie given a key and the trie's root
bool Trie::remove(std::string data, Node* root){
    // If the trie is empty
    if(!root){
        // Return false, key not present
        return false;
    }
    // Create a temporary vector of nodes to hold the root at index 0, each node of the next letter, and the node pointing to the word at the final index
    std::vector<Node*> currentNodes(data.length() + 1);
    // Insert the root at index 0
    currentNodes[0] = root;
    // Loop through the length of the key
    for(int i = 0; i < data.length(); i++){
        // Initialize the index variable, representing which child the next node is
        int index;
        if(data[i] >= 'A' && data[i] <= 'Z'){
            index = data[i] - 'A';
        }
        if(data[i] >= 'a' && data[i] <= 'z'){
            index = data[i] - 'a';
        }
        // If not on the second to last letter of key and the next character of the key is not in the trie...
        if((i != data.length() - 1) && (currentNodes[i]->children[index] == nullptr)) {
            // Return false, was not able to remove, key not present
            return false;
        }
        // If on the second to last letter of the trie...
        if((i == data.length() - 1)){
            // If a node containing the word was never added to the final node's children, it was not marked as a word
            if(currentNodes[i]->children.size() <= 26){
                // Return false, was not able to remove, key is not a word
                return false;
            }
            // If the word was added as a child, placed the word node at the final index of the vector
            currentNodes[i + 1] = currentNodes[i]->children[26];
        }
        // Otherwise...
        else{
            // Set the next index of the vector to the next letter's node
            currentNodes[i + 1] = currentNodes[i]->children[index];
        }
    }
    // Create a removeNode to prevent memory leaks
    Node* removeNode = currentNodes[data.length() - 1]->children[26];
    // Set both the pointer to the node and the node within the currentNodes vector to nullptr
    currentNodes[data.length() - 1]->children[26] = nullptr;
    currentNodes[data.length()] = nullptr;
    // Delete the node containing the word
    delete removeNode;
    // Pop back the children vector to decrement the size back to 26
    currentNodes[data.length()-1]->children.pop_back();
    // Decrement the number of children of the second to last letter
    currentNodes[data.length()-1]->numChildren--;
    // Loop through the key backwards
    for(int i = data.length()-1; i >= 1; i--){
        // If the node doesn't have any children...
        if(currentNodes[i]->numChildren == 0){
            // Delete the node as it is not needed in any other word
            int index;
            char c = currentNodes[i]->key.at(0);
            if(c >= 'A' && c <= 'Z'){
                index = c - 'A';
            }
            if(c >= 'a' && c <= 'z'){
                index = c - 'a';
            }
            currentNodes[i] = nullptr;
            removeNode = currentNodes[i - 1]->children[index];
            currentNodes[i - 1]->children[index] = nullptr;
            delete removeNode;
            // Decrement the number of children the node before the current has
            currentNodes[i-1]->numChildren--;
        }
        // Otherwise, the node is still needed in the trie
        else{
            // Return true, removal was successful
            return true;
        }
    }
    return true;
}

void Trie::visualize(std::ostringstream *listNodes, std::ostringstream *relationships, Node* root){
    Node* currentNode = root;
    Node* child;
    std::string parentKey;
    std::string childKey; 
    //std::cout << "The size:" << (*currentNode).children.size()  << std::endl;
    std::ostringstream get_the_address;
    std::string parentId;
    std::string childId;
    get_the_address.str("");
    get_the_address << currentNode;
    parentId =  get_the_address.str();
    parentId = parentId.erase(0, 2);
    parentKey = (currentNode->key == "")?"Root":currentNode->key;
    parentKey = (currentNode->isWord)?parentKey + "(" + std::to_string(currentNode->count) + ")":parentKey;
    (*listNodes) << "\"" <<  parentId << "\" [label=\"" << parentKey << "\"];\n";
    for(int i = 0; i < currentNode->children.size(); i++){
        child = currentNode->children[i];
        get_the_address.str(""); 
        get_the_address << child;
        childId =  get_the_address.str();
        childId = childId.erase(0, 2);
        if(child != nullptr){
            parentKey = (currentNode->key == "")?"Root":currentNode->key;
            (*relationships) << "\"" << parentId << "\"   -> " << "\"" << childId << "\" ;\n";
            visualize(listNodes, relationships, child);
        } 
    }
    return;
}
/*
 * Public Functions
*/

Trie::Trie(){
    this->root = new Node();

}

Trie::~Trie(){

}

void Trie::recursiveInsert(std::string data){
    this->recursiveInsert(this->root, data);
}


void Trie::insert(std::string data){
    this->insert(this->root, data);
}


void Trie::preorder(std::ostream& os){
     this->preorder(this->root, os);
    }
void Trie::inorder(std::ostream& os){
     this->inorder(this->root, os);
    }
void Trie::postorder(std::ostream& os){
     this->postorder(this->root, os);
    }

bool Trie::search(std::string data){
    this->search(data, this->root);
}

bool Trie::remove(std::string data){
    return this->remove(data, this->root);
}

void Trie::visualize(std::string filename){
    std::ofstream output_file(filename);
    std::ostringstream listNodes;
    std::ostringstream relationships;
    //std::cout << "digraph g {" << std::endl;
    output_file << "digraph g { \n";
    this->visualize(&listNodes, &relationships, this->root);
    output_file << listNodes.str() << relationships.str();
    output_file << "}";
    output_file.close();

    
}
void Trie::timingFunc(std::string data, Node* root, int pointer) {
    
    float value;
    unsigned long cStart , cEnd ;
    
    // checks time for search function performance
    if (search(root, entry) {
       cStart = std::clock();
        value = search(root, entry);
       cEnd = std::clock();

    }
        // checks time for insert function peformance
    else if (insert(data, root)) {
        cStart = std::clock();
        value = insert(root, entry);
        cEnd = std::clock();
       
        
    else if (recursiveInsert(root, data, pointer){
        cStart = std::clock();
        value = recursiveInsert(root, data, pointer);
        cEnd = std::clock();
     
    else{
        std::cout << "Please enter a valid function" << std::endl;

    }

    float time = 1.0 (cEnd - cStart) / CLOCKS_PER_SEC;
        
    std::cout << std::fixed << std::setprecision(4) << time << " Output: " << value << std::endl;
}

