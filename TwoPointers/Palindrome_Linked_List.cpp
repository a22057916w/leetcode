// The idea is find the middle of the list, then reverse
// the rear part of the list.
// For example, 1->2->2->1->NULL, the alogrithm goes
//              f
// 1->2->2->1->NULL
//       s
// where the iteration ends.
// Then we move f to the head like 1->2->2->NULL and reverse s to 1->2->NULL,
// and compare the two list until s goes to NULL

class Solution {
public:
    bool isPalindrome(ListNode* head) {
      ListNode *fast, *slow;
      fast = slow = head;

      // Move the two pointers until they reach the proper positions
      // in the list.
      while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
      }

      // compare the fast part(front end) and slow part(reversed rear end)
      fast = head;
      slow = reverse(slow);

      return isEqual(fast, slow);
    }

    ListNode *reverse(ListNode *head) {
      ListNode *prev = NULL;
      ListNode *curr = head;

      while(curr != NULL) {
        ListNode *nextTmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTmp;
      }

      return prev;
    }

    bool isEqual(ListNode *fast, ListNode *slow) {
      while(slow != NULL) {
        if(fast->val != slow->val)
          return false;
        fast = fast->next;
        slow = slow->next;
      }

      return true;
    }
};
