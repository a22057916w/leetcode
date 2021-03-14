#include <iostream>
#include <vector>
using namespace std;


class Solution1 {
public:
    int climbStairs(int n) {
        return rec(n);
    }

    int rec(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else
            return rec(n - 1) + rec(n - 2);
    }
};

// the recursion pattern is Fibnoacci series
class Solution2 {
public:
    int climbStairs(int n) {
      int maxn = 50;
      int fib[maxn];

      fib[0] = 1;
      fib[1] = 1;
      for(int i = 2; i < maxn; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

      return fib[n];
    }
};
