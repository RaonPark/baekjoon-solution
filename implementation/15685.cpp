#include <bits/stdc++.h>

using namespace std;

int N;
int board[110][110];

#define X_INC 0
#define Y_DEC 1
#define X_DEC 2
#define Y_INC 3
#define mp make_pair
#define eb emplace_back

typedef pair<int, int> ii;

bool board_checking(int y, int x) {
    return (x >= 0 && x <= 100 && y >= 0 && y <= 100);
}

ii get_end_point(int y, int x, int dir) {
    if(dir == X_INC)
        return mp(y, x+1);
    else if(dir == Y_DEC)
        return mp(y-1, x);
    else if(dir == X_DEC)
        return mp(y, x-1);
    else
        return mp(y+1, x);
}

void get_result() {
    int result = 0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) {
                result++;
            }
        }
    }
    
    printf("%d\n", result);
}

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        int y, x, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        
        vector<int> directions;
        directions.eb(d);
        
        int ex, ey;
        ii next = get_end_point(y, x, d);
        ey = next.first;
        ex = next.second;
        board[y][x] = 1;
        board[ey][ex] = 1;
        
        for(int gen=1; gen<=g; gen++) {
            int now_size = (int)directions.size();
            for(int idx=now_size-1; idx>=0; idx--) {
                int new_dir = directions[idx] == 3 ? 0 : directions[idx] + 1;
                
                ii end = get_end_point(ey, ex, new_dir);
                int ny = end.first, nx = end.second;
                if(board_checking(ny, nx)) {
                    board[ny][nx] = 1;
                    ex = nx;
                    ey = ny;
                    directions.eb(new_dir);
                }
            }
        }
    }
    get_result();
}
