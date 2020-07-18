package algorithms

type BinaryTree struct {
	Value       int
	Left, Right *BinaryTree
}

func nodeDepthsHelper(root *BinaryTree, depth int) int{
	if root == nil {
		return 0
	}
	return depth + nodeDepthsHelper(root.Left, depth + 1) + nodeDepthsHelper(root.Right, depth + 1)
}

func NodeDepths(root *BinaryTree) int {
	return nodeDepthsHelper(root, 0)
}