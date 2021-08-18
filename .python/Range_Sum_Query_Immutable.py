# https://leetcode.com/problems/range-sum-query-immutable/

class NumArray(object):
    def __init__(self, nums):
        arr = [0] * len(nums)

        arr[0] = nums[0];
        for i in range(1, len(nums)):
          arr[i] = nums[i] + arr[i - 1]

        self.pre = arr

    def sumRange(self, left, right):
        if(left == 0):
          return(self.pre[right])
        else:
          return(self.pre[right] - self.pre[left - 1])



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
