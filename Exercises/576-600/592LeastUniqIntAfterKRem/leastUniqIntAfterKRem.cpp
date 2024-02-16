/*


1481. Least Number of Unique Integers after K Removals
Medium
Topics
Companies
Hint
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.



Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.


Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length
Seen this question in a real interview before?
1/4
Yes
No
Accepted
123.6K
Submissions
214.7K
Acceptance Rate
57.6%

*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      // to freq map
      // back to vector of pairs
      // sort
      unordered_map<int, int> freq;
      for (int i: arr) {
        if (freq.find(i) != freq.end()) {
          freq[i]++;
        } else {
          freq[i] = 1;
        }
      }
      vector<int> as_v;
      for (auto [_,v]: freq) {
        as_v.push_back(v);
      }
      sort(as_v.begin(), as_v.end());
      int res = as_v.size();
      for (auto v: as_v) {
        if (k >= v) {
          k-=v;
          res--;
        }
      }
      return res;
    }
};