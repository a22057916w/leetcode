#include <iostream>
using namespace std;

class Solution {
public:
    static double myPow(double x, int n) {
        if(n == 0)
            return 1;
        double tmp = myPow(x, n / 2);
        if(n % 2 == 0)
            return tmp * tmp;
        else {
            if(n > 0)
                return x * tmp * tmp;
            else
                return
        }
    }
};

int main() {
  vector<int> v = {3,2,3};
  cout << Solution::myPow(1,2147483647) << endl;
  //cout << pow(2,-2147483648) << endl;

  return 0;
}
