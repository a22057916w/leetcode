// Question : https://leetcode.com/problems/number-of-good-pairs/

#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> cnt;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt.find(nums[i]) != cnt.end())
                cnt[nums[i]]++;
            else
                cnt.insert(make_pair(nums[i], 0));
        }

        int ans = 0;
        for(int i = 0; i < cnt.size(); i++)
            ans += cnt[i] * (cnt[i] + 1) / 2;

        return ans;
    }
};
