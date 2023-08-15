/*

86. Partition List
Medium
5.8K
663
Companies
Given the head of a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two
partitions.



Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]


Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
Accepted
476.2K
Submissions
900.3K
Acceptance Rate
52.9%

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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* before = nullptr;
    ListNode* beforehead = nullptr;
    ListNode* after = nullptr;
    ListNode* afterhead = nullptr;
    ListNode* target = nullptr;
    ListNode* tgthead = nullptr;
    while (head != nullptr) {
      int curval = head->val;
      if (curval == x) {
        if (target == nullptr) {
          target = new ListNode(x);
          tgthead = target;
        } else {
          ListNode* newLN = new ListNode(x);
          target->next = newLN;
          target = target->next;
        }
      } else if (curval < x) {
        if (before == nullptr) {
          before = new ListNode(curval);
          beforehead = before;
        } else {
          ListNode* newLN = new ListNode(curval);
          before->next = newLN;
          before = before->next;
        }
      } else {
        if (after == nullptr) {
          after = new ListNode(curval);
          afterhead = after;
        } else {
          ListNode* newLN = new ListNode(curval);
          after->next = newLN;
          after = after->next;
        }
      }
      head = head->next;
    }
    // connect the peices
    before->next = tgthead;
    target->next = afterhead;
    return beforehead;
  }
};

/*

iterate once
three nodes (before, after, and target)

*/