package algorithms

// A valid BST node:
// its value is greater than the values of every node to its left
// its value is less than or equal to the values of every node to its right
// its children nodes are either valid BST nodes themselves or null

type BST struct {
	Value int

	Left  *BST
	Right *BST
}

func abs(x, y int) int {
	if x > y {
		return x - y
	} else {
		return y - x
	}
}

func (tree *BST) findClosestValueHelper(target, closest int) int {
	curNode := tree

	for curNode != nil {
		if abs(target, curNode.Value) < abs(target, closest) {
			closest = curNode.Value
		}
		if target > curNode.Value {
			curNode = curNode.Right
		} else if target < curNode.Value {
			curNode = curNode.Left
		} else {
			break
		}
	}
	return closest
}

func (tree *BST) FindClosestValue(target int) int {
	return tree.findClosestValueHelper(target, tree.Value)
}
