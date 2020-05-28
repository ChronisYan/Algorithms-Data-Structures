package sort

func Selection (array []int) []int {
	for i := 0; i < len(array); i++{
		minIndex := i
		for j := i; j < len(array); j++ {
			if array[j] < array[minIndex] {
				minIndex = j
			}
		}
		if i != minIndex {
			array[i], array[minIndex] = array[minIndex], array[i]
		}
	}
	return array
}



