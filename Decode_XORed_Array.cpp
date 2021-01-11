/*
The idea is to use the characteristic of xor operation
A xor B = C
        => C xor B = A
        -> C xor A = B
*/
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
      vector<int> ans;
      ans.push_back(first);

      int j = first;
      for(int i = 0; i < encoded.size(); i++) {
        ans.push_back(encoded[i] ^ j);
        j = encoded[i] ^ j;
      }

      return ans;
    }
};
