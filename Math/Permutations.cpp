class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        perm(result, nums, 0, nums.size());
        return result;
    }

    // perm(a, b, c) = a + perm(b, c) -> perm(b,c) = b + perm(c)
    //                 b + perm(a, c)                c + perm(b)
    //                 c + perm(a, b)
    void perm(vector<vector<int>> &result, vector<int> &nums, int pos, int len) {
        if(pos == len)                          // print/store a permutation
            result.push_back(nums);
        for(int i = pos; i < len; i++) {
          swap(nums[pos], nums[i]);             // swaping the head, e.g. abc -> bac
          perm(result, nums, pos + 1, len);     // then do b + perm(a, c)
          swap(nums[pos], nums[i]);             // swaping back, e.g. bac -> abc
        }
    }
};
