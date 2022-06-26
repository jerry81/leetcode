class Solution:
    def hammingWeight(self, n: int) -> int:
        as_b = format(n,'032b')
        one_count = 0
        for i in as_b:
            if i == '1':
                one_count+=1
        return one_count

s = Solution()
n = 0b00000000000000000000000000001011
a = 3
print(f"expect {a}\ns is {s.hammingWeight(n)}")

n = 0b00000000000000000000000010000000
a = 1
print(f"expect {a}\ns is {s.hammingWeight(n)}")


n = 0b11111111111111111111111111111101
a = 31
print(f"expect {a}\ns is {s.hammingWeight(n)}")
