/*
The idea is to place the number by index.
e.g. For a list [1,4,3,2], we can make it an increaseing list [1,2,3,4] by
     subtract each element by 1, then replace the element.
For the question, if a given list is [1,4,2,2], applying the following
method , we get [1,2,_,4]. So we know the missing number is 3. However we cannot
use extra memory for the well-placed list, therefore, we find a way to mark the
index. We mark the original list by giving the element a negtive sign.
*/

#include <vector>
#include <cmath>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> miss;

      for(int i = 0; i < nums.size(); i++) {

        // get the index of the increasing list element from nums[i]
        // e.g. 4 -> [3]
        int index = abs(nums[i]) - 1;

        // mark the index by neg
        nums[index] = -abs(nums[index]);
      }

      // if an index is greater than 0, that is the missing number
      // which is i + 1
      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0)
            miss.push_back(i + 1);
      }

      return miss;
    }
};
