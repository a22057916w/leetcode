#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      nums1.resize(m);
      nums1.insert(nums1.begin() + m, nums2.begin(), nums2.end());
      sort(nums1.begin(), nums1.end());

      return;
    }
};
