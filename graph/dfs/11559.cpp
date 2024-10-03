#include <bits/stdc++.h>
using namespace std;

char board[12][6];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool visited[12][6];

bool border_checking(int r, int c) {
    return (r>=0 && r<12 && c>=0 && c<6);
}

void dfs(int r, int c, char color) {
    visited[r][c] = true;
    
    for(int i=0; i<4; i++) {
        int nr = r+dr[i], nc = c+dc[i];
        if(border_checking(nr, nc) && board[nr][nc] == color && !visited[nr][nc]) {
            dfs(nr, nc, color);
        }
    }
}

void move() {
    for(int c=0; c<6; c++) {
        int flag = 0;
        vector<char> v;
        
        for(int r=0; r<12; r++) {
            if(board[r][c] != '.') {
                v.emplace_back(board[r][c]);
                board[r][c] = '.';
            }
        }
        
        int size = (int)v.size();
        if(size > 0) {
            for(int i=0; i<size; i++) {
                board[11-i][c] = v[size - 1 - i];
            }
        }
    }
}

bool is_four() {
    int cnt = 0;
    for(int r=0; r<12; r++) {
        for(int c=0; c<6; c++) {
            if(visited[r][c]) {
                cnt++;
            }
        }
    }
    
    return cnt >= 4;
}

int solution() {
    int result = 0;
    while(true) {
        bool flag = false;
        
        for(int r=0; r<12; r++) {
            for(int c=0; c<6; c++) {
                memset(visited, false, sizeof(visited));
                if(board[r][c] == '.') continue;
                // 1. 단 dfs를 돌려서 뭉쳐있는 뿌요가 있는지 확인한다.
                dfs(r, c, board[r][c]);
                // 2. 4개 이상이라면 모든 뿌요를 터뜨리고 '.'으로 바꾼다.
                if(is_four()) {
                    flag = true;
                    for(int vr=0; vr<12; vr++) {
                        for(int vc=0; vc<6; vc++) {
                            if(visited[vr][vc]) {
                                board[vr][vc] = '.';
                            }
                        }
                    }
                }
            }
        }
        // 3. 터뜨린 뿌요 위에 뿌요가 있다면 이동시킨다.
        move();

        // 한번이라도 연쇄가 일어나면 게임이 끝난게 아니다.
        if(!flag) {
            break;
        }
        result++;
    }
    
    return result;
}

int main() {
    for(int r=0; r<12; r++) {
        char lines[13];
        scanf("%s", &lines);
        for(int i=0, c=0; lines[i] != '\0'; i++) {
            if(lines[i] != ' ') {
                board[r][c] = lines[i];
                c++;
            }
        }
    }
    
    int result = solution();
    printf("%d\n", result);
}
