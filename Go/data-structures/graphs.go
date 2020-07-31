package data_structures

type Node struct {
	Name     string
	Children []*Node
}

func NewNode(name string) *Node {
	return &Node{
		Name:     name,
		Children: []*Node{},
	}
}

func (n *Node) AddChildren(names ...string) *Node {
	for _, name := range names {
		child := Node{Name: name}
		n.Children = append(n.Children, &child)
	}
	return n
}

// Traverse
// Depth First Search (DFS)
func (n *Node) DepthFirstSearch(array *[]string, visited map[string]bool) []string {
	*array = append(*array, n.Name)
	visited[n.Name] = true
	for _, child := range n.Children {
		if _, ok := visited[child.Name]; !ok {
			visited[child.Name] = true
			*array = child.DepthFirstSearch(array, visited)
		}
	}
	return *array
}

// DFS for acyclic graphs or Trees
//func (n *Node) DepthFirstSearch(array []string) []string {
//	array = append(array, n.Name)
//	for _, child := range n.Children {
//			array = child.DepthFirstSearch(array)
//	}
//	return array
//}
