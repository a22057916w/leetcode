#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;

        // checking a number is carrying
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] >= 10) {
                if(i == 0) {
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                }
                else {
                    digits[i - 1]++;
                    digits[i] = 0;
                }
            }
            else
                break;
        }
        return digits;
    }
};
