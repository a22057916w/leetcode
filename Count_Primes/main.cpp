#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;


class Solution {
public:
    static int countPrimes(int n) {
        vector<int> prime = primelist(n);   // get a list of primes

        int total = 0;
        for(int i = 0; i < prime.size(); i++)   // count the primes
            if(prime[i] < n)
                total++;
            else
                break;

        return total;
    }

    static vector<int> primelist(int n) {
        vector<bool> vis(n + 1, false);
        vector<int> prime;

        // producing prime number list
        for(long long i = 2; i <= n; i++) {
            if(vis[i])
                continue;
            else {
                prime.push_back(i);
                for(long long j = i * i; j <= n; j += i)
                    vis[j] = true;
            }
        }
        return prime;
    }
};

int main() {
  vector<int> v(10, 0);
  cout << Solution::countPrimes(10) << endl;
  return 0;
}
