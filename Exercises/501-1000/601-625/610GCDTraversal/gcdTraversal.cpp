/*


2709. Greatest Common Divisor Traversal
Hard
Topics
Companies
Hint
You are given a 0-indexed integer array nums, and you are allowed to traverse
between its indices. You can traverse between index i and index j, i != j, if
and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

Your task is to determine if for every pair of indices i and j in nums, where i
< j, there exists a sequence of traversals that can take us from i to j.

Return true if it is possible to traverse between all such pairs of indices, or
false otherwise.



Example 1:

Input: nums = [2,3,6]
Output: true
Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0,
2), and (1, 2). To go from index 0 to index 1, we can use the sequence of
traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because
gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to index 1
because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1. To go from index 0 to index
2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1.
Likewise, to go from index 1 to index 2, we can just go directly because
gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1. Example 2:

Input: nums = [3,9,5]
Output: false
Explanation: No sequence of traversals can take us from index 0 to index 2 in
this example. So, we return false. Example 3:

Input: nums = [4,3,12,8]
Output: true
Explanation: There are 6 possible pairs of indices to traverse between: (0, 1),
(0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A valid sequence of traversals
exists for each pair, so we return true.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
Seen this question in a real interview before?
1/4
Yes
No
Accepted
13.8K
Submissions
48.3K
Acceptance Rate
28.6%

*/

#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

class UnionFind {
 public:
  UnionFind(int sz) : root(sz) {
    for (int i = 0; i < sz; i++) {
      root[i] = i;
    }
  }

  int find(int x) {
    while (x != root[x]) {
      x = root[x];
    }
    return x;
  }

  void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      root[rootY] = rootX;
    }
  }

  bool connected(int x, int y) { return find(x) == find(y); }

 private:
  vector<int> root;
};

vector<int> eratosthenes(int MAX) {
  vector<int> sieve(MAX + 1, 0);
  for (int d = 2; d <= MAX; d++) {
    if (sieve[d] == 0) {
      for (int v = d; v <= MAX; v += d) {
        sieve[v] = d;
      }
    }
  }
  return sieve;
}

unordered_set<int> getPrimeFactorsUsingSieve(int n, vector<int>& sieve) {
  unordered_set<int> ret;
  while (n > 1) {
    int factor = sieve[n];
    ret.insert(factor);
    n /= factor;
  }
  return ret;
}

class Solution {
  unordered_set<int> processed;

 public:
  bool canTraverseAllPairs(vector<int>& nums) {
    int MAX_NUM = 100000;
    unordered_set<int> as_s(nums.begin(), nums.end());
    vector<int> sieve = eratosthenes(
        MAX_NUM);  // items are prime if idx+1 is equal to sieve[idx]
    int sz = nums.size();
    if (sz == 1) return true;
    UnionFind uf = UnionFind(MAX_NUM + 1);
    for (int i = 0; i < sz - 1; ++i) {
      int x = nums[i];
      if (x == 1) return false;
      if (processed.find(x) != processed.end()) continue;

      processed.insert(x);
      for (int pf : getPrimeFactorsUsingSieve(x, sieve)) {
        uf.unionSet(x, pf);
      }
    }
    int rootCount = 0;
    for (int i : as_s) {
      if (uf.find(i) == i) rootCount += 1;
      if (rootCount > 1) return false;
    }
    return rootCount == 1;
  }
};