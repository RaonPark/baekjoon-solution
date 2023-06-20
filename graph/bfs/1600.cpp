#include <bits/stdc++.h>
using namespace std;

class Monkey {
public:
    int x, y;
    int k;
    int cnt;

    Monkey(int x, int y, int k, int cnt)
        :x(x), y(y), k(k), cnt(cnt) { }
};

int K;
int W, H;
int board[201][201];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};

bool border_checking(int x, int y) {
    return (x >= 0 && x < H && y >= 0 && y < W);
}

int bfs() {
    Monkey m(0, 0, 0, 0);
    queue<Monkey> q; q.push(m);
    bool visited[201][201][31]; memset(visited, 0, sizeof(visited));
    visited[0][0][0] = 1;

    while(!q.empty()) {
        Monkey now = q.front(); q.pop();

        if(now.x == H - 1 && now.y == W - 1) return now.cnt;
        if(now.k < K) {
            for(int i=0; i<8; i++) {
                int next_x = now.x + dx[i], next_y = now.y + dy[i];
                if(border_checking(next_x, next_y) && board[next_x][next_y] == 0 && !visited[next_x][next_y][now.k + 1]) {
                    visited[next_x][next_y][now.k + 1] = true;
                    Monkey next_m(next_x, next_y, now.k + 1, now.cnt + 1);
                    q.push(next_m);
                }
            }
        }

        for(int i=0; i<4; i++) {
            int next_x = now.x + mx[i], next_y = now.y + my[i];
            if(border_checking(next_x, next_y) && board[next_x][next_y] == 0 && !visited[next_x][next_y][now.k]) {
                visited[next_x][next_y][now.k] = true;
                Monkey next_m(next_x, next_y, now.k, now.cnt + 1);
                q.push(next_m);
            }
        }
    }

    return -1;
}

int main(void) {
    scanf("%d %d %d", &K, &W, &H);
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) scanf("%d", &board[i][j]);
    }

    int result = bfs();
    printf("%d\n", result);
    return 0;
}
