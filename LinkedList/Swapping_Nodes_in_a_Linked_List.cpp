// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

#include <algorithm>
#include <vector>
using namespace std;


// transfer linked list to array, then swap the targets
class Solution1 {
public:
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode *curr = head;
      vector<int> temp;

      // making up vector
      while(curr) {
        temp.push_back(curr->val);
        curr = curr->next;
      }

      swap(temp[k - 1], temp[temp.size() - k]);

      // setting the end condition for loop, "k - 1" might be greater than "temp.size()) - k"
      int n = max(k - 1, (int)(temp.size()) - k);
      curr = head;

      // assign vector elements to node values until reach index n
      for(int i = 0; i <= n; i++) {
        curr->val = temp[i];
        curr = curr->next;
      }

      return head;
    }
};


// two pointers, one pass
class Solution2 {
public:
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode *ptr1 = head, *ptr2 = head, *kth;

      // find the first pos to be swaped
      while(--k)
        ptr1 = ptr1->next;

      kth = ptr1;
      ptr1 = ptr1->next;

      // when ptr1 reach the end of the list, the gap between ptr1 and ptr2 is
      // exactly k - 1, and ptr2 would be the second pos to be swaped
      while(ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
      }
      swap(kth->val, ptr2->val);

      return head;
    }
};
