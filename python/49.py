from itertools import permutations

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anagram_group = {}

        for s in strs:
            sorted_s = ''.join(sorted(s))

            if sorted_s in anagram_group:
                anagram_group[sorted_s].append(s)
            else:
                anagram_group[sorted_s] = [s]

        return list(anagram_group.values())



s = Solution()
strs = ["eat","tea","tan","ate","nat","bat"]
print(s.groupAnagrams(strs))
