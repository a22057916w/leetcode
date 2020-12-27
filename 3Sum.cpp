#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
          unordered_map<int,int> cache;

          for(int j = i + 1; j < nums.size(); j++) {
            int needed_num = (0 - nums[i]) - nums[j];

            if(cache.find(nums[j]) != cache.end()) {
              vector<int> tmp;

              tmp.push_back(nums[i]);
              tmp.push_back(cache[nums[j]]);
              tmp.push_back(nums[j]);

              ans.push_back(tmp);
              break;
            }
            else
              cache.insert(make_pair(needed_num, nums[j]));
          }
        }

        return ans;
    }
};
