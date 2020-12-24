class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;

        ListNode *reversedHead = reverse(head);

        return isEqual(head, reversedHead);
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
    
    bool isEqual(ListNode *sh, ListNode *h) {
        ListNode *sc = sh, *c = h;

        while(sc != NULL && c != NULL) {
            if(sc->val != c->val)
                return false;
            sc = sc->next;
            c = c->next;
        }

        return true;
    }
};
