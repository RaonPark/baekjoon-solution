#include <bits/stdc++.h>
using namespace std;

int len = 0;
char s[5001];
int cache[5001];
const int MOD = 1000000;

// 19126
// 1 9 1 2 6
// 19 1 2 6
// 1 9 12 6
// 19 12 6
// 19 1 26
// 1 9 1 26

int dp(int lp) {
    if(lp > len)
        return 1;
    
    int& ret = cache[lp];
    if(ret != -1)
        return ret;
        
    ret = 0;
    if((s[lp] - '0') != 0) {
        ret = dp(lp + 1) % MOD;
        int alpha = (s[lp] - '0') * 10 + (s[lp+1] - '0');
        if(lp + 2 <= len && alpha >= 10 && alpha <= 26) {
            ret += (dp(lp + 2) % MOD);
        }
    }
    
    return ret;
}

int main() {
    scanf("%s", &s);
    
    for(int i=0; s[i] != '\0'; i++)
        len++;
        
    memset(cache, -1, sizeof(cache));
    int result = dp(0) % MOD;
    printf("%d\n", result % MOD);
}
