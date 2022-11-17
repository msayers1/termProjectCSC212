#include <string>
#include <vector>

class Node{
    private:
        std::string key;
        std::vector<Node*> children;

    public:
        // Not used. Implemented anyway.
        Node();
        Node(int data);

        friend class Trie;
};