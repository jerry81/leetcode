/*

1669. Merge In Between Linked Lists
Medium
Topics
Companies
Hint
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their
place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.



Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their
place. The blue edges and nodes in the above figure indicate the result. Example
2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 =
[1000000,1000001,1000002,1000003,1000004] Output:
[0,1,1000000,1000001,1000002,1000003,1000004,6] Explanation: The blue edges and
nodes in the above figure indicate the result.


Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104
Seen this question in a real interview before?
1/4
Yes
No
Accepted
96.9K
Submissions
131.1K
Acceptance Rate
73.9%

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
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    /* first clone the list */
    ListNode *cur = list1;
    ListNode *ret = cur;
    ListNode *cpyhead = new ListNode(list1->val);
    ListNode *cpy = cpyhead;
    ListNode *cpyptr = list1;
    while (cpyptr != nullptr) {
      ListNode *next = new ListNode(cpyptr->val);
      cpy->next = next;
      cpy = cpy->next;
      cpyptr = cpyptr->next;
    }

    /* keep track of "index"*/
    int cnt = 1;
    while (cnt < a) {
      cnt++;
      cur = cur->next;
      cpyhead = cpyhead->next;
    }
    cur->next = list2;
    cur = cur->next;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    while (cnt <= b) {
      cpyhead = cpyhead->next;
      cnt++;
    }
    if (cpyhead->next) cpyhead = cpyhead->next;
    cur->next = cpyhead->next;
    return ret;
  }
};