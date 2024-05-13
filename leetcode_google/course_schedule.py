"""
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
"""

from collections import deque

class Solution:
    def canFinish(self, n: int, prerequisites: list[list[int]]) -> bool:
        adj = [[] for _ in range(n)]
        indegree = [0] * n
        ans = []

        for pair in prerequisites:
            course = pair[0]
            prerequisites = pair[1]
            adj[prerequisites].append(course)
            indegree[course] += 1
        
        queue = deque()
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)

        while queue:
            current = queue.popleft()
            ans.append(current)

            for next_course in adj[current]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    queue.append(next_course)

        return len(ans) == n

num = 2
prerequisites = [[1,0],[0,1]]
r = Solution().canFinish(num, prerequisites)