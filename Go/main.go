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
	sorted := sort.MergeSort(myArray)
	fmt.Println(myArray)
	fmt.Println(sorted)

	// GRAPH
	fmt.Printf("\n-------------Graphs-------------\n")
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
