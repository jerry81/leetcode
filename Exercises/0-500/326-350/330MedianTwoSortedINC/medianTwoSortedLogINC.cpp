#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*
    editorials back!

    binary search method
    - we know the target "index" (half of all elements ish)
    - so we need to find the number that gives us that target index
    - start with nums1 midpoint (idxSum is idx of nums1's midpoint)
    - search in nums2 for this value (totalIdx is idxSum + idxFound)
    - we then repeat with our new search space depending totalIdx's value
    */
  }
};