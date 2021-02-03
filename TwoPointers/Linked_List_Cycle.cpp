/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

      if(head == NULL || head->next == NULL)
        return false;

      ListNode *slow = head->next, *fast = head->next->next;

      // if there are a circle, fast would catch slow
      while(fast && fast->next) {
        if(fast == slow)
          return true;
        slow = slow->next;
        fast = fast->next->next;
      }

      return false;
    }
};
