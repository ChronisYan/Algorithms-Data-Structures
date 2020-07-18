package algorithms

func traverse(node *BinaryTree, array *[]int, sum int) {
	if node == nil {
		return
	}

	sum += node.Value

	if node.Right == nil && node.Left == nil {
		*array = append(*array, sum)
		return
	}

	traverse(node.Left, array, sum)
	traverse(node.Right, array, sum)
}

func BranchSums(root *BinaryTree) []int {
	var result []int
	sum := 0
	traverse(root, &result, sum)
	return result
}
