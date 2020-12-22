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

        // base case. Don't proceed any further
        if(n == 1)
            return;

        // Keep moving the right pointer one step forward until (n == 1)
        right = right->next;

        // Keep moving left pointer to the right until we reach the proper node
        // from where the reversal is to start.
        if(m > 1)
            left = left->next;

        recAndReverse(right, m - 1, n - 1);

        // In case both the pointers cross each other or become equal, we
        // stop i.e. don't swap data any further. We are done reversing at this
        // point.
        if(left == right || right->next == left)
            stop = true;

        if(!stop) {
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;

            // Move left one step to the right.
            // The right pointer moves one step back via backtracking.
            left = left->next;
        }
    }
};
