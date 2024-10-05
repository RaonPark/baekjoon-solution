#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[501][501];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

typedef pair<int, int> ii;
#define mp make_pair

bool border_checking(int y, int x) {
    return (y>=0 && y<n && x>=0 && x<m);
}

int bfs(int y, int x) {
    queue<ii > q;
    q.push(mp(y, x));
    board[y][x] = 0;
    
    int result = 1;
    while(!q.empty()) {
        ii now = q.front(); q.pop();
        
        for(int i=0; i<4; i++) {
            int ny = now.first + dy[i], nx = now.second + dx[i];
            if(border_checking(ny, nx) && board[ny][nx] == 1) {
                q.push(mp(ny, nx));
                board[ny][nx] = 0;
                result++;
            }
        }
    }
    
    return result;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    int max_val = 0, num = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 1) {
                int result = bfs(i, j);
                max_val = max(max_val, result);
                num++;
            }
        }
    }
    
    printf("%d\n%d\n", num, max_val);
}
