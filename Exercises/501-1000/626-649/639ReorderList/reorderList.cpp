/*

143. Reorder List
Medium
Topics
Companies
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]


Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
Seen this question in a real interview before?
1/4
Yes
No
Accepted
860.8K
Submissions
1.5M
Acceptance Rate
56.5%

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
public:
    void reorderList(ListNode* head) {
      // map the nodes to index
      // then splice and merge
      unordered_map<int, ListNode*> nodes;
      int sz = 0;
      while (head) {
        nodes[sz] = head;
        auto nxt = head->next;
        head->next = nullptr;
        head = nxt;
        sz+=1;
      }
      int ptr1 = 0;
      int ptr2 = sz-1;
      ListNode* cur = nodes[0];
      while (ptr1 <= ptr2) {
        cur->next = nodes[ptr1];
        cur = cur->next;
        if (ptr1 == ptr2) break;
        cur->next = nodes[ptr2];
        cur = cur->next;

        ptr1++;
        ptr2--;
      }
    }
};