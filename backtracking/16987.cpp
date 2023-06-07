#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define mp make_pair

int N;
vector< ii > eggs;
bool check[8] = {false};
bool broken[8] = {false};
int result = 0;

void backtracking(int now) {
    if(now == N) {
        int cnt = 0;
        for(int i=0; i<N; i++)
            if(eggs[i].first <= 0) cnt++;
        result = max(cnt, result);
        return;
    }

    bool flag = false;
    for(int i=0; i<N; i++) {
        if(i == now) continue;
        if(eggs[now].first > 0 && eggs[i].first > 0) {
            eggs[now].first -= eggs[i].second;
            eggs[i].first -= eggs[now].second;
            flag = true;
            backtracking(now + 1);
            eggs[now].first += eggs[i].second;
            eggs[i].first += eggs[now].second;
        }
    }

    if(!flag) backtracking(now + 1);
}

int main(void) {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        int s, w; scanf("%d %d", &s, &w);
        eggs.emplace_back(mp(s, w));
    }

    backtracking(0);

    printf("%d\n", result);
    return 0;
}
