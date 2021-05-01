/*
Reference:
https://stackoverflow.com/questions/45494567/c-how-to-sort-the-rows-of-a-2d-vector-by-the-values-in-each-rows-column
https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-in-c11
https://en.cppreference.com/w/cpp/algorithm/sort
https://en.cppreference.com/w/cpp/named_req/Compare
*/

#include <alogrithm>
#include <vector>

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1])}; );
    }
};
