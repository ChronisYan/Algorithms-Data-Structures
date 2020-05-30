package famous

// NAIVE SOLUTION
func NthFibRec(n int) int {
	if n == 2 {
		return 1
	} else if n == 1 {
		return 0
	}
	return NthFibRec(n-1) + NthFibRec(n-2)
}
// O(n) time || O(1) space
func NthFib(n int) int {
	lastTwo := [2]int{0,1}

	if n == 0 {
		return lastTwo[0]
	} else if n == 1 {
		return lastTwo[1]
	}

	for i := 0; i < n-2; i++{
		next := lastTwo[0] + lastTwo[1]
		lastTwo[0] = lastTwo[1]
		lastTwo[1] = next
	}
	return lastTwo[1]
}
