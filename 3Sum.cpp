class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

        for(int i = 0; i < size; i++) {
            dp[i][i] = nums[i];
            for(int j = i + 1; j < size; j++) {
                dp[i][j] = nums[i] + nums[j];
            }
        }

        for(int i = 1; i < size; i++)
            for(int j = i + 1; j < size; j++) {
                if(dp[i][j] + dp[i - 1][i] == 0) {
                    vector<int> triple = {i, i}
                }
            }
    }
};
