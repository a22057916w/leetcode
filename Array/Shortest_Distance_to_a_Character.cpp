class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
      vector<int> dest(s.length(), 0);

      int prev = INT_MIN / 2;
      for (int i = 0; i < s.length(); ++i) {
          if (s[i] == c)
            prev = i;
          dest[i] = i - prev;
      }

        prev = INT_MAX / 2;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == c)
              prev = i;
            dest[i] = min(dest[i], prev - i);
        }

        return dest;
    }
};
