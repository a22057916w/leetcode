#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        int pos, target;

        pos = 1;
        target = nums[0];
        for(size_t i = 1; i < nums.size(); ++i) {
          if(target != nums[i]){
            target = nums[i];
            nums.erase(nums.begin() + pos, nums.begin() + i);
            i = ++pos;
          }
        }
        for(size_t n : nums)
          cout << n << " ";
    }
};

int main() {
  vector<int> v = {1,1,2};
  Solution::removeDuplicates(v);
  return 0;
}
