class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        ans = []
        for interval in intervals:
            print(f'Ans={ans} currInterval={interval}')
            if not ans or ans[-1][1] < interval[0]:
                ans.append(interval)
            else:
                ans[-1][1] = max(ans[-1][1], interval[1])
            print(f'Ans={ans} currInterval={interval}')
        
        return ans
    
intervals = [[1,3],[2,6],[8,10],[15,18]]
r = Solution().merge(intervals)