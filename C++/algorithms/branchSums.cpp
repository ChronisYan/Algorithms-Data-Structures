#include <vector>

#define NULL nullptr

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

void traverse(BinaryTree *node, std::vector<int> *array, int sum)
{
    if (node == NULL)
        return;

    sum += node->value;

    if (node->left == NULL && node->right == NULL)
    {
        array->push_back(sum);
        return;
    }

    traverse(node->left, array, sum);
    traverse(node->right, array, sum);
}

std::vector<int> branchSums(BinaryTree *root)
{
    std::vector<int> result;
    traverse(root, &result, 0);
    return result;
}