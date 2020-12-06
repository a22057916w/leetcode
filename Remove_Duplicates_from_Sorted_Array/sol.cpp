#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size() == 0)
        return 0;

      // pos is the mark of the starting position when the vector rearrangents itself.
      // target for tracking tht current value of nums[i]
      int pos = 0, target = nums[0];
      for(size_t i = 0; i < nums.size(); ++i) {
        if(target != nums[i]){
          target = nums[i];
          nums.erase(nums.begin() + pos, nums.begin() + i - 1);
          i = ++pos;    // after the elimination taking place, the starting position must reset and move forward
        }
        else if(i - pos > 0 && i == nums.size() - 1)    // for elimination like [1,1,1] or [0,1,1,1,1]
          nums.erase(nums.begin() + pos, nums.begin() + i);
        else
          continue;
      }

      return nums.size();
    }
};
