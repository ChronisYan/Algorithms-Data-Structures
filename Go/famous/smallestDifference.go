package famous

import "sort"

func SmallestDifference(array1, array2 []int) []int {

	sort.Ints(array1)
	sort.Ints(array2)
	var result []int
	cur, min := 1 << 31, 1 << 31
	i, j := 0, 0


	for i < len(array1) && j < len(array2){
		num1, num2 := array1[i], array2[j]
		if num1 > num2{
			cur = num1 - num2
			j++
		}else if num2 > num1 {
			cur = num2 - num1
			i++
		}else {
			return []int{num1, num2}
		}
		if cur < min {
			min = cur
			result = []int{num1, num2}
		}
	}

	return result
}
