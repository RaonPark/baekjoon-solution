#include <bits/stdc++.h>
using namespace std;

#define INF 987654321;

class Point {
public:
    int x, y;
    int broken;
    int cnt;

    Point(int x, int y, int broken, int cnt)
        :x(x), y(y), broken(broken), cnt(cnt) { }
};

int N, M;
char board[1001][1001];
int visited[1001][1001][2];
int checked[1001][1001];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool border_checking(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int bfs() {
    queue<Point> q; Point p(0, 0, 0, 0); q.push(p);
    visited[0][0][0] = 1;
    
    while(!q.empty()) {
        Point np = q.front(); q.pop();
        if(np.x == N - 1 && np.y == M - 1) return np.cnt + 1;

        for(int i=0; i<4; i++) {
            int nx = np.x + dx[i], ny = np.y + dy[i];
            if(border_checking(nx, ny) && visited[nx][ny][np.broken] > np.cnt + 1) {
                if(board[nx][ny] == '1' && np.broken == 0) {
                    visited[nx][ny][np.broken] = np.cnt + 1;
                    Point next_p(nx, ny, np.broken + 1, np.cnt +1);
                    q.push(next_p);
                }
                else if(board[nx][ny] == '0') {
                    //printf("%d %d to %d, %d -> %d compare %d\n", np.x, np.y, nx, ny, np.cnt, visited[nx][ny][np.broken]);
                    visited[nx][ny][np.broken] = np.cnt + 1;
                    Point next_p(nx, ny, np.broken, np.cnt +1);
                    q.push(next_p);
                }
            }
        }
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    string column;

    for(int i=0; i<N; i++) {
        cin >> column;
        for(int j=0; j<M; j++) {
            board[i][j] = column[j];
        }
    }
    
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) for(int k=0; k<2; k++) visited[i][j][k] = INF;

    int result = bfs();
    printf("%d\n", result);

    return 0;
}
