#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        perm(result, nums, 0, nums.size());
        return result;
    }

    static void perm(vector<vector<int>> &result, vector<int> &nums, int pos, int len) {
        if(pos == len)
            result.push_back(nums);
        for(int i = pos; i < len; i++) {
          swap(nums[pos], nums[i]);
          perm(result, nums, pos + 1, len);
          swap(nums[pos], nums[i]);
        }
    }
};

int main() {
    vector<int> v = {1,2,3};
    vector<vector<int>> ret = Solution::permute(v);
    for(auto n : ret) {
        for(auto i : n)
            cout << i << " ";
        cout << endl;
    }
  return 0;
}
