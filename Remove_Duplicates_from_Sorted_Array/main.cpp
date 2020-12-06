#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        int front , end;

        front = end = nums[0];
        for(size_t i = 1; i < nums.size(); ++i) {
          if(end == num[i])
            end = i;
          else {
            if(end > front)
              nums.erase(nums.begin() + front + 1, nums.begin() + end)
            front = end;
          }
        }
        for(size_t n : nums)
          cout << n << " ";
    }
};

int main() {
  vector<int> v = {0,0,1,1,1,2,2,3,3,4};
  Solution::removeDuplicates(v);
  return 0;
}
