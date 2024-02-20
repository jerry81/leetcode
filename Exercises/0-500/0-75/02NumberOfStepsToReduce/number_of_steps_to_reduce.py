class Solution:
    def numberOfSteps(self, num: int) -> int:
        count = 0
        while num > 0:
            if num % 2 == 0:
              num /= 2
            else:
              num-=1
            count+=1
        return count

s = Solution()
r1 = s.numberOfSteps(14)
r2 = s.numberOfSteps(8)
r3 = s.numberOfSteps(123)
print(f"expect 6 {r1}")
print(f"expect 4 {r2}")
print(f"expect 12 {r3}")