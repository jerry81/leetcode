from typing import List


class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        return 

sol = Solution()
s = "a1b2"
expect = ["a1b2","a1B2","A1b2","A1B2"]
print(f"expect {expect}\nsol is {sol.letterCasePermutation(s)}")

s = "3z4"
expect = ["3z4","3Z4"]
print(f"expect {expect}\nsol is {sol.letterCasePermutation(s)}")