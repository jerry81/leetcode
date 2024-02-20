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

#include <unordered_map>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
unordered_map<int, ListNode*> nodes;
int size;
public:
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode* tmp = head;
      int counter = 1;
      while (tmp != nullptr) {
        ListNode* cpy = new ListNode(tmp->val, tmp->next);
        nodes[counter] = cpy;
        counter++;
        tmp = tmp->next;
      }

      int rk = counter - k;
      if (k == rk) return head;

      ListNode* back = new ListNode(nodes[rk]->val, nodes[rk]->next);

      ListNode* front = new ListNode(nodes[k]->val, nodes[k]->next);
      back->next = front->next;
      front->next = nodes[rk]->next;
      if (k > 0) {
        nodes[k-1]->next = back;

      }
      nodes[rk-1]->next = front;

      return nodes[1];
    }
};