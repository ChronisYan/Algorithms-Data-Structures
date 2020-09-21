// A binary tree is a Binary Search Tree(BST) if for every node in the tree:
// 1 - Nodes in the left subtree are less than itself
// 2 - Nodes in the right subtree are greater than itself

// Dictionary Implementation using a BST
#include <iostream>
#include <stdexcept>
#include <string>

template <typename K, typename V>
class Dictonary
{
public:
    Dictonary() : root_(nullptr){};
    V find(K key)
    {
    }
    void insert(K key, V value)
    {
    }
    V remove(K key){

    };
    void print()
    {
        _traverse(root_);
        std::cout << std::endl;
    }

private:
    class Node
    {
    public:
        K key;
        V value;
        Node *left, *right;
        Node(K key, V value) : key(key), value(value), left(nullptr), right(nullptr){};
    };

    void _traverse(Node *cur)
    {
        if (!cur)
            return;

        std::cout << cur->value << "-> ";

        _traverse(cur->left);
        _traverse(cur->right);
    }
    Node *root_;
};

int main()
{
    Dictonary<int, std::string> D;

    return 0;
}