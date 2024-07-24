#include <bits/stdc++.h>

using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int N, M;
int board[10][10];
int original[10][10];
vector<pair<int, int> > v;

void print_board() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int blind_spot() {
    int sum = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            sum += ((board[i][j] == 0) ? 1 : 0);
        }
    }
    return sum;
}

void down(int x, int y, int flag) {
    for(int i=x + 1; i < N; i++) {
        if(board[i][y] == 6)
            break;
        else {
            // cleanup
            if(flag == 1 && board[i][y] % 9 == 0)
                board[i][y] -= (board[i][y] >= 0 ? 9 : 0);
            else if(flag == 0 && board[i][y] % 9 == 0)
                board[i][y] += 9;
        }
    }
}

void up(int x, int y, int flag) {
    for(int i=x - 1; i >= 0; i--) {
        if(board[i][y] == 6)
            break;
        else
            if(flag == 1 && board[i][y] % 9 == 0)
                board[i][y] -= (board[i][y] >= 0 ? 9 : 0);
            else if(flag == 0 && board[i][y] % 9 == 0)
                board[i][y] += 9;
    }
}

void right(int x, int y, int flag) {
    for(int j=y + 1; j < M; j++) {
        if(board[x][j] == 6)
            break;
        else
            if(flag == 1 && board[x][j] % 9 == 0)
                board[x][j] -= (board[x][j] >= 0 ? 9 : 0);
            else if(flag == 0 && board[x][j] % 9 == 0)
                board[x][j] += 9;
    }
}

void left(int x, int y, int flag) {
    for(int j=y - 1; j >= 0; j--) {
        if(board[x][j] == 6)
            break;
        else
            if(flag == 1 && board[x][j] % 9 == 0)
                board[x][j] -= (board[x][j] >= 0 ? 9 : 0);
            else if(flag == 0 && board[x][j] % 9 == 0)
                board[x][j] += 9;
    }
}

// dir = 0 이면 오른쪽, 1이면 아래쪽, 2이면 왼쪽 3이면 위쪽
void simulate(int cctv, int dir, int x, int y, int flag) {
    // 1이면 한쪽 방향만 쭉 볼 수 있다.
    if(cctv == 1) {
        if(dir == RIGHT) {
            right(x, y, flag);
        }
        else if(dir == DOWN) {
            down(x, y, flag);
        }
        else if(dir == LEFT) {
            left(x, y, flag);
        }
        else {
            up(x, y, flag);
        }
    }
    // 2이면 양쪽방향으로 감시한다.
    else if(cctv == 2) {
        if(dir == RIGHT || dir == LEFT) {
            right(x, y, flag);
            left(x, y, flag);
        }
        else {
            down(x, y, flag);
            up(x, y, flag);
        }
    }
    // 3이면 직각방향으로 감시한다.
    else if(cctv == 3) {
        if(dir == RIGHT) {
            right(x, y, flag);
            up(x, y, flag);
        }
        else if(dir == DOWN) {
            down(x, y, flag);
            right(x, y, flag);
        }
        else if(dir == LEFT) {
            left(x, y, flag);
            down(x, y, flag);
        }
        else {
            up(x, y, flag);
            left(x, y, flag);
        }
    }
    // 4번은 세방향향
    else if(cctv == 4) {
        if(dir == RIGHT) {
            right(x, y, flag);
            left(x, y, flag);
            up(x, y, flag);
        }
        else if(dir == LEFT) {
            left(x, y, flag);
            down(x, y, flag);
            right(x, y, flag);
        }
        else if(dir == DOWN) {
            down(x, y, flag);
            right(x, y, flag);
            up(x, y, flag);
        }
        else {
            down(x, y, flag);
            up(x, y, flag);
            left(x, y, flag);
        }
    }
    // 5번은 전방향
    else {
        up(x, y, flag);
        right(x, y, flag);
        left(x, y, flag);
        down(x, y, flag);
    }
}

int solve(int cctv) {
    int result = 99999;
    
    if(cctv == (int)v.size()) {
        return (result = blind_spot());
    }
    
    for(int i=0; i<4; i++) {
        int x = v[cctv].first, y = v[cctv].second;
        simulate(board[x][y], i, x, y, 0);
        
        result = min(result, solve(cctv + 1));
        simulate(board[x][y], i, x, y, 1);
    }
    
    return result;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d", &board[i][j]);
            if(board[i][j] != 0 && board[i][j] != 6)
                v.emplace_back(make_pair(i, j));
        }
    }
    
    // 계속해서 반복하는데
    // 문제는 cctv를 어떻게 정할 것인가?
    int result = solve(0);
    
    printf("%d\n", result);
}
