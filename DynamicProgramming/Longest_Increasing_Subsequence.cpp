/*
Reference:
http://web.ntnu.edu.tw/~algo/Subsequence.html
https://www.mdeditor.tw/pl/gbLO/zh-tw
https://blog.techbridge.cc/2016/09/24/binary-search-introduction/
*/

// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> lng(nums.size(), 1);

      for(int i = 0; i < nums.size(); i++) {
        // find out
        for(int j = 0; j < i; j++)
          if(nums[j] < nums[i])
            lng[i] = max(lng[i], lng[j] + 1);
      }

      int maxl = INT_MIN;
      for(const auto& e : lng)
        maxl = max(maxl, e);

      return maxl;
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> tail(nums.size(), INT_MAX / 2);
      int len = 1;

      for(const auto& e : nums) {
        if(e < tail[0])
          tail[0] = e;
        else if(e > tail[len - 1])
          tail[len++] = e;
        else
          tail[bisec(tail, -1, len - 1, e)] = e;
      }

      return len;
    }

    int bisec(vector<int>& tail, int left, int right, int key) {
      while(right - left > 1) {
        int mid = (left + right) >> 1;
        if(tail[mid] >= key)
          right = mid;
        else
          left = mid;
      }

      return right;
    }
};
