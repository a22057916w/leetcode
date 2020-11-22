#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int maxn = 5;

int main() {
  int arr[5] = {1, 4, 2, 5, 3};

    int odd = 1;
    int ans = 0;
    while(odd <= maxn) {

      for(int i = 0; i <= maxn - odd; i++) {
        int sum = 0;
        for(int j = i; j < i + odd; j++)
          sum += arr[j];
        cout << sum << endl;
        ans += sum;
        }

      odd += 2;
    }
    cout << ans << endl;
  return 0;
}
