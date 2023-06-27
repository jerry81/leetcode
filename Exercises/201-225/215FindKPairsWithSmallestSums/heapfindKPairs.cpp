#include <queue>
#include <vector>

using namespace std;

struct HeapItem {
  int sum;
  int i1;
  int i2;
};

struct ComparePQ {
  bool operator()(HeapItem* a, HeapItem* b) {
    return a->sum < b->sum;
  }  // this is idiomatic...
};

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    vector<vector<int>> ret;
    priority_queue<HeapItem*, vector<HeapItem*>, ComparePQ> pq;
    vector<int> start;
    start.push_back(nums1[0]);
    start.push_back(nums2[0]);
    ret.push_back(start);
    int c1 = 0;
    int c2 = 0;
    while (ret.size() < k) {
      HeapItem* hi;
      hi->sum = nums1[c1] + nums2[c2]; // handle oob
      hi->i1 = c1;
      hi->i2 = c2;
      pq.push(hi);
    }
    return ret;
  }
};

/*

1,1,2
1,2,3
1,1,0,0 - combined to 2,0,0
2,1,0


*/