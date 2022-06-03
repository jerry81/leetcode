from typing import List


class NumMatrix:

    
    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        self.prefix_sums = {}
        # first run - prefix sums per line
        for y,l in enumerate(self.matrix):
            for x,num in enumerate(l):
                prior = 0 if x == 0 else self.prefix_sums[f"{y},{x-1}"] 
                self.prefix_sums[f"{y},{x}"] = num + prior
        # second run - apply the vertical sums 
        for y in range(1,len(matrix)):
            for x in range(len(matrix)):
                prior = self.prefix_sums[f"{y-1},{x}"] 
                self.prefix_sums[f"{y},{x}"] = self.prefix_sums[f"{y},{x}"] + prior
        print(f"prrefix sums are now {self.prefix_sums}")

    def make_key(self,row1,col1,row2,col2):
      return f"{row1},{col1},{row2},{col2}"

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        key = self.make_key(row1,col1,row2,col2)

nm = NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]])
print(f"nm.matrix is {nm.matrix}")
out1 = nm.sumRegion(2, 1, 4, 3); 
print(f"expect 8 {out1}")
brokenlen = len([56334,-28555,-93032,-49515,21604,-17474,98719,-85143,-66171,-65379,-15103,-36949,-16075,-80234,-58582,29332,87342,-72292,12036,65051,-70499,-23383,69759,-11016,-51054,70421,78082,94353,-7351,38031,33184,24107,40690,486,-56287,1772,39808,-38194,-38920,55386,-60774,10137,16364,-89433,-24427,53565,64423,93655,9095,27581,-47648,73989,-89735,31117,-24064,18937,74242,80206,-9878,14081,-48881,-44091,-22328,-70740,-25899,-97446,-5115,-74589,2154,33858,43120,3696,55622,64423,4438,-6617,-41471,6803,-92582,-32562,-6295,-38825,76475,17182,67869,-37278,-3186,49720,-76131,1436,8345,-76348,-78860,34262,12678,-79937,55818,-70222,81334,-54217,35774,26934,10390,64653,-407,-57183,55792,-32074,-78160,74295,-49596,58917,46410,21604,-45419,9985,-40627,36826,64138,10125,38195,97344,-45046,-1985,-9358,47881,-62409,43766,-60471,33672,89462,75473,92793,77778,81768,14290,-30274,78672,-74309,-34383,-61988,-51140,24252,50299,-96405,-25240,-64975,84308,-16522,10941,-64080,81843,-33038,-13833,84824,16357,20235,42814,-33164,-77620,35078,-56760,82962,19273,81015,-55368,-45776,80935,63084,-45901,7575,-31393,-5635,-25472,-61653,-1413,-95972,94535,-13906,-16074,7602,-84591,-79309,24768,3735,19067,74620,-55702,-45024,-22752,-64374,-89789,-97229,80044,92268,63850,-33495,-55181,27651,-88536])
print(f"brokenlen is {brokenlen}")

nm2 = NumMatrix([[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]])
print(f"nm2.matrix is {nm2.matrix}")
out1 = nm.sumRegion(2, 1, 4, 3)
# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)