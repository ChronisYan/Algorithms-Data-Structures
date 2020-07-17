#include <iostream>

// Find the colest value in a BST
// Each BST node has an int value, a left child node, and a right child node
// A valid BST node: 
// its value is greater than the values of every node to its left
// its value is less than or equal to the values of every node to its right
// its children nodes are either valid BST nodes themselves or null

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target)
{
    // Write your code here.
    return -1;
}

int main()
{
}
