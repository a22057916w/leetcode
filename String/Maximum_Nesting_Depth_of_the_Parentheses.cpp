/*
e.g. ()(), (()), ()(())
*/

#include <algorithm>

class Solution {
public:
    int maxDepth(string s) {
      int parentheses = 0, depth = 0;

      for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(')
          parentheses++;
        if(s[i] == ')')
          parentheses--;

        // find the maxinum number of '(' - ')'
        depth = max(depth, parentheses);
      }

      return depth;
    }
};
