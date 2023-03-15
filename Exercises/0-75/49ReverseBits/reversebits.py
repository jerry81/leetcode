class Solution:
    def reverseBits(self, n: int) -> int:
        as_b = format(n,"032b")
        rev = list(as_b)[::-1]
        return int("".join(rev),2) # TIL - convert binary string to int 

s = Solution()
n = 0b00000010100101000001111010011100
ret = 964176192 # (00111001011110000010100101000000)
print(f"expect is {ret}\ns is {s.reverseBits(n)}")

n = 0b11111111111111111111111111111101
ret = 3221225471 # (10111111111111111111111111111111)
print(f"expect is {ret}\ns is {s.reverseBits(n)}")

