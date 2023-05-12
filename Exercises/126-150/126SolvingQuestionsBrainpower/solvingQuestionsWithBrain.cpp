/*

2140. Solving Questions With Brainpower
Medium
1.1K
28
Companies
You are given a 0-indexed 2D integer array questions where questions[i] =
[pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the
questions in order (i.e., starting from question 0) and make a decision whether
to solve or skip each question. Solving question i will earn you pointsi points
but you will be unable to solve each of the next brainpoweri questions. If you
skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve
questions 1 and 2. If instead, question 0 is skipped and question 1 is solved,
you will earn 4 points but you will be unable to solve questions 2 and 3. Return
the maximum points you can earn for the exam.



Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.


Constraints:

1 <= questions.length <= 105
questions[i].length == 2
1 <= pointsi, brainpoweri <= 105
Accepted
37.3K
Submissions
73.8K
Acceptance Rate
50.6%

*/

#include <vector>

using namespace std;

class Solution {
  vector<int> dp;
  vector<vector<int>> q;
  int sz;
  long long mostPointsR(int idx) {
    if (idx >= sz) return 0;
    if (dp[idx] > -1) return dp[idx];

    long long max = 0;
    vector<int> pr = q[idx];
    int pts = pr[0];
    int next = idx + pr[1] + 1;
    long long tmp = (next >= sz) ? pts : pts + mostPointsR(next);
    if (tmp > max) max = tmp;

    tmp = mostPointsR(idx+1);

    if (tmp > max) max = tmp;


    dp[idx] = max;
    return max;
  }

 public:
  long long mostPoints(vector<vector<int>>& questions) {
    q = questions;
    sz = q.size();
    vector<int> lu(sz, -1);
    dp = lu;
    return mostPointsR(0);
  }
};

/*

similar to knapsack

try all possibilities?

wrong answer for this

questions =
[[62,62],[1,84],[44,43],[15,95],[18,35],[9,45],[7,98],[64,78],[77,31],[39,93],[19,8],[90,82],[69,87],[27,30],[44,97],[22,95],[97,97],[50,52],[93,72],[26,37],[52,34],[26,21],[66,67],[97,41],[27,86],[31,46],[10,31],[30,45],[98,57],[5,67],[33,42],[79,87],[27,88],[33,22],[94,45],[2,29],[87,98],[70,31],[54,53],[90,82],[85,52],[8,17],[7,36],[67,81],[67,60],[14,54],[93,4],[75,50],[31,13],[39,3],[69,71],[63,36],[65,86],[97,38],[1,3],[50,2],[26,10],[97,16],[34,12],[43,59],[19,60],[27,82],[56,79],[57,30],[77,45],[67,78],[44,84],[45,72],[88,79],[16,23],[95,48],[40,63],[68,72],[45,27],[81,80],[62,26],[23,82],[74,89],[67,87],[58,25],[65,84],[51,89],[96,100],[77,95],[93,86],[21,76],[40,94],[47,60]]


TLE on case 48


*/