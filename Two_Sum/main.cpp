#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
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

vector<int> extractNums(string s) {
  string front = s.find('[');
  string end = s.find(']');
  string numss = s.substr(front + 1, (end - 1) - front);

  vector<int> nums;
  char *token = strtok(nums.data(), ',')
  while(token != NULL) {
    nums.push_back(stoi(token));
    token = strtok(NULL, ",");
  }
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  vector<int> ans = Solution::twoSum(nums, target);
  for(size_t n : ans)
    cout << n << endl;

  return 0;
}
