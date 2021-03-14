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
