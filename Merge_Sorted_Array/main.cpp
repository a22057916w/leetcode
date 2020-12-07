#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      nums1.resize(m);
      nums1.insert(nums1.begin() + m, nums2.begin(), nums2.end());
      sort(nums1.begin(), nums1.end());
      for(size_t n : nums1)
        cout << n << " ";
    }
};

int main() {
  vector<int> num1 = {1,2,3,0,0,0};
  vector<int> num2 = {2,5,6};
  Solution::merge(num1, 3, num2, 3);
  return 0;
}
