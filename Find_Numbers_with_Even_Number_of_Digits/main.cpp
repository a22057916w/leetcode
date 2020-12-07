#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
      int even = 0;
        for(size_t n : nums) {
          if(n < 10)
            continue;
          else if(n < 100)
            even++;
          else if(n < 1000)
            continue;
          else if(n < 10000)
            even++;
          else if(n < 100000)
            continue;
          else
            even++;
        }
      return even;
    }
};
