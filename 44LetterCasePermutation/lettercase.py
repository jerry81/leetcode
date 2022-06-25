from typing import List


class Solution:
    def get_binary_perms(self, numdigits):
        strs = []
        for i in range(1,2**numdigits):
            formatS = '0' + str(numdigits) + 'b'
            asB = format(i, formatS)
            strs.append(asB)
        return strs

    def letterCasePermutation(self, s: str) -> List[str]:
        # first make map of all chars 
        chmap = {}
        res = []
        for idx,c in enumerate(s):
            if c.isalpha():
                chmap[idx] = c
        print(f"chmap is {chmap}")
        return 

sol = Solution()
s = "a1b2"
expect = ["a1b2","a1B2","A1b2","A1B2"]
print(f"expect {expect}\nsol is {sol.letterCasePermutation(s)}")

s = "3z4"
expect = ["3z4","3Z4"]
print(f"expect {expect}\nsol is {sol.letterCasePermutation(s)}")

print(format(5,'08b'))
print(format(25,'8b'))
print(format(25,'08b'))

print(f"getbin4 is {sol.get_binary_perms(3)}")

"""
ab, AB,aB,Ab
00, 11, 01, 10

abc
abC, aBc, Abc
aBC, ABc
ABC
000, 001, 010, 011,
100, 101, 110, 111

0000, 0001,0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111

"""