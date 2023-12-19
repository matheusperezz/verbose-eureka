package main

import (
	"fmt"
	"main/leetcode"
	"main/utils"
)

func main() {

	nums := []int{2, 7, 11, 15, 7}
	target := 9

	uniques := utils.RemoveDuplicates(nums)
	fmt.Println(uniques)

	leetcode.TwoSum(nums, target)
}
