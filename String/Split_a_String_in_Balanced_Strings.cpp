class Solution {
public:
    int balancedStringSplit(string s) {
      int count = 0, balance = 0;


      for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'R')
          count++;
        if(s[i] == 'L')
          count--;

        // if count == 0, it means we have swept same amount of R and L in eithor order
        if(count == 0)
          balance++;
      }

      return balance;
    }
};
