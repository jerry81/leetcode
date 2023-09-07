/*

92. Reverse Linked List II
Medium
9.9K
449
Companies
Given the head of a singly linked list and two integers left and right where
left <= right, reverse the nodes of the list from position left to position
right, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]


Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n


Follow up: Could you do it in one pass?
Accepted
684K
Submissions
1.5M
Acceptance Rate
45.8%

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
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    /*
      my guess:  put them into array
      then left-1's next becomes right
      from right to left+1, next becomes cur-1
      left's next becomes right+1
    */
   if (head == nullptr) return nullptr;

    vector<ListNode*> nodes;
    ListNode* tmp = head;
    while (tmp != nullptr) {
      nodes.push_back(tmp);
      tmp = tmp->next;
    }
    int lidx = left-1;
    int ridx = right-1;
    ListNode* ret = nodes[0];
    if (lidx > 0) {
      nodes[lidx-1] -> next = nodes[ridx];
    } else {
      ret = nodes[ridx];
    }
    for (int i = ridx; i > lidx; --i) {
      nodes[i] -> next = nodes[i-1];
    }
    ListNode* finalItem =  (right < nodes.size()) ? nodes[right] : nullptr;
    nodes[lidx] -> next = finalItem;

    return ret;
  }
};