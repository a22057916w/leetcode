#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// burtal force
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
      int n = arr.size();
      int interval = 1;   // for odd length interval
      int ans = 0;

      while(interval <= n) {
        for(int i = 0; i <= n - interval; i++)
          for(int j = i; j < i + interval; j++)
            ans += arr[j];
        interval += 2;
      }

      return ans;
    }
};

// math solution
/*class Solution {
public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();
    int interval_cnt = (n + 1) / 2;   // for odd length interval
    int ans = 0;

    int i = 0, j = interval_cnt;      //  j for manipulating the interval

    // the times of a traversed number equals the counts of intevals of the number,
    // then add the privous number. e.g. the times of a[1] = times of a[1] traversed by
    // different size of interval + times of a[0].
    for(; i <= n / 2; i++) {
      if(i == n / 2 && n % 2)                   // condition for odd numbers array
        ans += arr[i] * j;
      else if(i == n / 2 - 1 && n % 2 == 0) {   // condition for even numbers array
        ans += arr[i] * j + arr[(n - 1) - i] * j;
        break;
      }
      else
        ans += arr[i] * j + arr[(n - 1) - i] * j;

      // rule out the interval count "1", e.g. when interval size is one,
      // it does not include other numbers
      j--;

      j += (n - (i + 1) + 1) / 2 ;
    }
    return ans;
  }
};*/
