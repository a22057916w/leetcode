#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
      map<int, int> m;

      int res = 0;

      for(const auto& n :nums)
        m.find(n) == m.end() ? m[n] = 1 : m[n]++;

      for(const auto& [key, value] : m)
        if(m.find(key + 1) != m.end())
          res = max(res, value + m[key + 1]);

      return res;
    }
};
