// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3667/

class Solution {
public:
    string intToRoman(int num) {
      vector<string> roman = {"M", "D", "C", "L", "X", "V", "I"};
      vector<int> integer = {1000, 500, 100, 50, 10, 5, 1};
      vector<int> carry = {100, 100, 10, 10, 1, 1, 0};

      string result = "";

      for(int i = 0; i < 7 && num > 0; i++) {
        int quotient = num / integer[i];
        while(quotient--)
          result += roman[i];
        num %= integer[i];


        if(num + carry[i] >= integer[i]) {
          result += (i % 2 ? roman[i + 1] + roman[i] : roman[i + 2] + roman[i]);
          num -= integer[i] - carry[i];
        }
      }

      return result;
    }
};
