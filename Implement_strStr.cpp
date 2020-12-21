// impelement using c standard lib underlying approaching
#include <cstring>
class Solution {
public:
    int strStr(string haystack, string needle) {
        char *s = haystack.data(), *find = needle.data();
        if(s == 0 || find == 0)
            return 0;

        int index = 0;
        size_t len = strlen(find);
        while(strncmp(s, find, len) != 0) {
            if(*s++ == 0)
                return -1;
            index++;
        }
        return index;
    }
};

// impelement using c++ stl lib, 5ms faster
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;

        int pos = haystack.find(needle);
        if(pos != string::npos)
            return pos;
        else
            return -1;
    }
};
