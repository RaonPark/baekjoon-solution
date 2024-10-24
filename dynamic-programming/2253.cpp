#include <bits/stdc++.h>
using namespace std;

int N, M;
int small[10000];
int cache[200][10002];

#define PLUS 1
#define MINUS 2
#define ZERO 3
#define INF 987654321

bool is_small(int n) {
    for(int i=0; i<M; i++) {
        if(small[i] == n)
            return true;
    }
    return false;
}

int dp(int x, int n) {
    if(n > N || is_small(n)) {
        return INF;
    }
    if(n == N) {
        return 0;
    }
    
    int& ret = cache[x][n];
    if(ret != -1)
        return ret;
    
    ret = INF;
    ret = min(ret, dp(x, n + x) + 1);
    if(n > 1)
        ret = min(ret, dp(x + 1, n + x + 1) + 1);
    if(x - 1 >= 1)
        ret = min(ret, dp(x - 1, n + x - 1) + 1);
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        scanf("%d", &small[i]);
    }
    
    memset(cache, -1, sizeof(cache));
    
    int result = dp(1, 1);
    printf("%d\n", result >= INF ? -1 : result);
}
