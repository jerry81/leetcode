/*

703. Kth Largest Element in a Stream
Easy
4.1K
2.5K
Companies
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.


Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8


Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.
Accepted
361.5K
Submissions
649.3K
Acceptance Rate
55.7%

*/
#include <vector>
using namespace std;
class KthLargest {
vector<int> _nums;
int _k;
public:
    KthLargest(int k, vector<int>& nums) {
      sort(nums.begin(), nums.end());
      _nums = nums;
      _k = k;
    }

    int add(int val) {
      bool broke = false;
      for (int i = 0; i < _nums.size(); ++i) {
        if (_nums[i] > val) {
          _nums.insert(_nums.begin()+i, val);
          broke = true;
          break;
        }
      }
      if (!broke) _nums.push_back(val);
      return _nums[_nums.size()-_k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */