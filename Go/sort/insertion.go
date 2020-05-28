package sort

func Insertion (array []int) []int {
	for i := range array {
		for j := i; j > 0 && array[j] < array[j-1]; j--{
			array[j], array[j-1] = array[j-1], array[j]
		}
	}
	return array
}