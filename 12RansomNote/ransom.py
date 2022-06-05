class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        lookup = {}
        for i in list(magazine):
            try:
                lookup[i] += 1
            except:
                lookup[i] = 1
        for i in list(ransomNote):
            try:
                lookup[i] -= 1
            except: 
                return False 
        for i in lookup.values():
            if i < 0:
                return False 
        return True

s = Solution()