#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
          ans ^= nums[i];
        return ans;
    }
};

int main() {
  vector<int> v = {4,2,1,2,1};
  cout << Solution::singleNumber(v) << endl;
}
