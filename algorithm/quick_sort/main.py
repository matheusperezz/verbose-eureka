def partition(arr, low, high):
    pivot = arr[high]
    leftwall = low - 1

    for i in range(low, high):
        if arr[i] <= pivot:
            leftwall = leftwall + 1
            arr[i], arr[leftwall] = arr[leftwall], arr[i]
    
    arr[leftwall+1], arr[high] = arr[high], arr[leftwall+1]
    return leftwall + 1

def quick_sort(arr, low, high):
    if low < high:
        pivot_location = partition(arr, low, high)
        quick_sort(arr, low, pivot_location - 1)
        quick_sort(arr, pivot_location + 1, high)

a = [9, 7, 3, 2, 0, 12, 2]
high = len(a) - 1
quick_sort(a, 0, high)

print(a)