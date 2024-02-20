class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n < 0: 
            return False
        as_b = format(n,'032b')
        one_count = 0
        for i in as_b:
            if i == '1':
                one_count+=1
                if one_count > 1:
                    return False 
        return one_count == 1

s = Solution()
n = 1
a = "true"
print(f"a is {a}\ns is {s.isPowerOfTwo(n)}")

n = 16
a = "true"
print(f"a is {a}\ns is {s.isPowerOfTwo(n)}")

n = 3
a = "false"
print(f"a is {a}\ns is {s.isPowerOfTwo(n)}")

n = -16
a = 'false'
print(f"a is {a}\ns is {s.isPowerOfTwo(n)}")
