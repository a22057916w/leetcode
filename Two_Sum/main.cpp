#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        vector<int> answer;

        for(size_t i = 0; i < nums.size(); i++) {
          int needed_num = target - nums[i];

          if(cache.find(needed_num) != cache.end()) {
            answer.push_back(cache[needed_num]);
            answer.push_back(i);
            return answer;
          }
          else
            cache.insert(make_pair(nums[i], i));
        }
    }
};


// extracting data in the "num = [n1,n2,...,nn]" to a string "n1,n2,...,nn",
// then spliting the comma and stroing to a vector<int>.
vector<int> extractNums(string s) {

  // performing string extracting.
  int front = s.find('[');
  int end = s.find(']');
  string input = s.substr(front + 1, (end - 1) - front);

  // performing spliting using stringstream and string lib,
  // and storing to a vector<int> container.
  vector<int> v;
  stringstream ss(input);
  string token;
  while(getline(ss, token, ','))
    v.push_back(stoi(token));

  return v;
}



int main() {
  string data = "nums = [2,7,11,15], target = 9";

  vector<int> nums = extractNums(data);
  int target = 9;

  vector<int> ans = Solution::twoSum(nums, target);
  for(size_t n : ans)
    cout << n << endl;

  return 0;
}
