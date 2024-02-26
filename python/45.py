class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0

        jumps = 0
        farthest = 0
        current_end = 0

        for i in range(n - 1):
            farthest = max(farthest, i + nums[i])
            if i == current_end:
                jumps += 1
                current_end = farthest
                if current_end >= n - 1:
                    break

        return jumps

if __name__ == '__main__':
    s = Solution()

    nums = [2, 3, 1, 1, 4]
    print(s.jump(nums)) # 2

    # 0,2 -> 2 vamos para 0
    # 2,0 -> 2 vamos para 0
    nums = [2, 3, 0, 1, 4]
    print(s.jump(nums)) # 2

    nums = [0]
    print(s.jump(nums))

    nums = [1,3,2]
    print(s.jump(nums))