#include <bits/stdc++.h>
using namespace std;

int N;
string result = "";


// 기껏해야 O(N^3)
int is_good(string now) {
    for(int i=0; i<now.length(); i++) {
        for(int j=1; j<=now.length() - i; j++) {
            string frag = now.substr(i, j);
            
            bool flag = true;
            for(int k=0; k<frag.length(); k++) {
                if(frag[k] != now[i+k+j])
                    flag = false;
            }
        
            if(flag) {
                return false;
            }
        }
    }
    
    return true;
}

string min(string& a, string& b) {
    for(int i=0; i<a.length(); i++) {
        if(a[i] < b[i])
            return a;
    }
    return b;
}

void solve(string now, int digit) {
    if(!is_good(now))
        return;
    if(digit > N)
        return;
    if(digit == N) {
        if(!is_good(now))
            return;
        result = min(result, now);
        return;
    }
    
    if(result != "")
        return;
    
    for(int num=1; num<=3; num++) {
        if(now[digit - 1] == ('0' + num))
            continue;
        string next = now + to_string(num);
        if(is_good(next))
            solve(next, digit+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    solve("", 0);
    cout << result << '\n';
}
