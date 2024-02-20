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
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* cur = head;
        ListNode* kthNode = nullptr;
        ListNode* endNode = nullptr;

        // Traverse the linked list to find the kth and end nodes
        while (cur != nullptr) {
            length++;
            if (length == k)
                kthNode = cur;
            cur = cur->next;
        }

        endNode = head;

        // Traverse from the beginning again to find the end node
        for (int i = 0; i < length - k; i++)
            endNode = endNode->next;

        // Swap the values of the kth and end nodes
        int temp = kthNode->val;
        kthNode->val = endNode->val;
        endNode->val = temp;

        return head;
    }
};