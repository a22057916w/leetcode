#include <iostream>
#include <vector>
using namespace std;

// bitwise approach: S(1), O(n)
// a xor 0 = a
// a xor a = 0
// a xor b xor a = (a xor a) xor b = 0 xor b = b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
          ans ^= nums[i];
        return ans;
    }
};
