class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        m = {}
        n = len(nums)
        for i in range(n):
            complement = target - nums[i]
            if complement in m:
                return [m[complement], i]
            m[nums[i]] = i
        return []

nums = [2,7,11,15]
target = 9
result = Solution().twoSum(nums, target)
print(result)
