"""
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
"""

def removeDuplicates(nums):
    nums[:] = sorted(set(nums))
    return len(nums)
        

testcase1 = [1,1,2]
testcase2 = [0,0,1,1,1,2,2,3,3,4]
#testcase3 = [0,0,1,1,1,2,2,3,3,4]
#testcase4 = "4193 with words"
#testcase5 = "   000435"
removeDuplicates(testcase1)

print(f'TestCase 1 -> Input: "{testcase1}" || Output: {removeDuplicates(testcase1)}')
print(f'TestCase 2 -> Input: "{testcase2}" || Output: {removeDuplicates(testcase2)}')
#print(f'TestCase 3 -> Input: "{testcase3}" || Output: {removeDuplicates(testcase3)}')
#print(f'TestCase 4 -> Input: "{testcase4}" || Output: {removeDuplicates(testcase4)}')
#print(f'TestCase 5 -> Input: "{testcase5}" || Output: {removeDuplicates(testcase5)}')
