package leetcode

func TwoSum(nums []int, target int) []int {

	var output []int

	for i, v := range nums {
		for subI, subV := range nums {
			if i != subI && v+subV == target {
				output = append(output, i)
				output = append(output, subI)
				break
			}
		}
	}

	return RemoveDuplicates(output)
}

func RemoveDuplicates(slice []int) []int {
	found := make(map[int]bool)
	var result []int

	for _, value := range slice {
		if _, exists := found[value]; !exists {
			found[value] = true
			result = append(result, value)
		}
	}

	return result
}
