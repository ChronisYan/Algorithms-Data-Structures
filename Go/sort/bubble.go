package sort

func Bubble (arr []int) []int{
	unsorted := len(arr) - 1
	swap := true
	for{
		if !swap{
			break
		}
		swap = false
		for i := 0; i<unsorted;i++{
			if arr[i] > arr[i+1]{
				swap = true
				temp := arr[i]
				arr[i] = arr[i+1]
				arr[i+1] = temp
			}
		}
		unsorted--
	}
	return arr
}