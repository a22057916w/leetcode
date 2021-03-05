#include <string>
using namespace std;

class Solution1 {
public:
    int romanToInt(string s) {
      int sum = 0;

      s += 'a';   // prevent from error "out of index"
      for(int i = 0; i < s.length(); i++)
        sum += getValue(s, i);

      return sum;
    }

    int getValue(string s, int i) {
      switch(s[i]) {
        case 'I': return (s[i + 1] == 'V' || s[i + 1] == 'X') ? -1 : 1;
        case 'X': return (s[i + 1] == 'L' || s[i + 1] == 'C') ? -10 : 10;
        case 'C': return (s[i + 1] == 'D' || s[i + 1] == 'M') ? -100 : 100;
        case 'V': return 5;
        case 'L': return 50;
        case 'D': return 500;
        case 'M': return 1000;
      }
      return 0;
    }
};

// using c pointer and switch
class Solution2 {
public:
    int romanToInt(string s) {
      char *cs = s.data();

      int sum = 0;
      for(;*cs != '\0'; cs++)
        sum += getValue(cs);
      return sum;
    }

    int getValue(const char *cs) {
      switch(*cs) {
        case 'I': return (cs[1] == 'V' || cs[1] == 'X') ? -1 : 1;
        case 'X': return (cs[1] == 'L' || cs[1] == 'C') ? -10 : 10;
        case 'C': return (cs[1] == 'D' || cs[1] == 'M') ? -100 : 100;
        case 'V': return 5;
        case 'L': return 50;
        case 'D': return 500;
        case 'M': return 1000;
      }
      return 0;
    }
};
