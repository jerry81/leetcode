from typing import List


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        curStreak = 0
        maxStreak = 0
        for i in nums:
            if i == 1:
                curStreak+=1 
                if curStreak > maxStreak:
                    maxStreak = curStreak
            else:
                curStreak = 0
        return maxStreak