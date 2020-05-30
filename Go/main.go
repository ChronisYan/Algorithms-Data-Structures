package main

import (
	famous "./famous"
	sort "./sort"
	"fmt"
)

func main() {
	myArray := []int{3, 100, 73, 2, 532, 1, 90, 21, 15, 54, 17}
	//sort.Bubble(myArray)
	//sort.Insertion(myArray)
	sort.Selection(myArray)
	fmt.Println(myArray)


	fmt.Println(famous.NthFibRec(15))
	fmt.Println(famous.NthFib(15))
}
