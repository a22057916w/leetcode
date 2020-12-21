// For c underlying approach
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
