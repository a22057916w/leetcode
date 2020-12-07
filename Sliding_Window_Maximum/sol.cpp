#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brutal force, time limit exceeded
/*class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> ans;

      int maxn = -1E9, pos = 0, curr = 0;
      for(int i = 0; i < nums.size(); i++) {
          if(i == nums.size() - k) {
            for(int j = i; j < nums.size(); j++) {
              if(pos < i)
                maxn = -1E9;
              if(maxn < nums[j]) {
                    maxn = nums[j];
                    pos = j;
                }
            }
            ans.push_back(maxn);
            break;
          }
          else if(i == 0) {
            for(int j = 0; j < k; j++)
              if(maxn < nums[j]) {
                maxn = nums[j];
                pos = j;
              }
            curr = k - 1;
            ans.push_back(maxn);
          }
          else {
            if(pos < i) {
                maxn = -1E9;
                curr++;
                for(int j = i; j <= curr; j++)
                    if(maxn < nums[j]) {
                        maxn = nums[j];
                        pos = j;
                    }
            }
            else {
                if(maxn < nums[++curr]) {
                    maxn = nums[curr];
                    pos = curr;
                }
            }
            ans.push_back(maxn);
          }
      }
      return ans;
    }
};*/

// using double-ended-queue as a container for sliding-window
// the deque is a monotone decrease seqeuence. Therefore, the
// front of the deqeu is always the maximun value.
// By using <deque>, we can solving the question in O(n).
class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> maxWindow;

      // initiating the deque for the first sliding-window
      for(int i = 0; i < k && i < nums.size(); i++) {
        while(maxWindow.size() > 0 && nums[maxWindow.back()] <= nums[i])
          maxWindow.pop_back();
        maxWindow.push_back(i);
      }
      vector<int> ans;

      // dealing with the following sliding-windows with deqeu and vector
      for(int i = k; i < nums.size(); i++) {
        ans.push_back(nums[maxWindow.front()]);

        if(maxWindow.size() > 0 && i - maxWindow.front() >= k)
          maxWindow.pop_front();
        while(maxWindow.size() > 0 && nums[maxWindow.back()] <= nums[i])
          maxWindow.pop_back();

        maxWindow.push_back(i);
      }

      ans.push_back(nums[maxWindow.front()]);
      return ans;
    }
};
