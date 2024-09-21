/*


386. Lexicographical Numbers
Medium
Topics
Companies
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.



Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]


Constraints:

1 <= n <= 5 * 104

Seen this question in a real interview before?
1/5
Yes
No
Accepted
140.1K
Submissions
212.2K
Acceptance Rate
66.0%

*/

#include <vector>

using namespace std;
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, res);
        }
        return res;
    }

    void dfs(int cur, int n, vector<int>& res) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; ++i) {
            if (10 * cur + i > n) return;
            dfs(10 * cur + i, n, res);
        }
    }
};
