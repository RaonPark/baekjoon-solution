#include <bits/stdc++.h>
using namespace std;

#define END 40
#define eb emplace_back
#define FIRST 0
#define TEN 1
#define TWENTY 2
#define THIRTY 3
#define TWENTYFIVE 4
int N = 10;
int dice[10];
map<int, vector<int>> board;
vector<vector<int> > route;
int ans = -1;
pair<int, int> status[4];

void init_board() {
    route.assign(5, vector<int>());
    // 짝수끼리는 이어져있다.
    for(int i=0; i<=40; i+=2) {
        route[FIRST].eb(i);
    }
    
    // 10 - 13 - 16 - 19 - 25
    for(int i=10; i<=19; i+=3) {
        route[TEN].eb(i);
    }
    route[TEN].eb(25);
    
    // 20 - 22 - 24 - 25
    for(int i=20; i<=24; i+=2) {
        route[TWENTY].eb(i);
    }
    route[TWENTY].eb(25);
    
    // 30 - 28 - 27 - 26 - 25
    route[THIRTY].eb(30);
    for(int i=28; i>=25; i--) {
        route[THIRTY].eb(i);
    }
    
    // 25 - 30 - 35 - 40
    for(int i=25; i<=40; i+=5) {
        route[TWENTYFIVE].eb(i);
    }
    
    for(int i=0; i<4; i++) {
        status[i] = make_pair(0, 0);
    }
}

pair<int, int> find_path(int now, int r, int d) {
    int next = now;
    int iter = 0, idx = r, jdx = 0;
    bool transfer = false;
    
    for(jdx=0; jdx<(int)route[idx].size(); jdx++) {
        if(route[idx][jdx] == now) {
            break;
        }
    }

    while(iter < d) {
        if(iter < d && next == 40) {
            return make_pair(-1, 0);
        }
        // 나머지 노선 중 환승을 아직 안했는데 25에 도달한 경우
        if(!transfer && next == 25 && iter != 0) {
            transfer = true;
            idx = TWENTYFIVE;
            jdx = 0;
        }
        
        next = route[idx][++jdx];
        iter++;
    }
    
    // 10부터 시작하는 경우는
    if(next == 10) {
        idx = TEN;
    }
    // 20부터 시작하는 경우
    else if(next == 20) {
        idx = TWENTY;
    }
    // 30부터 시작하는 경우
    else if(idx != TWENTYFIVE && next == 30) {
        idx = THIRTY;
    }
    // 25부터 시작하는 경우
    else if(next == 25) {
        idx = TWENTYFIVE;
    }
    
    return make_pair(idx, next);
}

int twos[6] = {30, 28, 26, 16, 24, 22};

bool is_dup(int idx, int num) {
    for(int i=0; i<4; i++) {
        if(num == 25 || num == 40)
            if(status[i].second == num)
                return true;
        if(status[i].second == num && status[i].first == idx) {
            return true;
        }
    }
    return false;
}

void backtracking(int turn, int sum) {
    if(turn == N) {
        ans = max(ans, sum);
        return;
    }
    
    for(int i=0; i<4; i++) {
        pair<int, int> now = status[i];
        if(now.first == -1)
            continue;
        pair<int, int> next = find_path(now.second, now.first, dice[turn]);
        if(next.first != -1 && is_dup(next.first, next.second)) {
            continue;
        }
        status[i] = next;
        backtracking(turn + 1, sum + next.second);
        status[i] = now;
    }
}

int main() {
    for(int i=0; i<N; i++) {
        scanf("%d", &dice[i]);
    }
    
    init_board();
    backtracking(0, 0);

    printf("%d\n", ans);
}
