#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool isMonotonic(vector<int>& A) {
        if(A.size() == 1)
          return true;
        else
          return checkMono(A);
    }

    static bool checkMono(vector<int> A) {
      bool inc = true, dec = true;

      // checkiing for monotone increasing
      for(int i = 1; i < A.size(); ++i)
        if(A[i] < A[i - 1]) {
          inc = false;
          break;
        }

      // checkiing for monotone decreasing
      for(int i = 1; i < A.size(); ++i)
        if(A[i] > A[i - 1]) {
          dec = false;
          break;
        }

      return inc | dec;
    }
};

int main() {
  vector<int> v = {1,2,2,3};
  cout << Solution::isMonotonic(v) << endl;
  return 0;
}
