def insertion_sort(a):
    for i in range(1, len(a)):
        j = i
        while j > 0 and a[j - 1] > a[j]:
            a[j], a[j-1] = a[j-1], a[j]
            j -= 1
            print(a)


a = [3, 6, 1, 9, 2]
insertion_sort(a)
print(a)
