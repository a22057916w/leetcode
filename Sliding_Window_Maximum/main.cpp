#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

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

int main() {
  vector<int> v = {9,10,9,-7,-4,-8,2,-6};
  int k = 5;
  vector<int> ans = Solution::maxSlidingWindow(v, k);
  for(auto n : v)
    cout << n << " ";
  cout << endl;
  for(auto n : ans)
    cout << n << " ";
  return 0;
}
