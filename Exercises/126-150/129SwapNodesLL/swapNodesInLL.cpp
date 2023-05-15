/*

1721. Swapping Nodes in a Linked List
Medium
3.9K
131
Companies
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
Accepted
220.6K
Submissions
327K
Acceptance Rate
67.5%

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

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
vector<ListNode*> nodes;
public:
    ListNode* swapNodes(ListNode* head, int k) {
      int tk = k-1;
      ListNode* tmp = head;
      while (tmp != nullptr) {
        nodes.push_back(tmp);
        tmp = tmp->next;
      }

      int rk = nodes.size()-tk-1;
      if (tk == rk) return head;

      ListNode* tmpBackN = nodes[rk]->next;
      if (tk > 0) {
        nodes[tk-1]->next = nodes[rk];
      }
      nodes[rk]->next = nodes[tk]->next;
      nodes[tk]->next = tmpBackN;
      nodes[rk-1]->next = nodes[tk];
      return nodes[0];
    }
};