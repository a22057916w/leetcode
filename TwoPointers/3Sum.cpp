// The idea is fix one number, and We can't use <unordered_map> for there cannot
// contain duplicate answers. To sloved the problem, we sort the list then use
// two-pointers method, by converging from two end, and check the dulicaption
// simultaneously.

#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // check if the list is legal, that is at least have 3 numbers
        if(nums.size() < 3)
          return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++) {

          // if the fixed number > 0, there are no answers for the other two
          // pointers
          if(nums[i] > 0) break;

          // if the fixed numbers is equal to the previous, pass the duplication
          if(i > 0 && nums[i] == nums[i - 1]) continue;

          // j for left(front), k for right(rear);
          int target = 0 - nums[i], j = i + 1, k = nums.size() - 1;
          while(j < k) {

            // if the sum equals target, move j and k;
            // if the sum less than target, move j;
            // if greater, move k.
            if(nums[j] + nums[k] == target) {
              res.push_back({nums[i], nums[j], nums[k]});

              // check the duplication
              while(j < k && nums[j] == nums[j + 1]) j++;
              while(j < k && nums[k] == nums[k - 1]) k--;

              // move one step respectively
              j++; k--;
            }
            else if(nums[j] + nums[k] < target)
              j++;
            else
              k--;
          }
        }
        return res;
    }
};
