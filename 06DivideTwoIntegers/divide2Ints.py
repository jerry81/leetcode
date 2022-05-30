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