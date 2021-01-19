class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

      // base case
      if(strs.size() < 1)
        return "";

      string s = strs[0];
      for(int i = 1; i < strs.size(); i++) {
        int j = 0;

        // compare the characters in the string to get the common prefix
        while(s[j] == strs[i][j] && j < s.length() && j < strs[i].length()) j++;

        // update the prefix
        s = s.substr(0, j);

      }
      return s;
    }
};
