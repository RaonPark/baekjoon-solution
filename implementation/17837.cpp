#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

#define WHITE 0
#define RED 1
#define BLUE 2

typedef struct pieces {
    int r, c;
    int dir;
    int order;
} pieces;

int N, K;
int board[15][15];
int state[15][15][11];
vector<pieces> v;

bool border_checking(int r, int c) {
    return (r > 0 && r <= N && c > 0 && c <= N);
}

int move_backwards(int dir) {
    if(dir == RIGHT)
        return LEFT;
    else if(dir == LEFT)
        return RIGHT;
    else if(dir == UP)
        return DOWN;
    return UP;
}

bool is_four(int r, int c, int nr, int nc, int order) {
    int origin = 0;
    for(int o=0; o<4; o++) {
        if(state[nr][nc][o] == 0)
            break;
        origin++;
    }
    
    int cnt = 0;
    for(int o=order; o<4; o++) {
        if(state[r][c][o] == 0)
            break;
        cnt++;
    }
    
    return ((origin + cnt) >= 4);
}

bool white(int r, int c, int nr, int nc, int order) {
    // 움직일 칸에 이미 있는 말들의 개수를 센다.
    int origin = 0;
    for(int o=0; o<4; o++) {
        if(state[nr][nc][o] == 0)
            break;
        origin++;
    }
    // 현재 있는 칸에 이미 있는 말들의 개수를 센다.
    int cnt = 0;
    for(int o = order; o < 4; o++) {
        if(state[r][c][o] == 0)
            break;
        cnt++;
    }
    
    // 만약 4보다 크면 게임을 종료시킨다.
    if((cnt + origin) >= 4)
        return false;
        
    // 아니라면 현재 있는 칸에 있는 자신보다 위에 있는 말들을 모두 옮긴다.
    for(int o=0; o<cnt; o++) {
        if(state[r][c][order + o] == 0)
            break;
        state[nr][nc][origin+o] = state[r][c][order+o];
        state[r][c][order+o] = 0;
        v[state[nr][nc][origin+o]].order = origin + o;
        v[state[nr][nc][origin+o]].r = nr;
        v[state[nr][nc][origin+o]].c = nc;
    }
    
    return true;
}

bool red(int r, int c, int nr, int nc, int order) {
    // 움직일 칸에 이미 있는 말들의 개수를 센다.
    int origin = 0;
    for(int o=0; o<4; o++) {
        if(state[nr][nc][o] == 0)
            break;
        origin++;
    }
    // 현재 있는 칸에 이미 있는 말들의 개수를 센다.
    stack<int> s;
    int cnt = 0;
    for(int o = order; o < 4; o++) {
        if(state[r][c][o] == 0)
            break;
        cnt++;
        s.push(state[r][c][o]);
        state[r][c][o] = 0;
    }
    
    if((cnt + origin) >= 4)
        return false;
        
    // 아니라면 현재 있는 칸에 있는 자신보다 위에 있는 말들을 모두 옮기는데 반대로 옮긴다.
    int o = 0;
    while(!s.empty()) {
        int node = s.top(); s.pop();
        state[nr][nc][origin+o] = node;
        v[node].order = origin+o;
        v[node].r = nr;
        v[node].c = nc;
        o++;
    }
    
    return true;
}

void print_state() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int cnt = 0;
            for(int o=0; o<K; o++) {
                if(state[i][j][o] == 0)
                    break;
                cnt++;
            }
            printf("%d ", cnt);
        }
        printf("\n");
    }
    printf("\n");
}

int solution() {
    int turns = 1;
    while(turns <= 1000) {
        bool is_continue = true;
        for(int i=1; i<=K; i++) {
            pieces p = v[i];

            int nr = p.r, nc = p.c, ndir = p.dir;
            if(p.dir == RIGHT)
                nc++;
            else if(p.dir == LEFT)
                nc--;
            else if(p.dir == UP)
                nr--;
            else
                nr++;
            
            // if(border_checking(nr, nc) && is_four(p.r, p.c, nr, nc, p.order))
            //     return turns;
            
            if(!border_checking(nr, nc) || board[nr][nc] == BLUE) {
                ndir = move_backwards(ndir);
                
                nr = p.r, nc = p.c;
                if(ndir == RIGHT)
                    nc++;
                else if(ndir == LEFT)
                    nc--;
                else if(ndir == UP)
                    nr--;
                else
                    nr++;
                v[i].dir = ndir;
            }
            
            if(border_checking(nr, nc) && is_four(p.r, p.c, nr, nc, p.order))
                return turns;
            
            // printf("%d %d -> %d %d : dir %d order %d\n", p.r, p.c, nr, nc, ndir, p.order);
            
            if(!border_checking(nr, nc) || board[nr][nc] == BLUE) {
                continue;
            }
            // WHITE
            else if(board[nr][nc] == WHITE) {
                is_continue = white(p.r, p.c, nr, nc, p.order);
            }
            // RED
            else if(board[nr][nc] == RED) {
                is_continue = red(p.r, p.c, nr, nc, p.order);
            }

            // print_state();
            if(!is_continue)
                return turns;
            
            
        }
    
        turns++;
    }
    
    return -1;
}

int main(void) {
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    pieces nullp; nullp.r=-1; nullp.c=-1; nullp.dir=-1; nullp.order=-1;
    v.emplace_back(nullp);
    for(int i=0; i<K; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        pieces p;
        p.r =a; p.c=b; p.dir=c; p.order=0;
        state[a][b][0] = i + 1;
        v.emplace_back(p);
    }
    
    int result = solution();
    printf("%d\n", result);
    return 0;
}
