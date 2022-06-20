class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        return 

sol = Solution()
s1 = "ab"
s2 = "eidbaooo"
expect = "True"
# Explanation: s2 contains one permutation of s1 ("ba").
print(f"expect {expect} {sol.checkInclusion(s1,s2)}")

s1 = "ab"
s2 = "eidboaoo"
expect = "false"
print(f"expect {expect} {sol.checkInclusion(s1,s2)}")
 