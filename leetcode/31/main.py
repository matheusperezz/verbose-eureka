from itertools import permutations

def nextPermutation(nums):
    perm_nums = list(permutations(nums))
    perm_nums.sort()
    set_perm_nums = []
    [set_perm_nums.append(item) for item in perm_nums if item not in set_perm_nums]

    if tuple(nums) in set_perm_nums:
        if set_perm_nums.index(tuple(nums)) >= len(set_perm_nums) - 1:
            nums[:] = list(set_perm_nums[0])
        else:
            nums[:] = list(set_perm_nums[set_perm_nums.index(tuple(nums)) + 1])

def nextPermutatio2(nums) -> None:
    n = len(nums)
    
    # Encontra o primeiro índice (a partir do final) onde nums[i] < nums[i+1]
    i = n - 2
    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1
    
    if i >= 0:
        # Encontra o menor número à direita de nums[i] que seja maior que nums[i]
        j = n - 1
        while nums[j] <= nums[i]:
            j -= 1
        
        # Troca nums[i] com nums[j]
        nums[i], nums[j] = nums[j], nums[i]
    
    # Inverte a parte à direita de i
    left, right = i + 1, n - 1
    while left < right:
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1

testcase1 = [1,2,3]
testcase2 = [3,2,1]
testcase3 = [1,1,5]
testcase4 = [2,2,7,5,4,3,2,2,1]
nextPermutation(testcase1)
nextPermutation(testcase2)
nextPermutation(testcase3)
nextPermutation(testcase4)

print(f'TestCase 1 -> Input: "{testcase1}" || Output: {(testcase1)}')
print(f'TestCase 2 -> Input: "{testcase2}" || Output: {(testcase2)}')
print(f'TestCase 3 -> Input: "{testcase3}" || Output: {(testcase3)}')
print(f'TestCase 4 -> Input: "{testcase4}" || Output: {testcase4}')