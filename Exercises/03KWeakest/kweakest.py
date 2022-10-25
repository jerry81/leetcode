from typing import List


class Solution:
    def soldiers(self, l: List[int]):
        return list(filter(lambda x: x > 0, l))

    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        mapped = list(map(self.soldiers, mat))
        d = dict(enumerate(mapped))
        print(f"d is {d}")
        s =  {k: v for k,v in sorted(d.items(), key=lambda item: len(item[1]))}
        return list(s.keys())[:k]

sol = Solution()

mat = [[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]]
k = 3
print(f"expect [2,0,3] {sol.kWeakestRows(mat, k)}")