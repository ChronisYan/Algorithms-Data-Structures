package algorithms

// given a Binary Tree return the sum of all its Nodes' depth
// Depth - distance between current Node and root Node
type BinaryTree struct {
	Value       int
	Left, Right *BinaryTree
}

// RECURSION
func nodeDepthsHelper(root *BinaryTree, depth int) int {
	if root == nil {
		return 0
	}
	return depth + nodeDepthsHelper(root.Left, depth+1) + nodeDepthsHelper(root.Right, depth+1)
}

func NodeDepths(root *BinaryTree) int {
	return nodeDepthsHelper(root, 0)
}

// ITERATIVE
type Node struct {
	Root  *BinaryTree
	Depth int
}

func NodeDepthsIt(root *BinaryTree) int {
	sum := 0
	stack := []Node{{Root: root, Depth: 0}}
	for len(stack) > 0 {
		cur := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		curNode, curDepth := cur.Root, cur.Depth
		if curNode == nil {
			continue
		}
		sum += curDepth
		stack = append(stack, Node{Root: curNode.Left, Depth: curDepth + 1})
		stack = append(stack, Node{Root: curNode.Right, Depth: curDepth + 1})
	}
	return sum
}

//                        ------------ SIDE NOTE ------------
// Default parameters work around (Golang doesn't have them!)
// Create a helper function with the same params as the original plus any default params you want
// From the OG function call the helper passing the same arguments + any default options you want
// return the result of the helper function
