package algorithms

func IsPalindrome(str string) bool {
	left := 0
	right := len(str) - 1

	for str[left] == str[right] {
		if left >= right {
			return true
		}
		left++
		right--
	}
	return false
}
