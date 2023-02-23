/*

502. IPO
Hard
1.2K
102
Companies
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.



Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6


Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109
Accepted
45.9K
Submissions
99.5K
Acceptance Rate
46.1%

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
vector<int> getIndexesOfCandidates(vector<int> capital, int limit) {
  vector<int> returned;
  for (int i = 0; i < capital.size(); ++i) {
    int cur = capital[i];
    if (cur <= limit) {
      returned.push_back(i);
    }
  }
  return returned;
}

struct Project {
  int capital = 0;
  int profit = 0;
  void Print() {
    cerr << "profit is " << profit << endl;
    cerr << "capital is " << capital << endl;
  }
};

struct MaxMarginResult {
  int index=0;
  int value=0;
};

MaxMarginResult getMaxMargin(vector<int> profits, vector<int> indexes) {
  int maxv = 0;
  int maxi = 0;
  for (int idx:indexes) {
    int net = profits[idx];
    if (net > maxv) {
      maxv = net;
      maxi = idx;
    }
  }
  MaxMarginResult mmr;
  mmr.index = maxi;
  mmr.value = maxv;
  return mmr;
}

static bool compareProjects(Project a, Project b) {
  return a.profit > b.profit;
}

vector<Project> buildAndSort(vector<int> profits, vector<int> capitals) {
  vector<Project> ret;
  for (int i = 0; i < profits.size(); ++i) {
    Project p;
    p.profit = profits[i];
    p.capital = capitals[i];
    ret.push_back(p);
  }
  sort(ret.begin(), ret.end(), compareProjects);
  return ret;
}

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      vector<Project> projects = buildAndSort(profits, capital);

      int totalCap = w;
      for (int i=0; i < k; ++i) {
        if (projects.size() == 0) break;

        for (int j=0; j < projects.size(); ++j) {
          if (projects[j].capital <= totalCap) {
            totalCap += projects[j].profit;
            projects.erase(projects.begin()+j);
            break;
          }
        }
      }
      return totalCap;
    }
};

int main () {
  Solution s;
  vector<int> test1a = {1,2,3};
  vector<int> test1b = {0,1,1};
  cerr << "expect 4 " << s.findMaximizedCapital(2,0,test1a, test1b) << endl;
  vector<int> failtest1 = {1,2,3};
  vector<int> failtest1b = {0,1,2};
  cerr << "expect 6 " << s.findMaximizedCapital(10,0,failtest1,failtest1b);
  return 0;
};

/*

optimization problem
- feels like recursion + memoization?
- loop k times
- available projects first (capital < project capital)
- try greedy first?  take the highest net profit that is available

- timeout on huge list

- sort by profit first

*/