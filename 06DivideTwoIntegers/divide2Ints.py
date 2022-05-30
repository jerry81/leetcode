class Solution:
    def short_divide(self, d, d2):
        count = 0
        while d >= d2:
            d -= d2
            count+=1
        return count, d

    def long_divide(self, dividend, divisor):
        div_s = str(dividend)
        result = []
        st = 0
        en = 1
        r = 0
        while en <= len(div_s):
          sub_div = div_s[st:en] if r == 0 else "".join([str(r),div_s[st:en]])
          print(f"sub_div is {sub_div}")
          div = int(sub_div)
          if div > divisor:
            print(f"div is {div} divisor is {divisor}")
            q,r = self.short_divide(div, divisor)
            result.append(str(q))
            print(f"q is {q}, result is {result} and r is {r}")
            st = en 
            en +=1
          else: 
              en +=1
        return int("".join(result))

    def divide(self, dividend: int, divisor: int) -> int:
        count = 0
        neg = False
        if (dividend < 0 or divisor < 0) and not (dividend < 0 and divisor < 0):
            neg = True
        divisor = abs(divisor)
        dividend = abs(dividend)
        count = self.long_divide(dividend, divisor)
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
dividend = 100
divisor = 3
print(f"expect 33 {s.divide(dividend, divisor)}")


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