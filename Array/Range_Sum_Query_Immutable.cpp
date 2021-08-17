/*
Reference:
https://www.geeksforgeeks.org/range-sum-queries-without-updates/
*/

// https://leetcode.com/problems/range-sum-query-immutable/

#include <vector>
using std::vector;

class NumArray {
public:
    NumArray(vector<int>& nums) {
      pre.resize(nums.size(), 0);

      pre[0] = nums[0];
      for(int i = 1; i < nums.size(); i++)
        pre[i] = nums[i] + pre[i - 1];
    }

    int sumRange(int left, int right) {
      if(left == 0)
        return pre[right];
      else
        return pre[right] - pre[left - 1];
    }

private:
    vector<int> pre;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
