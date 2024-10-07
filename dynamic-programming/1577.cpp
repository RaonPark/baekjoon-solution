#include <bits/stdc++.h>
using namespace std;

typedef struct points {
    int sr, sc;
    int er, ec;
} points;

int N, M, K;
vector<points> v;
long long cache[101][101];
int dr[2] = {1, 0};
int dc[2] = {0, 1};

bool border_checking(int r, int c) {
    return (r>=0 && r<=N && c>=0 && c<=M);
}

bool is_blocked(int r, int c, int nr, int nc) {
    for(int i=0; i<K; i++) {
        points p = v[i];
        if(p.sr == r && p.sc == c && p.er == nr && p.ec == nc)
            return true;
        if(p.sr == nr && p.sc == nc && p.er == r && p.ec == c)
            return true;
    }
    return false;
}

long long dp(int r, int c, int cnt) {
    if(r == N && c == M) {
        return 1;
    }
    
    long long& ret = cache[r][c];
    if(ret != -1)
        return ret;
        
    ret = 0;
    for(int i=0; i<2; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(border_checking(nr, nc) && !is_blocked(r, c, nr, nc)) {
            ret += dp(nr, nc, cnt + 1);
        }
    }
    
    return ret;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=0; i<K; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        points p;
        p.sr = a; p.sc = b; p.er = c; p.ec = d;
        v.emplace_back(p);
    }
    
    memset(cache, (long long)-1, sizeof(cache));
    long long result = dp(0, 0, 0);
    printf("%lld\n", result);
}
