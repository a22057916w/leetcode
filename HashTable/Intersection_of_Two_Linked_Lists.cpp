// LeetCode : https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> table;

        ListNode* curr = headA;
        while(curr) {
            table[curr] = curr->val;
            curr = curr->next;
        }

        curr = headB;
        while(curr) {
            if(table.count(curr))
                return curr;
            curr = curr->next;
        }

        return NULL;
    }
};