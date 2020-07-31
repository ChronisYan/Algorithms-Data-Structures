package sort

func merge(left []int, right []int) []int {
	merged := make([]int, 0, len(left)+len(right))
	i, j := 0, 0
	for i < len(left) && j < len(right) {
		if left[i] < right[j] {
			merged = append(merged, left[i])
			i++
		} else {
			merged = append(merged, right[j])
			j++
		}
	}
	if i < len(left) {
		merged = append(merged, left[i:]...)
	}
	if j < len(right) {
		merged = append(merged, right[j:]...)
	}
	return merged
}

func MergeSort(array []int) []int {
	if len(array) < 2 {
		return array
	}
	mid := len(array) / 2
	left := MergeSort(array[:mid])
	right := MergeSort(array[mid:])
	return merge(left, right)
}
