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
class Solution1 {
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


class Solution2 {
private:
    bool stop;
    ListNode *left;
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
            return NULL;

        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode *curr = head, *prev = NULL;
        while(m > 1) {
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }

        // The two pointers that will fix the final connections.
        ListNode *con = prev, *tail = curr;

        // Iteratively reverse the nodes until n becomes 0.
        while(n > 0) {
            ListNode *nextTmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTmp;
            n--;
        }

        // Adjust the final connections. If con == NULL means the starting point
        // is at the beginning, which is head.
        if(con != NULL)
            con->next = prev;
        else
            head = prev;

        tail->next = curr;
        return head;
    }
};
