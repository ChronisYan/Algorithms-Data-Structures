package search

func BinarySearch(array []int, target int) int {
	left := 0
	right := len(array) - 1

	for left <= right {
		curIndex := (left + right) / 2
		if array[curIndex] > target {
			right = curIndex - 1
		} else if array[curIndex] < target {
			left = curIndex + 1
		}else {
			return curIndex
		}
	}
	return -1
}