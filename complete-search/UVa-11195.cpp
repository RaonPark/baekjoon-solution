#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int n, OK;
int ans = 0;
int bad[15];

void backtrack(int rw, int ld, int rd, int row) {
    if(rw == OK) {
        ans++; return;
    }
    
    int pos = OK & (~(rw | ld | rd | bad[row]));
    while(pos) {
        int p = pos & -pos;
        pos -= p;
        backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1, row + 1);
    }
}

int main() {
    int t = 1;
    while(true) {
        scanf("%d", &n);
        if(n == 0)
            break;
        
        ans = 0;
        OK = (1 << n) - 1;
        memset(bad, 0, sizeof(bad));
        for(int i=0; i<n; i++) {
            int bit = 0;
            char s[15]; scanf("%s", &s);
            for(int j=0; j<n; j++) {
                if(s[j] == '*') {
                    bad[j] |= (1 << i);
                }
            }
        }
        backtrack(0, 0, 0, 0);
        printf("Case %d: %d\n", t, ans);
        t++;
    }
}
