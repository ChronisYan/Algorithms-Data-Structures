// Find the colest value in a BST
// A valid BST node:
// its value is greater than the values of every node to its left
// its value is less than or equal to the values of every node to its right
// its children nodes are either valid BST nodes themselves or null
#define NULL nullptr

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int abs(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

int findClosestValueInBst(BST *tree, int target)
{
    BST *curNode = tree;
    int result = tree->value;
    int score_to_beat = abs(tree->value, target);
    while (curNode != NULL)
    {
        int curDifference = abs(curNode->value, target);
        if (curDifference < score_to_beat)
        {
            result = curNode->value;
            score_to_beat = curDifference;
        }
        if (curNode->value > target)
        {
            curNode = curNode->left;
        }
        else if (curNode->value < target)
        {
            curNode = curNode->right;
        }
        else
        {
            break;
        }
    }
    return result;
}