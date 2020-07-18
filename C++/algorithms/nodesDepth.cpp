
// given a Binary Tree return the sum of all its Nodes' depth

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

int nodeDepths(BinaryTree *root, int depth = 0)
{
    if (root == NULL)
    {
        return 0;
    }
    return depth + nodeDepths(root->left, depth + 1) +
           nodeDepths(root->right, depth + 1);
}