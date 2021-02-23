// Watch the explnation in second comment of https://leetcode.com/problems/brok
// en-calculator/discuss/234484/JavaC%2B%2BPython-Change-Y-to-X-in-1-Line


class Solution {
public:
    int brokenCalc(int X, int Y) {
      int cnt = 0;

      while(Y > X) {
        if(Y % 2)
          Y++;
        else
          Y /= 2;
        cnt++;
      }

      return cnt + X - Y;
    }
};
