/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int solve(string s, string t) {
    int ans = 987654321;
    int alpha['Z' - 'A' + 1];
    memset(alpha, 0, sizeof(alpha));
    for(int i=0; i<s.length(); i++) {
        alpha[s[i] - 'A']++;
    }
    
    map<char, int> m;
    int dup['Z' - 'A' + 1];
    memset(dup, 0, sizeof(dup));
    for(int i=0; i<t.length(); i++) {
        dup[t[i] - 'A']++;
        m[t[i]] = alpha[t[i] - 'A'];
    }
    
    for(int i='A'; i<='Z'; i++) {
        if(dup[i - 'A'] > 1) {
            m[i] /= dup[i - 'A'];
        }
        
        if(dup[i - 'A'] >= 1) {
            ans = min(ans, m[i]);
        }
    }
    cout << t << " ans : " << ans << '\n';
    return ans;
}

int main()
{
    string s;
    vector<string> v;
    cin >> s;
    
    for(int i=0; i<3; i++) {
        string t; cin >> t;
        v.emplace_back(t);
    }
    
    int max_val = -1;
    for(int i=0; i<v.size(); i++) {
        max_val = max(max_val, solve(s, v[i]));
    }
    
    printf("%d\n", max_val);
    return 0;
}
