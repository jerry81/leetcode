class Solution:
    def reverseWord(self, s:str) -> str:
        asL = list(s)
        newL = []
        for i in range(len(s)):
            curi = len(s) - 1 - i 
            newL.append(asL[curi])
        return "".join(newL)

    def reverseWords(self, s: str) -> str:
        rev = list(map(self.reverseWord, s.split(" ")))
        return " ".join(rev)

sol = Solution()
s = "Let's take LeetCode contest"
Output = "s'teL ekat edoCteeL tsetnoc"
print(f"expect {Output} {sol.reverseWords(s)}")

s = "God Ding"
Output = "doG gniD"
print(f"expect {Output} {sol.reverseWords(s)}")