/*

2816. Double a Number Represented as a Linked List
Medium
Topics
Companies
Hint
You are given the head of a non-empty linked list representing a non-negative
integer without leading zeroes.

Return the head of the linked list after doubling it.



Example 1:


Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which
represents the number 189. Hence, the returned linked list represents the number
189 * 2 = 378. Example 2:


Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which
represents the number 999. Hence, the returned linked list reprersents the
number 999 * 2 = 1998.


Constraints:

The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have
leading zeros, except the number 0 itself. Seen this question in a real
interview before? 1/5 Yes No Accepted 51.7K Submissions 98.3K Acceptance Rate
52.6%

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

#include <string>

using namespace std;

class Solution {
  string doubleNumber(const string& numStr) {
    int carry = 0;
    string result;

    for (int i = numStr.size() - 1; i >= 0; i--) {
      int digit = numStr[i] - '0';
      int doubledDigit = (digit * 2 + carry) % 10;
      carry = (digit * 2 + carry) / 10;
      result = std::to_string(doubledDigit) + result;
    }

    if (carry > 0) {
      result = std::to_string(carry) + result;
    }

    return result;
  }

 public:
  ListNode* doubleIt(ListNode* head) {
    string as_s = "";
    ListNode* cpy = head;
    while (cpy != nullptr) {
      as_s += to_string(cpy->val);
      cpy = cpy->next;
    }

    as_s = doubleNumber(as_s);

    ListNode* new_head = nullptr; // if uninitialized they can contain garbage values yo.
    ListNode* cur = nullptr;
    for (char c : as_s) {
      int cur_i = c - '0';
      ListNode* tmp = new ListNode(cur_i);
      if (!cur) {
        cur = tmp;
        new_head = cur;
      } else {
        cur->next = tmp;
        cur = tmp;
      }
    }

    return new_head;
  }
};