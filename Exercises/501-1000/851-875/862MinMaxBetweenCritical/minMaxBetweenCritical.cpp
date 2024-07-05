/*

2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Medium
Topics
Companies
Hint
A critical point in a linked list is defined as either a local maxima or a local
minima.

A node is a local maxima if the current node has a value strictly greater than
the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than
the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a
previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance,
maxDistance] where minDistance is the minimum distance between any two distinct
critical points and maxDistance is the maximum distance between any two distinct
critical points. If there are fewer than two critical points, return [-1, -1].



Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3
and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2
and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5
and 2. The minimum distance is between the fifth and the sixth node. minDistance
= 6 - 5 = 1. The maximum distance is between the third and the sixth node.
maxDistance = 6 - 3 = 3. Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater
than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater
than 2 and 2. Both the minimum and maximum distances are between the second and
the fifth node. Thus, minDistance and maxDistance is 5 - 2 = 3. Note that the
last node is not considered a local maxima because it does not have a next node.


Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
64.1K
Submissions
100K
Acceptance Rate
64.1%
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 **/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    // drop critical points into a vector
    vector<int> as_v;
    while (head != nullptr) {
      as_v.push_back(head->val);
      head = head->next;
    }
    // find critical idxes
    int sz = as_v.size();
    vector<int> cidxs;
    for (int i = 1; i < sz - 1; ++i) {
      int prev = as_v[i - 1];
      int nxt = as_v[i + 1];
      int cur = as_v[i];
      if ((prev < cur && nxt < cur) || (prev > cur && nxt > cur)) {
       cidxs.push_back(i);
      }
    }
    int mnDist = INT_MAX;
    vector<int> res = {-1,-1};
    if (cidxs.size() < 2) return {-1,-1};
    res[1] = as_v.back() - as_v.front();
    for (int i = 0; i < sz-1; ++i) {
      int cur = as_v[i];
      int nxt = as_v[i+1];
      mnDist = min(mnDist, nxt-cur);
    }
    return res;
  }
};