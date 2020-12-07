#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static void reverseString(vector<char>& s) {
      reverse(s.begin(), s.end());
    }
};
