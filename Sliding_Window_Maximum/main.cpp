#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> ans;

      int maxn = 0, pos = 0;
      for(int i = 0; i < nums.size(); i++) {
          if(i == 0) {
            for(int j = 0; j < k; j++)
              maxn = max(maxn, nums[j]);
            ans.push_back(maxn);
            pos = k - 1;
          }
          else if(i < nums.size - k) {
            maxn = maxn(maxn, nums[pos++])
            ans.push_back(maxn);
          }
          else {
            for(int j = i; j < nums.size(); j++)
              maxn = max(maxn, nums[j]);
            ans.push_back(maxn);
          }
      }
      for(auto n : nums)
        cout << n << " ";
      return ans;
    }
};

int main() {
  vector<int> v = {1,3,-1,-3,5,3,6,7};
  int k = 3;

  return 0;
}
