class Solution {
private:
    bool stop;
    ListNode *left;
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        left = head;
        stop = false;
        recAndReverse(head, m, n);
        return head;
    }

    void recAndReverse(ListNode *right, int m, int n) {
        if(n == 1)
            return;

        right = right->next;

        if(m > 1)
            left = left->next;

        recAndReverse(right, m - 1, n - 1);

        if(left == right || right->next == left)
            stop = true;

        if(!stop) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
            left = left->next;
        }
    }
};
