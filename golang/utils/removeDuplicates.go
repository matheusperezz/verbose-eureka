package utils

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
