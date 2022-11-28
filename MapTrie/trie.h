#include "node.h"
#include <iostream>
#include <ostream>
class Trie
{
    private:
        Node* root;

        void recursiveInsert(Node* root, std::string data, int pointer = 0);
        void insert(Node* root, std::string entry);

        void visualize(std::ostringstream* listNodes, std::ostringstream* relationships, Node* root);

        void timingFunc(std::string data, Node* root, int pointer);

    public:
        Trie();
        ~Trie();

        void recursiveInsert(std::string data);
        void insert(std::string data);
        
        void visualize(std::string filename);

};

