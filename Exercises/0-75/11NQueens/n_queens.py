from typing import List

class Solution:
    def place_queen(self, matrix, y, x):
        h = len(matrix)
        cp = [l.copy() for l in matrix]
        cp[y][x] = 'Q'
        w = 0
        if h > 0:
          w = len(cp[0])
        for off in range(h):
          if off != x:
            cp[y][off] = 'x'

          if off != y:
            cp[off][x] = 'x'

          # diagonal
          if off == 0: 
              continue

          if (off+x) < w and (off+y) < h:
              cp[off+y][off+x] = 'x'
          
          if (x-off) >= 0 and (y-off) >= 0:
              cp[y-off][x-off] = 'x'
          
          # reverse diag

          if (off+x) < w and (y-off) >= 0:
              cp[y-off][x+off] = 'x'

          if (x-off) >= 0 and (y+off) < h:
              cp[y+off][x-off] = 'x'
        return cp
    
    def convert(self, x):
        return x if x == 'Q' else '.'

    def convertL(self,x):
        return "".join(list(map(self.convert,x)))
    
    def convertLofL(self,x):
        return list(map(self.convertL,x))

    def queensR(self, m, accum):
        if len(m) == 1:
            line = m[0]
            for i,x in enumerate(line):
                if x == '.':
                    line[i] = 'Q'
                    ac = [a.copy() for a in accum]
                    ac.append(line)
                    return [ac] 
            return []
        line = m[0]
        candidates = []
        for i,x in enumerate(line):
            if x == '.':
                candidates.append(i)
        if len(candidates) == 0:
            return []
        results = []
        for i in candidates:
            lineC = line.copy() 
            lineC[i] = 'Q'
            newM = self.place_queen(m,0,i)
            del(newM[0])
            accumC = [a.copy() for a in accum]
            accumC.append(lineC)
            res = self.queensR(newM, accumC)
            if len(res) > 0:
                for r in res:
                    results.append(r)
        return results 


            

    def solveNQueens(self, n: int) -> List[List[str]]:
        matrix = [['.'] * n for _ in range(n)]

        # place q 
        # move to y = 1 and choose first available square - reapply 
        # repeat until no squares to place or y=7 line has been placed 
        if n == 1: 
          return [['Q']]
        results = self.queensR(matrix, [])
        results = list(map(self.convertLofL, results))
           
        return results
            

s = Solution()
print(f"expect [['Q']] {s.solveNQueens(1)}")
print(f"expect example {s.solveNQueens(4)}")

# print(f"place queen test: ")
# mat = [['.']*3 for _ in range(3)]
# print(f"result {s.place_queen(mat, 0,0)}")
# 
# print(f"place queen test: ")
# mat = [['.']*4 for _ in range(4)]
# print(f"result {s.place_queen(mat, 1,1)}")
# 
# print(f"place queen test: ")
# mat = [['.']*4 for _ in range(4)]
# print(f"mat is {mat}")
# cp = [x.copy() for x in mat] # copy not enough for 2d array!  list comprehension faster than deep copy
# 
# print(f"result {s.place_queen(cp, 3,1)}")
# 
# mat = [['.']*4 for _ in range(4)]
# print(f"test queenR {s.queensR(mat,[])}")
# 
# mat = [['.']*3 for _ in range(3)]
# print(f"test queenR {s.queensR(mat,[])}")
# 
# mat = [['.']*5 for _ in range(5)]
# print(f"test queenR {s.queensR(mat,[])}")
# 
# mat = [['.']*6 for _ in range(6)]
# print(f"test queenR {len(s.queensR(mat,[]))}")
# 
# mat = [['.']*7 for _ in range(7)]
# print(f"test queenR {s.queensR(mat,[])}")
# 
# mat = [['.']*8 for _ in range(8)]
# print(f"test queenR {len(s.queensR(mat,[]))}")
# 
# mat = [['.']*9 for _ in range(9)]
# print(f"test queenR {len(s.queensR(mat,[]))}")