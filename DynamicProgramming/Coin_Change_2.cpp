// https://leetcode.com/problems/coin-change-2/

#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
      vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        // dp[i] represents the number of ways of making up the coin to amount i
        // usgin coins as pivots that will eliminate the duplication such as (2+1, 1+2)
        for (const auto& c : coins) {
            for (int i = c; i <= amount; i++)
                dp[i] += dp[i - c];
        }

        return dp[amount];
    }
};
