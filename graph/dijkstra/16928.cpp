#include <bits/stdc++.h>
using namespace std;

int N, M;
int ladder[101];
int snake[101];
int visited[101];

typedef pair<int, int> ii;
#define mp make_pair

int djikstra() {
    priority_queue<ii, vector<ii >, greater<ii > > pq;
    pq.push(mp(0, 1));
    int min_cnt = -1;
    
    while(!pq.empty()) {
        int cnt = pq.top().first, now = pq.top().second; pq.pop();
        
        if(now == 100) {
            return cnt;
        }
        
        if(cnt < min_cnt)
            continue;
        
        for(int dice=1; dice<=6; dice++) {
            int next = now + dice;
            if(next > 100) continue;
            if(ladder[next] != 0) next = ladder[next];
            else if(snake[next] != 0) next = snake[next];
            
            if(!visited[next]) {
                visited[next] = true;
                pq.push(mp(cnt + 1, next));
                min_cnt = max(min_cnt, cnt);
            }
        }
    }
    
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++) {
        int x, y; scanf("%d %d", &x, &y);
        ladder[x] = y;
    }
    
    for(int i=0; i<M; i++) {
        int u, v; scanf("%d %d", &u, &v);
        snake[u] = v;
    }
    
    int min_cnt = djikstra();
    // dfs(1, 0);
    
    printf("%d\n", min_cnt);
}
