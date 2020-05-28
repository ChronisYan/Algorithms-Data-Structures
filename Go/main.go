package main

import (
	sort "./sort"
	"fmt"
)

func main() {
	myArray := []int{3, 100, 73, 2, 532, 1, 90, 21, 15, 54, 17}
	//sort.Bubble(myArray)
	sort.Insertion(myArray)
	fmt.Println(myArray)
}
