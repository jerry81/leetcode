/*

1502. Can Make Arithmetic Progression From Sequence
Easy
1.1K
67
Companies
A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.


Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.


Constraints:

2 <= arr.length <= 1000
-106 <= arr[i] <= 106
Accepted
135.8K
Submissions
200.2K
Acceptance Rate
67.8%

*/

#include <vector>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
      sort(arr.begin(), arr.end());
      int diff = arr[1] - arr[0];
      for (int i = 2; i < arr.size(); ++i) {
        if (arr[i]-arr[i-1] != diff) return false;
      }
      return true;
    }
};

/*

editorial:

get max and min o(N)
diff is max-min/number of elements between
but breaks if duplicates
- extra check for dupes
- check each item - min % diff == 0
*/