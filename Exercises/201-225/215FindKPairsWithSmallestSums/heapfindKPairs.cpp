#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct HeapItem {
  int sum;
  int i1;
  int i2;
  HeapItem(int sum, int i1, int i2) : sum(sum), i1(i1), i2(i2){};
};

struct ComparePQ {
  bool operator()(HeapItem* a, HeapItem* b) {
    return a->sum > b->sum;
  }  // this is idiomatic...
};

string getHash(int i, int j) { return to_string(i) + " " + to_string(j); };

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    vector<vector<int>> ret;
    unordered_map<string, bool> visited;
    priority_queue<HeapItem*, vector<HeapItem*>, ComparePQ> pq;

    HeapItem* first = new HeapItem(nums1[0] + nums2[0], 0, 0);
    visited[getHash(0, 0)] = true;

    pq.push(first);

    while (ret.size() < k) {
      HeapItem* minHI = pq.top();
      pq.pop();
      vector<int> item;
      int c1 = minHI->i1;
      int c2 = minHI->i2;
      item.push_back(nums1[c1]);
      item.push_back(nums2[c2]);
      ret.push_back(item);
      int n1 = c1 + 1;
      int n2 = c2 + 1;
      if (n1 < nums1.size() && n2 < nums2.size()) {
        if (!visited[getHash(c1, n2)]) {
          visited[getHash(c1, c2)] = true;

          HeapItem* nextItem1 = new HeapItem(nums1[c1] + nums2[n2], c1, n2);
          pq.push(nextItem1);
        }

        if (!visited[getHash(n1, c2)]) {
          visited[getHash(n1, c2)] = true;

          HeapItem* nextItem = new HeapItem(nums1[n1] + nums2[c2], n1, c2);
          pq.push(nextItem);
        }

        continue;
      }

      // out of bounds
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