package main

import (
	"fmt"
)

func main() {
	var a, m, c int
	fmt.Scanf("%d %d %d", &a, &m, &c)
	max_sw := min(a/2, min(m/2, c/5))

	fmt.Println(max_sw)
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
