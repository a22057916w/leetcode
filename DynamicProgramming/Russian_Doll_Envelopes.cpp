/*
Reference:
https://stackoverflow.com/questions/45494567/c-how-to-sort-the-rows-of-a-2d-vector-by-the-values-in-each-rows-column
https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
https://en.cppreference.com/w/cpp/algorithm/sort
https://en.cppreference.com/w/cpp/named_req/Compare
*/

// https://leetcode.com/problems/russian-doll-envelopes/

#include <alogrithm>
#include <vector>

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);} );


      vector<int> tail(envelopes.size(), INT_MAX / 2);
      int len = 1;

      for(const auto& envl : envelopes) {
        if(envl[1] <= tail[0])
          tail[0] = envl[1];
        else if(envl[1] > tail[len - 1])
          tail[len++] = envl[1];
        else
          tail[bisec(tail, 0, len - 1, envl[1])] = envl[1];
      }

      return len;
    }
    int bisec(vector<int>& tail, int L, int R, int key) {

      while(R - L > 1) {
        int M = (R - L) / 2 + L;
        if(tail[M] >= key)
          R = M;
        else
          L = M;
      }

      return R;
      }
};
