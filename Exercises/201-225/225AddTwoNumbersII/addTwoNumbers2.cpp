/*

445. Add Two Numbers II
Medium
4.9K
253
Companies
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.



Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading
zeros.


Follow up: Could you solve it without reversing the input lists?

Accepted
391K
Submissions
649.6K
Acceptance Rate
60.2%

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // make vectors
    vector<int> v1;
    vector<int> v2;
    while (l1 != nullptr) {
      v1.push_back(l1->val);
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      v2.push_back(l2->val);
      l2 = l2->next;
    }
    // iterate on vectors
    int offset = 0;
    int s1 = v1.size() - 1;
    int s2 = v2.size() - 1;
    int ptr1 = s1;
    int ptr2 = s2;
    ListNode* cur;
    bool carry = false;
    while (ptr1 >= 0 && ptr2 >= 0) {
      int sum;
      int addend1;
      int addend2;
      if (ptr1 < 0) {
        addend1 = 0;
      } else {
        addend1 = v1[ptr1];
      }

      if (ptr2 < 0) {
        addend2 = 0;
      } else {
        addend2 = v2[ptr2];
      }

      sum = addend1 + addend2 + (int)carry;
      if (sum > 9) {
        sum -= 10;
        carry = true;
      } else {
        carry = false;
      }
      cur->val = sum;

      ListNode* next;
      next->next = cur;
      cur = next;
    }
    return cur->next;
  }
};