from itertools import permutations

class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        output = []
        perm = permutations(nums)
        for p in perm:
            output.append(list(p))
        return output

s = Solution()
nums = [1,2,3]
output = s.permute(nums)
for i in output:
    print(f'{i} {type(i)}')