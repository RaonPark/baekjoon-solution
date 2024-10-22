#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int x[51], d[51], k[51];
int board[51][51];
map<int, set<int> > adjs;
bool flag = false;

#define CLOCK 0
#define COUNTER 1
#define BLANK 0
#define ep emplace

// 1 1 2 3 -> 시계방향이면 3 1 1 2
// 1 1 2 3 -> 반시계방향이면 1 2 3 1
void spin(int t) {
    int xt = x[t], dt = d[t], kt = k[t];
    int re = 0;
    while(re < kt) {
        if(dt == CLOCK) {
            for(int i=xt; i<=N; i+=xt) {
                int last = board[i][M];
                for(int j=M-1; j >= 1; j--) {
                    board[i][j+1] = board[i][j];
                }
                board[i][1] = last;
            }
        } else {
            for(int i=xt; i<=N; i+=xt) {
                int first = board[i][1];
                for(int j=1; j<M; j++) {
                    board[i][j] = board[i][j+1];
                }
                board[i][M] = first;
            }
        }
        re++;
    }
}

void find_adjs() {
    for(int xt=1; xt<=N; xt++) {
        // (i,1)은 (i,2)와 인접하다.
        if(board[xt][1] != BLANK && board[xt][1] == board[xt][2]) {
            adjs[xt].ep(2);
            adjs[xt].ep(1);
            flag = true;
        }
        // (i,1)은 (i,M)과 인접하다.
        if(board[xt][1] != BLANK && board[xt][1] == board[xt][M]) {
            adjs[xt].ep(1);
            adjs[xt].ep(M);
            flag = true;
        }
        // (i,M)은 (i, M-1), (i, 1)과 인접하다.
        if(board[xt][M] != BLANK && board[xt][M-1] == board[xt][M]) {
            adjs[xt].ep(M-1);
            adjs[xt].ep(M);
            flag = true;
        }
        if(board[xt][M] != BLANK && board[xt][M] == board[xt][1]) {
            adjs[xt].ep(M);
            adjs[xt].ep(1);
            flag = true;
        }
        // 2 <= j < M인 j에 대해 (i, j)는 (i, j-1), (i, j+1)과 인접하다.
        for(int j=2; j<M; j++) {
            if(board[xt][j] != BLANK && board[xt][j] == board[xt][j-1]) {
                adjs[xt].ep(j-1);
                adjs[xt].ep(j);
                flag = true;
            }
            if(board[xt][j] != BLANK && board[xt][j] == board[xt][j+1]) {
                adjs[xt].ep(j);
                adjs[xt].ep(j+1);
                flag = true;
            }
        }
        
        for(int j=1; j<=M; j++) {
            // (1, j)는 (2, j)와 인접하다.
            if(xt == 1 && board[1][j] != BLANK && board[1][j] == board[2][j]) {
                adjs[1].ep(j);
                adjs[2].ep(j);
                flag = true;
            } 
            // (N, j)는 (N-1, j)와 인접하다.
            if(xt == N && board[N][j] != BLANK && board[N-1][j] == board[N][j]) {
                adjs[N-1].ep(j);
                adjs[N].ep(j);
                flag = true;
            }
            // 2 <= i <= N-1에 대해 (i, j)는 (i-1, j), (i+1, j)와 인접하다.
            if(xt >= 2 && xt <= N-1) {
                if(board[xt][j] != BLANK && board[xt][j] == board[xt-1][j]) {
                    adjs[xt].ep(j);
                    adjs[xt-1].ep(j);
                    flag = true;
                }
                if(board[xt][j] != BLANK && board[xt][j] == board[xt+1][j]) {
                    adjs[xt].ep(j);
                    adjs[xt+1].ep(j);
                    flag = true;
                }
            }
        }
    }
}

void delete_adj() {
    for(int i=1; i<=N; i++) {
        for(auto j: adjs[i]) {
            board[i][j] = BLANK;
        }
    }
}

void change_val() {
    // 평균을 구한다.
    double avg = 0, sum = 0, non_zero = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(board[i][j] != BLANK) {
                sum += (double)board[i][j];
                non_zero++;
            }
        }
    }
    
    avg = sum / (double)non_zero;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            // 평균보다 크다면 1을 빼고 평균보다 작다면 1을 더한다.
            if(board[i][j] != BLANK && (double)board[i][j] > avg) {
                board[i][j]--;
            } else if(board[i][j] != BLANK && (double)board[i][j] < avg) {
                board[i][j]++;
            }
        }
    }
}

bool is_left() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(board[i][j] != BLANK)
                return true;
        }
    }
    return false;
}

void print_board() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

void solution() {
    for(int t=0; t<T; t++) {
        adjs.clear();
        flag = false;
        // 돌리고
        spin(t);
        // 인접한 곳을 찾고
        find_adjs();
        // 같은 수가 있다면 없애고 없다면 평균보다 큰 수는 +1 작은 수는 -1 한다.
        if(flag) {
            delete_adj();
        } else {
            if(!is_left())
                return;
            change_val();
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &T);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    for(int i=0; i<T; i++) {
        scanf("%d %d %d", &x[i], &d[i], &k[i]);
    }
    
    solution();
    
    int sum = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            sum += board[i][j];
        }
    }
    
    printf("%d\n", sum);
}
