from ast import Return


class Solution:
    def buildLookup(self, k):
      lookup = []
      for _ in range(k-1):
          if len(lookup) == 0:
              lookup = [['0'], ['1']]
          new_lookup = []
          for j in lookup:
            it = j.copy()
            j.append('0')
            it.append('1')
            new_lookup.append(j)
            new_lookup.append(it)
          lookup = new_lookup
      return lookup

    def hasAllCodes(self, s: str, k: int) -> bool:
        return 

s = Solution()


print(f"build_lookup 2 is {s.buildLookup(2)}")
print(f"build_lookup 3 is {s.buildLookup(3)}")

i = "00110110"
k = 2 
print(f"expect True {s.hasAllCodes(i,k)}")

i = "0110"
k = 1
print(f"expect True {s.hasAllCodes(i,k)}")

i = "0110"
k = 2
print(f"expect False {s.hasAllCodes(i,k)}")