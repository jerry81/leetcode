/*

1171. Remove Zero Sum Consecutive Nodes from Linked List
Medium
Topics
Companies
Hint
Given the head of a linked list, we repeatedly delete consecutive sequences of
nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any
such answer.



(Note that in the examples below, all sequences are serializations of ListNode
objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]


Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
58.2K
Submissions
130.7K
Acceptance Rate
44.5%

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
 */

#include <vector>

// try brute force first

using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    // simplicity, let's make an array?
    vector<int> vals;
    ListNode* clone = head;
    while (clone) {
      vals.push_back(clone->val);
      clone = clone->next;
    }

    vector<int> resv;
    for (int i=0; i < vals.size(); ++i) {
      int cur = vals[i];
      int sum = cur;
      bool found = false;
      for (int j = resv.size()-1; j >=0; --j) {
        sum+= resv[j];
        if (sum == 0) {
          // delete from j to end
          resv = vector<int>(resv.begin(), resv.begin()+j);
          found = true;
        }
        if (found) break;
      }
      if (!found) resv.push_back(cur);
    }
    ListNode* res = new ListNode(resv[0]);
    ListNode* cur = res;
    for (int i = 1; i < resv.size(); ++i) {
      ListNode* nxt = new ListNode(resv[i]);
      cur->next = nxt;
      cur = nxt;
    }
    return res;
  }
};