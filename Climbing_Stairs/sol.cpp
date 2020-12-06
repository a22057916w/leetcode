#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        return rec(n);
    }

    static int rec(int n) {
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
