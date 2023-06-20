#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii > iii;
#define mp make_pair 
#define INF 987654321

int N, M;
char board[51][51];
vector<pair<int, int> > v;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int checked[51][51];

bool border_checking(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int bfs(int x, int y) {
    int result = 0;
    queue<ii > q; q.push(mp(x, y));
    checked[x][y] = 1;

    while(!q.empty()) {
        int now_x = q.front().first, now_y = q.front().second; q.pop();

        for(int i=0; i<4; i++) {
            int next_x = now_x + dx[i], next_y = now_y + dy[i];
            if(border_checking(next_x, next_y) && board[next_x][next_y] == 'L' && !checked[next_x][next_y]) {
                q.push(mp(next_x, next_y)); 
                checked[next_x][next_y] = checked[now_x][now_y] + 1;
                result = max(result, checked[next_x][next_y]);
            }
        }
    }

    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
        cin >> board[i][j];
        if(board[i][j] == 'L') {
            v.emplace_back(make_pair(i, j));
        }
    }

    int result = 0;
    for(int i=0; i<v.size(); i++) {
        memset(checked, 0, sizeof(checked));
        result = max(result, bfs(v[i].first, v[i].second));
    }

    cout << result - 1 << '\n';
    return 0;
}
