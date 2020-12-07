#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> ans;

      int maxn = -1E9, pos = 0, curr = 0;
      for(int i = 0; i < nums.size(); i++) {
        if(i == nums.size() - k) {
          for(int j = i; j < nums.size(); j++) {
            if(pos < i)
              maxn = -1E9;
              maxn = max(maxn, nums[j]);
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
          ans.push_back(maxn);
          curr = k - 1;
        }
        else {
          if(pos < i)
              maxn = -1E9;
          if(maxn < nums[++curr]) {
              maxn = nums[curr];
              pos = curr;
            }
          ans.push_back(maxn);
        }
      }
      return ans;
    }
};
