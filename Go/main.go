package main

import (
	ds "./data-structures"
	sort "./sort"
	"fmt"
)

func main() {
	myArray := []int{3, 100, 73, 2, 532, 1, 90, 21, 15, 54, 17}
	//sort.Bubble(myArray)
	//sort.Insertion(myArray)
	sort.Selection(myArray)
	fmt.Println(myArray)

	// GRAPH
	graph := ds.NewNode("A").AddChildren("B", "C", "D")
	graph.Children[0].AddChildren("E").AddChildren("F")
	graph.Children[2].AddChildren("G").AddChildren("H")
	graph.Children[0].Children[1].AddChildren("I").AddChildren("J")
	graph.Children[2].Children[0].AddChildren("K")

	var array []string
	visited := make(map[string]bool)

	graph.DepthFirstSearch(&array, visited)

	fmt.Println(array)
}
