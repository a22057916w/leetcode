#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

// !!! brutal force, time limit exceeded !!!

// using double-ended-queue as a container for sliding-window
// the deque we implement is a monotone decrease seqeuence. Therefore, the
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

        // push the maxinum in each intervak
        ans.push_back(nums[maxWindow.front()]);

        // moving one step forward then find new maximun in current interval
        if(maxWindow.size() > 0 && i - maxWindow.front() >= k)
          maxWindow.pop_front();
        while(maxWindow.size() > 0 && nums[maxWindow.back()] <= nums[i])
          maxWindow.pop_back();

        // push the index of the forward number(nums[i])
        maxWindow.push_back(i);
      }

      ans.push_back(nums[maxWindow.front()]);
      return ans;
    }
};
