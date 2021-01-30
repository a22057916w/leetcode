/*
Concept
1. For any given configuration of nums the deviation is equal to (maxx - minn)
2. To decrease the deviation either increase the minn or decrease the maxx.
3. Now, Make every number as maximum as possible to eliminate one operation
   (increase the minn) since every element is as maximum as possible , you can
   not increase any number further.
4. Now we are left with just one operation decrease the maxx.
5. So perform this operation as any times as u can and keep track of the min_deviation
*/

#include <algorithm>
#include <queue>

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
      int maxx = INT_MIN, minn = INT_MAX;

      // Step 1 :- increase all elements to as maximum as it can and track the minn number and also the result
      for(auto& n : nums) {
        if(n % 2 != 0)
          n *= 2;

        maxx = max(maxx, n);
        minn = min(minn, n);
      }

      // Step 2 :- Insert into max_heap and try to decrease the maxx as much as u can
      priority_queue<int> pq;
      for(const auto& n : nums)
        pq.push(n);

      int min_deviation = maxx - minn;

      while(pq.top() % 2 == 0) {
        int top = pq.top();
        pq.pop();

        min_deviation = min(min_deviation, top - minn);

        top /= 2;
        minn = min(minn, top);
        pq.push(top);
      }
      min_deviation = min(min_deviation, pq.top() - minn);

      // Step 3 : return maxx - minn
      return min_deviation;
    }
};
