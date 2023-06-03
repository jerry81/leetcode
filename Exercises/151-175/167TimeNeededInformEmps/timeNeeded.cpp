/*

1376. Time Needed to Inform All Employees
Medium
2.8K
185
Companies
A company has n employees with a unique ID for each employee from 0 to n - 1.
The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i]
is the direct manager of the i-th employee, manager[headID] = -1. Also, it is
guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent
piece of news. He will inform his direct subordinates, and they will inform
their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct
subordinates (i.e., After informTime[i] minutes, all his direct subordinates can
start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent
news.



Example 1:

Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.
Example 2:


Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all
the employees in the company and needs 1 minute to inform them all. The tree
structure of the employees in the company is shown.


Constraints:

1 <= n <= 105
0 <= headID < n
manager.length == n
0 <= manager[i] < n
manager[headID] == -1
informTime.length == n
0 <= informTime[i] <= 1000
informTime[i] == 0 if employee i has no subordinates.
It is guaranteed that all the employees can be informed.
Accepted
138.6K
Submissions
236K
Acceptance Rate
58.7%

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> subordinates;

  void buildSubordinates(vector<int>& manager) {
    for (int i = 0; i < manager.size(); ++i) {
      int imanager = manager[i];
      if (imanager == -1) continue;

      subordinates[imanager].push_back(i);
    }
  }

  int bfs(vector<int>& informTime, int head, int sz) {
    int res = 0;
    vector<bool> visited(sz, false);
    queue<pair<int, int>> nn;
    nn.push({head, 0});
    visited[head] = true;
    while (!nn.empty()) {
      auto cur = nn.front();
      nn.pop();
      int emp = cur.first;
      cerr << "emp is " << emp << endl;
      int curHeight = informTime[emp] + cur.second;
      cerr << "height is " << curHeight << endl;
      if (curHeight > res) res = curHeight;

      if (subordinates[emp].empty()) continue;

      for (int i : subordinates[emp]) {
        if (!visited[i]) {
          visited[i] = true;
          nn.push({i, curHeight});
        }
      }
    }
    return res;
  }

 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    subordinates.resize(n, vector<int>(0));
    buildSubordinates(manager);
    return bfs(informTime, headID, n);
  }
};

int main() {
  Solution s;
  vector<int> mgr1 = {3, 3, -1, 2};
  vector<int> inf1 = {0, 0, 162, 914};
  int res = s.numOfMinutes(4, 2, mgr1, inf1);
  cout << "expect something " << res << endl;
  vector<int> mgr2 = {-1};
  vector<int> inf2 = {0};
  int res2 = s.numOfMinutes(1, 0, mgr2, inf2);
  cout << "expect something " << res2 << endl;
  vector<int> mgr3 = {2, 2, -1, 2, 2, 2};
  vector<int> inf3 = {0, 0, 1, 0, 0, 0};
  int res3 = s.numOfMinutes(6, 2, mgr3, inf3);
  cout << "expect something " << res3 << endl;
}

/*

build neighbors

start with headID

bfs traverse

// fix - all "informs" should happen in parallel.
// so this becomes a height counting problem.
// not all heights are created equal - we are looking for the max height

*/