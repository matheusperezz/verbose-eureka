from itertools import permutations

class Solution:
    def permuteUnique(self, nums: list[int]) -> list[list[int]]:
        output = []
        perm = set(permutations(nums))
        for p in perm:
            output.append(list(p))

        return output

s = Solution()
nums = [1,1,2]
print(s.permuteUnique(nums))