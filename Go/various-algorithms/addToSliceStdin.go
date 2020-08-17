package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func sort(array []int, i int) {
	for i > 0 && array[i] < array[i-1] {
		temp := array[i]
		array[i] = array[i-1]
		array[i-1] = temp
		i--
	}
}
func main() {
	array := make([]int, 3)
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a number or X to exit: ")
	input, _ := reader.ReadString('\n')
	char := input[:len(input)-1]
	indexInArray := 0

	for char != "X" {
		n, err := strconv.Atoi(char)
		if err != nil {
			fmt.Print("Enter a number or X to exit: ")
			input, _ := reader.ReadString('\n')
			char = input[:len(input)-1]
		} else {
			if indexInArray < 3 {
				array[indexInArray] = n
				sort(array, indexInArray)
				indexInArray++
			} else {
				array = append(array, n)
				sort(array, len(array)-1)
			}
			fmt.Println(array)
			fmt.Print("Enter a number or X to exit: ")
			input, _ := reader.ReadString('\n')
			char = input[:len(input)-1]
		}
	}
}
