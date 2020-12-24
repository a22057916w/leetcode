class Solution {
public:
    bool isPalindrome(ListNode* head) {
      ListNode *fast, *slow;
      fast = slow = head;

      while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
      }

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
