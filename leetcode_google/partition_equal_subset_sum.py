class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        @cache
        def subsetSum(s, i):
            if s == 0: return True
            if i >= len(nums) or s < 0: return False
            return subsetSum(s-nums[i], i+1) or subsetSum(s, i+1)
        total_sum = sum(nums)
        return total_sum & 1 == 0 and subsetSum(total_sum // 2, 0)

nums = [1,1]
output = Solution().canPartition(nums)
print(output)