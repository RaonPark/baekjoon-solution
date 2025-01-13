class Solution {
public:
    string reverseWords(string s) {
        if(s[0] == ' ') {
            s.erase(0, s.find_first_not_of(' '));
        }
        if(s[s.length() - 1] == ' ') {
            s.erase(s.find_last_not_of(' ') + 1);
        }

        stack<string> st;
        while(!s.empty()) {
            if(s[0] == ' ') {
                s.erase(0, s.find_first_not_of(' '));
            }
            string t = s.substr(0, s.find_first_of(' '));
            ans += t + ' ';
            s.erase(0, s.find_first_of(' '));
        }

        return ans.substr();
    }
};
