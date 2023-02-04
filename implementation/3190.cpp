#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K, L;
int board[101][101];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
queue<pair<int, int> > q;
vector<pair<int, char> > v;

int solve() {
    int result = 0, idx = 0, i = 0;
    pair<int, int> head = make_pair(1, 1);
    pair<int, int> tail = make_pair(1, 1);
    q.emplace(make_pair(1, 1));
    int pHead1, pHead2;

    while(1) {
        // 벽과 부딪히면 게임이 끝난다.
        if(head.first < 1 || head.first > N || head.second > N || head.second < 1) {
            break;
        }

        // 1초를 더한다.
        result += 1;

        // 움직이는 방향에 따라 head의 x와 y를 증가시킨다.
        // 경로를 추가한다.
        head.first += dx[i];
        head.second += dy[i];
        // 만약에 head가 몸과 겹친다면 탈출
        if(board[head.first][head.second] & 2) {
        	break;
        }
        q.emplace(head);

        // 만약에 그 자리에 사과가 없으면 tail을 방향으로 증가시킨다.
        if(!(board[head.first][head.second] & 0x1)) {
        	board[tail.first][tail.second] = 0;
        	q.pop();
            pair<int, int> t = q.front();
            tail = t;
        }
        
        //printf("h: %d %d: %d\n", head.first, head.second, board[head.first][head.second]);
    	//printf("t: %d %d: %d\n", tail.first, tail.second, board[tail.first][tail.second]);
        
        // 사과를 먹었다면 0을 대입한다.
        // 큐에 경로를 추가한다.
        if(board[head.first][head.second] & 1) {
        	board[head.first][head.second] = 0;
        }
        // head를 증가시켜야한다.
        board[head.first][head.second] |= 2;

        // 만약 그 시간초에 방향을 바꿔야하면 바꾼다.
        if(idx < L && v[idx].first == result) {
            if(v[idx].second == 'L') {
                i -= 1;
                if(i < 0) {
                    i = 3;
                }
            } else {
                i += 1;
                if(i > 3) {
                    i = 0;
                }
            }
            idx++;
        }
    }
    return result;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &K);

    memset(board, 0, sizeof(board));

    for(int i=0; i<K; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        board[a][b] = 1;
    }

    scanf("%d", &L);
    for(int i=0; i<L; i++) {
        int x; char c;
        scanf("%d %c", &x, &c);
        v.push_back(make_pair(x, c));
    }

    int result = solve();

    printf("%d\n", result);
    return 0;
}
