// A binary tree is a hierarchical data structure.

// The topmost node is called the root.
// Each node can have up to two children, hence the name Binary tree.
// The two children of a node are the left and right children.
// The node above a node is called its parent. Root has no parent.
// Nodes with no children are called leaves or external nodes.
// Non-Leaf nodes are called internal nodes.
// The number of levels is the height of the tree.
// Siblings: Nodes with the same parent.
// Descendant: Node reachable by traversing children (Nodes in the Subtree).
// Ancestor: Nodes reachable by traversing parents (Nodes on the path from the node to root).

template <typename T>
class BinaryTree
{
public:
    // ...
private:
    class TreeNode
    {
    private:
        T &data;
        TreeNode *left, *right;
        TreeNode(T &data) : data(data), left(nullptr), right(nullptr) {}
    };

    TreeNode *root_;
};