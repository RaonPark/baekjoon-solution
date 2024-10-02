#include <bits/stdc++.h>
using namespace std;

int R, C;
char board[21][21];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int max_val = 1;

bool border_checking(int r, int c) {
    return (r>=0 && r<R && c>=0 && c<C);
}

void dfs(int r, int c, bitset<30> bs) {
    max_val = max(max_val, (int)bs.count());
    for(int i=0; i<4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(border_checking(nr, nc)) {
            if(bs[board[nr][nc]] == 0) {
                bs[board[nr][nc]] = 1;
                dfs(nr, nc, bs);
                bs[board[nr][nc]] = 0;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;
    
    for(int i=0; i<R; i++) {
        string s; cin >> s;
        for(int j=0; j<C; j++) {
            board[i][j] = s[j];
        }
    }
    
    bitset<30> bs; bs.reset();
    bs[board[0][0]] = 1;
    dfs(0, 0, bs);
    
    
    cout << max_val << '\n';
}
