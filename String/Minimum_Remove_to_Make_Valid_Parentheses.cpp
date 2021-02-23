// Question : https://leetcode.com/problems/minimum-remove-to-make-valid-parenth
// eses/

#include <algorithm>
#include <string>
using std::string;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
      int right_parenthese = 0;
      int left_parenthese = 0;


      for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(')
          right_parenthese++;
        if(s[i] == ')')
          left_parenthese++;

        if(right_parenthese < left_parenthese) {
          s[i] = 'X';
          left_parenthese--;
        }
      }

      right_parenthese = 0;
      left_parenthese = 0;

      for(int i = s.length(); i >= 0; i--) {
        if(s[i] == ')')
          left_parenthese++;
        if(s[i] == '(')
          right_parenthese++;

        if(left_parenthese < right_parenthese) {
          s[i] = 'X';
          right_parenthese--;
        }
      }

      s.erase(std::remove(s.begin(), s.end(), 'X'), s.end());

      return s;
    }
};
