#include <bits/stdc++.h>
using namespace std;

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4

int north = 5;
int east = 3;
int upper = 1;

int N, M, x, y, K;
int board[21][21];
int dice[7] = {0, 0, 0, 0, 0, 0, 0};
// 동 서 북 남
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 북쪽으로 이동하면, 동서는 바뀌지 않지만 북남은 바뀐다.
// 동쪽으로 이동하면, 북남은 바뀌지 않지만 동서는 바뀐다.

bool is_boundary(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int main() {
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	for(int i=0; i<K; i++) {
		int move; scanf("%d", &move);
		
		int nx = x + dx[move - 1], ny = y + dy[move - 1];
		
		
		
		if(!is_boundary(nx, ny)) {
			continue;
		}

		if(move == EAST) {
			int new_upper = 7 - east;
			int new_east = upper;
			upper = new_upper;
			east = new_east;
		}
		else if(move == WEST) {
			int new_upper = east;
			int new_east = 7 - upper;
			upper = new_upper;
			east = new_east;
		}
		else if(move == SOUTH) {
			int new_upper = north;
			int new_north = 7 - upper;
			upper = new_upper;
			north = new_north;
		}
		else if(move == NORTH) {
			int new_upper = 7 - north;
			int new_north = upper;
			upper = new_upper;
			north = new_north;
		}
		
		// 바닥면이 칸에 복사된다.
		if(board[nx][ny] == 0) {
			board[nx][ny] = dice[7 - upper];
		} else {
			dice[7 - upper] = board[nx][ny];
			board[nx][ny] = 0;
		}
		
		printf("%d\n", dice[upper]);
		
		x = nx;
		y = ny;
	}
	
	return 0;
}
