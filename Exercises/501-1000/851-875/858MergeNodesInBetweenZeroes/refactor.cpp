
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// nice, the refactor removes the intermediate vector

class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    ListNode* itr = head->next;  // Start from the first node after the initial 0
    int cursum = 0;

    while (itr != nullptr) {
      if (itr->val == 0) {
        cur->next = new ListNode(cursum);
        cur = cur->next;
        cursum = 0;
      } else {
        cursum += itr->val;
      }
      itr = itr->next;
    }

    return dummy->next;
  }
};