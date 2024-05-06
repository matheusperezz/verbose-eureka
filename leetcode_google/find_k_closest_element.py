class Solution:
    def findClosestElements(self, A, k, x):
        left, right = 0, len(A) - k
        while left < right:
            mid = int((left + right) / 2)
            if x - A[mid] > A[mid + k] - x:
                left = mid + 1
            else:
                right = mid
        return A[left:left + k]

    
arr = [1,2,3,4,5]
k = 4
x = 3
output = Solution().findClosestElements(arr, k, x)
print(output)