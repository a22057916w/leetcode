#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static void reverseString(vector<char>& s) {
      reverse(s.begin(), s.end());
      for(auto c : s)
        cout << c << " ";
    }
};

int main() {
  vector<char> s = "abcdefgh";
  Solution::reverseString(s)
  return 0;
}
