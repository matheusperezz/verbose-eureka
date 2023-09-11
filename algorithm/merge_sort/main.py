def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort(arr[:mid])  # 38, 27, 43
    right = merge_sort(arr[mid:])  # 3, 9, 10

    return merge(left, right)


def merge(left, right):
    i = 0
    j = 0
    result = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result += left[i:]
    result += right[j:]

    return result


# Usage example
arr = [38, 27, 43, 3, 9, 10]
sorted_arr = merge_sort(arr)
print(sorted_arr)
