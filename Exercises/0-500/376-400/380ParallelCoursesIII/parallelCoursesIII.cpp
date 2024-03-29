/*

2050. Parallel Courses III
Hard
778
24
Companies
You are given an integer n, which indicates that there are n courses labeled
from 1 to n. You are also given a 2D integer array relations where relations[j]
= [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed
before course nextCoursej (prerequisite relationship). Furthermore, you are
given a 0-indexed integer array time where time[i] denotes how many months it
takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses
following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every
course (i.e., the graph is a directed acyclic graph).



Example 1:


Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required
to complete each course. We start course 1 and course 2 simultaneously at month
0. Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time
required is 3 + 5 = 8 months. Example 2:


Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
Output: 12
Explanation: The figure above represents the given graph and the time required
to complete each course. You can start courses 1, 2, and 3 at month 0. You can
complete them after 1, 2, and 3 months respectively. Course 4 can be taken only
after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 =
7 months. Course 5 can be taken only after courses 1, 2, 3, and 4 have been
completed, i.e., after max(1,2,3,7) = 7 months. Thus, the minimum time needed to
complete all the courses is 7 + 5 = 12 months.


Constraints:

1 <= n <= 5 * 104
0 <= relations.length <= min(n * (n - 1) / 2, 5 * 104)
relations[j].length == 2
1 <= prevCoursej, nextCoursej <= n
prevCoursej != nextCoursej
All the pairs [prevCoursej, nextCoursej] are unique.
time.length == n
1 <= time[i] <= 104
The given graph is a directed acyclic graph.
Accepted
23.3K
Submissions
38.3K
Acceptance Rate
60.7%

*/

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  struct Node {
    int tidx = -1;
    int indegree = 0;
    vector<int> neighbors;
    int accum = 0;
    Node(int accum, int tidx) : accum(accum), tidx(tidx) {}
  };

  unordered_map<int, Node*> nodes;

 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    if (time.size() == 1) return time[0];

    if (relations.empty()) return *max_element(time.begin(), time.end());

    int counter = 1;

    for (int t : time) {
      nodes[counter] = new Node(t, counter - 1);

      counter++;
    }
    // make indegrees list
    for (vector<int> v : relations) {
      int depended = v[0];
      int dependent = v[1];
      nodes[dependent]->indegree++;
      nodes[depended]->neighbors.push_back(dependent);
    }

    queue<int> nn;

    int res = 0;
    for (auto [idx, node] : nodes) {
      if (node->indegree == 0) nn.push(idx);
      res = max(res, node->accum);
    }

    while (!nn.empty()) {
      int fi = nn.front();
      nn.pop();
      Node* f = nodes[fi];
      for (int neigh : f->neighbors) {
        Node* cur = nodes[neigh];
        int newIn = cur->indegree - 1;
        cur->indegree = newIn;
        int neighT = time[cur->tidx];
        int newAccum = max(neighT + f->accum, cur->accum);
        res = max(res, newAccum);
        cur->accum = newAccum;
        nodes[neigh] = cur;
        if (newIn == 0) nn.push(neigh);
      }
    }
    return res;
    // or outdegree/indegrees?
    // times zero indexed
    // labels 1 indexed
  }
};

/*

[[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]

           4  < - -
           |      |
           v      |
1    - >   5  < - 3
           ^
2    -  -  |

do 1,2 3 first
1+5
2+5
3+5 <-- not going to be as big as 4->5
3+4

5+ max indegrees
do 4 next

indegrees:

1 - 0, 2 - 0, 3 - 0, 4 - 1, 5 - 4

1,2,3
- 5 -> 9
- 4 -> 7
- indegree 0
4
- 5 -> 12
*/