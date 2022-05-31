class Solution:
    def buildLookup(self, k):
      lookup = []
      if k == 1:
          return {'0':False, '1':False}
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
      asStrList = list(map(lambda x: "".join(x), lookup))
      return { key:False for key in asStrList }

    def hasAllCodes(self, s: str, k: int) -> bool:
        # lookup = self.buildLookup(k)
        count = 0
        lookup = {}
        ks_arr = [s[i:i+k] for i in range(0, len(s) - k + 1)]
        for subs in ks_arr:
          try:
              lookup[subs]
          except:
              lookup[subs] = True
              count+=1
        # try to improve performance
        print(f"count is {count}")
        return count == 2**k

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


i = "00110"
k = 2
print(f"expect true {s.hasAllCodes(i,k)}")

i = "1"
k = 1
print(f"expect false {s.hasAllCodes(i,k)}")

i= "00011010111101010111110111011110101001111001111100010010010001111001000010010010001110010000111000010001001000010011111111100010111011101101111100001110001110101110101001110000010101100100100010100110101110110001000011011011000111001101111000000010101110110100110001100010111111110101010001111000001110000000011111101011011111011110001100011100001011000000111101011100011011111110001010001111110100011110101101101011100100000100110011110111011000001010111011100011000100001000000111101001101010010000111110001110111100100110000101001011010101010101000100011000111100100101100010100111100111000010110011011110110001100101010101111001011000000010"
k = 19
print(f"expect something {s.hasAllCodes(i,k)}")