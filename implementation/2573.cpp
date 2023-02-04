#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int N, M, adjMat[310][310], zeroMat[310][310];
bool visit[310][310];
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void bfs(int u, int v) {
    queue< ii > q; q.push({u, v}); visit[u][v] = true;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second, zeroCounter = 0; q.pop();
        for(int i=0; i<4; ++i) {
            int x2 = x + dx[i], y2 = y + dy[i];
            if(x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && !visit[x2][y2] && adjMat[x2][y2] != 0){
                q.push({x2, y2}); visit[x2][y2] = true;
            }
            if(x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && adjMat[x2][y2] == 0) zeroCounter++;
        }
        zeroMat[x][y] = zeroCounter;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) {
        scanf("%d", &adjMat[i][j]); zeroMat[i][j] = 0; visit[i][j] = false;
    }
    int result = 0;
    while(1) {
        int counter = 0;
        for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
            if(adjMat[i][j] != 0 && !visit[i][j]) {
                bfs(i, j); counter++;
            }
        if(counter > 1) { printf("%d\n", result); break; }
        bool flag = true;
        for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) {
            int num = adjMat[i][j] - zeroMat[i][j];
            adjMat[i][j] = num < 0 ? 0 : num;
            if(flag && adjMat[i][j] != 0) { flag = false; }
            zeroMat[i][j] = 0;
            visit[i][j] = false;
        }
        if(flag) { puts("0"); break; }
        result++;
    }
}
