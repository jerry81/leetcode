from collections import defaultdict


class Solution:
    def getFreqMap(self, s):
        m = defaultdict(int)
        for c in s:
          m[c]+=1
        return m
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # sliding window - check freq map match
        baseMap = self.getFreqMap(s1)
        starter = 0
        ender = len(s1)
        trial = s2[starter:ender]
        compareMap = self.getFreqMap(trial)
        if baseMap == compareMap:
            return True 
        while ender < len(s2):
          ender += 1 
          prevStart = s2[starter]
          starter += 1
          newEnd = s2[ender-1]
          compareMap[prevStart] -= 1 
          compareMap[newEnd] += 1 
          if baseMap == compareMap:
            return True 
        return False 

sol = Solution()
s1 = "ab"
s2 = "eidbaooo"
expect = "True"
# Explanation: s2 contains one permutation of s1 ("ba").
print(f"expect {expect} {sol.checkInclusion(s1,s2)}")
print(f"expect a good freq map {sol.getFreqMap(s1)}")
print(f"expect a good freq map {sol.getFreqMap(s2)}")
hashCompare = {'a': 1, 'b': 1} == {'b': 1, 'a': 1}
print(f"expect True {hashCompare}")
s1 = "ab"
s2 = "eidboaoo"
expect = "false"
print(f"expect {expect} {sol.checkInclusion(s1,s2)}")
 