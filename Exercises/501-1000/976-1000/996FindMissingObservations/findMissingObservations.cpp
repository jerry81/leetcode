/*

2028. Find Missing Observations
Medium
Topics
Companies
Hint
You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.



Example 1:

Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
Example 2:

Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
Example 3:

Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.


Constraints:

m == rolls.length
1 <= n, m <= 105
1 <= rolls[i], mean <= 6
Seen this question in a real interview before?
1/5
Yes
No
Accepted
47.5K
Submissions
93.5K
Acceptance Rate
50.8%

*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
      int sz = rolls.size();
      int m_plus_n = sz + n;
      int x = m_plus_n*mean;
      int sm = 0;
      for (int i: rolls) sm+=i;
      int tgt = x-sm;
      vector<int> res = {};
      for (int i = 0; i < n-1; ++i) {
        int rm = n-i;
        int cur_avg = tgt/rm;
        if (cur_avg > 6) return {};
        if (cur_avg < 1) return {};
        res.push_back(cur_avg);
        tgt-=cur_avg;
      }
      if (tgt > 6 || tgt < 0) return {};
      res.push_back(tgt);
      return res;
    }
};

 /*
    find what fraction is missing
    rolls = [3,2,4,3], mean = 4, n = 2
    m+n = rolls.size() + n = 6
    x / 6 = 4
    x = 24
    x-sum(rolls) = 12
    fit 12 in 2 items
    // can just do 1,1,1, ... x-j
 */