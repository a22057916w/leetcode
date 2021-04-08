/*
Reference:
http://web.ntnu.edu.tw/~algo/Subsequence.html
https://www.mdeditor.tw/pl/gbLO/zh-tw
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

    int bisec(vector<int>& tail, int left, int right, int key) {
      while(left < right) {
        int mid = (left + right) >> 1;
        if(tail[mid] >= key)
          right = mid;
        else
          left = mid;
      }
      
      return right;
    }
};
