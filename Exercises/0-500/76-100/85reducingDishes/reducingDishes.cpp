/*

1402. Reducing Dishes
Hard
1.6K
186
Companies
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.



Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.


Constraints:

n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000
Accepted
59.8K
Submissions
81.9K
Acceptance Rate
73.1%

*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
vector<int> sorted;
int getSum(int start) {
  int multiplier = 1;
  int sum = 0;
  for (int s = start; s < sorted.size(); ++s) {
   sum+=multiplier*sorted[s];
   ++multiplier;
  }
  return sum;
}
public:
    int maxSatisfaction(vector<int>& satisfaction) {
      sorted = satisfaction;
      sort(sorted.begin(), sorted.end());
      for (int item:sorted) {
        cout << item << endl;
      }
      if (sorted[sorted.size()-1] < 0) return 0;
      int max = 0;
      for (int idx = 0; idx < sorted.size(); ++idx) {
        int sum = getSum(idx);

        if (sum > max) max = sum;

        if (sorted[idx] >= 0) return max;
      }
      return 1;
    }
};

/*

naive:
1.  sort
2.  if no positive numbers, return 0
3.  start trials

*/