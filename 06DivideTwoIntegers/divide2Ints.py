class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        count = 0
        neg = False
        if (dividend < 0 or divisor < 0) and not (dividend < 0 and divisor < 0):
            neg = True
        divisor = abs(divisor)
        dividend = abs(dividend)
        while dividend >= divisor:
          if divisor == 1:
              count = dividend
              break
          dividend -= divisor 
          count+=1
        count = -count if neg else count
        if count > 2**31 - 1:
            return 2**31 - 1
        if count < (-(2**31) - 1):
            return -2**31
        return count 

s = Solution()
dividend = 10
divisor = 3 
print(f"expect 3 {s.divide(dividend, divisor)}")
dividend = 7
divisor = -3
print(f"expect -2 {s.divide(dividend, divisor)}")

# experimenting with leftshift

print(f"10 >> 1 is {10 >> 1}")
print(f"5 >> 1 is {5 >> 1}")
print(f"100 >> 1 is {100 >> 1}")
print(f"50 >> 1 is {50 >> 1}")

# use long division 
# 200048891 / 2 
# 2/2 = 1 remainder 0 
# 0/2 (3 times) ans 100
# 4/2 = 2 ans 1002
# 8/2 = 4 ans 10024
# 8/2 = 4 ans 100244
# 9/2 = 4 r 1 ans 1002444
# 11/2 = 1 ans 10024445