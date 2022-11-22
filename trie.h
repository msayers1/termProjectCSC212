#include <iostream>
#include <ostream>
#include "node.h"
class Trie
{
    private:
        Node* root;

        void insert(Node* root, std::string entry);
        void preorder(Node* root, std::ostream& os);
        void inorder(Node* root, std::ostream& os);
        void postorder(Node* root, std::ostream& os);

        void destroy(Node* root);
        bool search(std::string data, Node* root);
        bool remove(std::string data, Node* root);
        void visualize(std::ostringstream* listNodes, std::ostringstream* relationships, Node* root);

    public:
        Trie();
        ~Trie();

        void insert(std::string data);
        
        void preorder(std::ostream& os = std::cout);
        void inorder(std::ostream& os = std::cout);
        void postorder(std::ostream& os = std::cout);

        bool search(std::string data);
        bool remove(std::string data);
        void visualize(std::string filename);

};
