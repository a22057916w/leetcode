class Solution {
public:
    string defangIPaddr(string address) {
        stringstream ss(address);
        string token;

        int cnt = 0;
        string s = "";

        // std::string::getline
        while(getline(ss, token, '.')) {
            if(cnt++ > 0)
                s += "[.]";
            s += token;
        }
        return s;
    }
};
