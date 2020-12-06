#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size() == 0)
        return 0;

      int pos = 0, target = nums[0];
      for(size_t i = 0; i < nums.size(); ++i) {
        if(target != nums[i]){
          target = nums[i];
          nums.erase(nums.begin() + pos, nums.begin() + i - 1);
          i = ++pos;
        }
        else if(i - pos > 0 && i == nums.size() - 1)
          nums.erase(nums.begin() + pos, nums.begin() + i);
        else
          continue;
      }

      return nums.size();
    }
};
