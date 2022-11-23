#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Node{
    private:
        std::string key;
        std::vector<Node*> children;
        int count;
        bool isWord;

    public:
        // Not used. Implemented anyway.
        Node();
        Node(std::string data);
        Node(char data);

        friend class Trie;
};
#endif