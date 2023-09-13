/*

135. Candy
Hard
6.3K
446
Companies
There are n children standing in a line. Each child is assigned a rating value
given in the integer array ratings.

You are giving candies to these children subjected to the following
requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies
to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2
candies respectively. Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1
candies respectively. The third child gets 1 candy because it satisfies the
above two conditions.


Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
Accepted
353.8K
Submissions
853.4K
Acceptance Rate
41.5%

*/

#include <vector>

using namespace std;

// greedy? stick 1 in the lowest priorities of the graph
// graph problem?
// if neighbor equal then no constraint on either

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> weights(n, 1);
    // forwards loop
    // compare neighbor
    for (int i = 0; i < n - 1; ++i) {
      int j = i + 1;
      int cur = ratings[i];
      int next = ratings[j];
      while (j < ratings.size() && next > cur) {
        weights[j] = weights[j - 1] + 1;
        j++;
        cur = next;
        next = ratings[j];
      }
    }
    for (int i = n - 1; i >= 1; --i) {
      int j = i - 1;
      int cur = ratings[i];
      int next = ratings[j];
      while (j >= 0 && next > cur) {
        weights[j] = max(weights[j - 1] + 1, weights[j]);
        j--;
        cur = next;
        next = ratings[j];
      }
    }
    int res = 0;
    for (int w : weights) res += w;
    return res;
  }
};