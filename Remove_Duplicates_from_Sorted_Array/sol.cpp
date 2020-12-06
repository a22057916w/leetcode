#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int pos, target;
      int cnt = 0;

      pos = 1;
      target = nums[0];
      for(size_t i = 1; i < nums.size(); ++i) {
        if(target != nums[i]){
          target = nums[i];
          nums.erase(nums.begin() + pos, nums.begin() + i);
          cnt++;
          i = ++pos;
        }
      }

      return cnt;
    }
};
