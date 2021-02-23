#include <cmath>
using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    double ans = powCur(x, abs(n));
    if(n < 0) {
      if(isinf(1 / ans))
          return 0;
      else
          return 1 / ans;
    }
    else
      return ans;
  }

  // do not deal with the negative sign
  double powCur(double x, int n) {
    if(n == 0)
        return 1;
    double tmp = myPow(x, n / 2);
    if(n % 2 == 0)
        return tmp * tmp;
    else
        return x * tmp * tmp;
  }
};
