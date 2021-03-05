/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
*/


#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> st;

      for(int i = 0; i < s.length(); i++) {

        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
          st.push(s[i]);
        else {
          if(st.empty())
            return false;
          if(s[i] == ')' && st.top() != '(')
            return false;
          if(s[i] == ']' && st.top() != '[')
            return false;
          if(s[i] == '}' && st.top() != '{')
            return false;
          st.pop();
        }
      }

      return st.empty();
    }
};
