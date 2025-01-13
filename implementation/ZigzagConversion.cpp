class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows + 1, "");
        vector<int> seq(s.size() + 1, 0);
        bool isDownwards = true;
        int turn = 1;
        for(int i=0; i<s.length(); i++) {
            if(isDownwards) {
                cout << "turn : " << turn << ' ' << s[i] << '\n';
                v[turn++] += s[i];
                
                if(turn > numRows) {
                    isDownwards = false;
                    turn = numRows - 1 > 0 ? numRows - 1 : 1;
                }
            } else {
                cout << "turn : " << turn << ' ' << s[i] << '\n';
                v[turn--] += s[i];
                
                if(turn < 1) {
                    isDownwards = true;
                    turn = 2 > numRows ? 1 : 2;
                }
            }
        }

        string ans = "";
            for(int i=0; i<v.size(); i++) {
                ans += v[i];
            }

            return ans;
    }
};
