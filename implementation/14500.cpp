#include <bits/stdc++.h>
using namespace std;

int N, M, board[501][501];

int first() {
	int max_value = -1;
	
	for(int i=0; i<N; i++) {
		int sum1 = 0;
		for(int j=0; j<M-3; j++) {
			sum1 = board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3];
			max_value = max(max_value, sum1);
		}
	}
	
	for(int i=0; i<N-3; i++) {
		int sum1 = 0;
		for(int j=0; j<M; j++) {
			sum1 = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j];
			max_value = max(max_value, sum1);
		}
	}
	
	return max_value;
}

int second() {
	int max_value = -1;
	
	for(int i=0; i<N-1; i++) {
		int sum1 = 0;
		for(int j=0; j<M-1; j++) {
			sum1 = board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
			max_value = max(max_value, sum1);
		}
	}
	
	return max_value;
}

int max(int a, int b, int c, int d, int e) {
	if(a >= b && a >= c && a >= d && a >= e) return a;
	else if(b >= a && b >= c && b >= d && b >= e) return b;
	else if(c >= a && c >= b && c >= d && c >= e) return c;
	else if(d >= a && d >= b && d >= c && d >= e) return d;
	return e;
}

int third() {
	int max_value = -1;
	// 3*2 배열 4가지의 경우의 수
	for(int i=0; i<N-2; i++) {
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		for(int j=0; j<M-1; j++) {
			sum1 = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+2][j+1];
			sum2 = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+2][j+1];
			sum3 = board[i][j+1] + board[i+1][j+1] + board[i+2][j+1] + board[i+2][j];
			sum4 = board[i][j] + board[i][j+1] + board[i+1][j] + board[i+2][j];
			max_value = max(max_value, sum1, sum2, sum3, sum4);
		}
	}
	
	// 2*3 배열 4가지 경우의 수
	for(int i=0; i<N-1; i++) {
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
		for(int j=0; j<M-2; j++) {
			sum1 = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j];
			sum2 = board[i][j+2] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2];
			sum3 = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+2];
			sum4 = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2];
			max_value = max(max_value, sum1, sum2, sum3, sum4);
		}
	}
	
	return max_value;
}

int max(int a, int b, int c) {
	if(a >= b && a >= c) return a;
	else if(b >= a && b >= c) return b;
	else return c;
}

int fourth() {
	int max_value = -1;
	
	// 3*2 크기 2가지
	for(int i=0; i<N-2; i++) {
		int sum1 = 0, sum2 = 0;
		for(int j=0; j<M-1; j++) {
			sum1 = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1];
			sum2 = board[i][j+1] + board[i+1][j] + board[i+1][j+1] + board[i+2][j];
			max_value = max(max_value, sum1, sum2);
		}
	}
	
	// 2*3 크기 2가지
	for(int i=0; i<N-1; i++) {
		int sum1 = 0, sum2 = 0;
		for(int j=0; j<M-2; j++) {
			sum1 = board[i][j+1] + board[i][j+2] + board[i+1][j] + board[i+1][j+1];
			sum2 = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2];
			max_value = max(max_value, sum1, sum2);
		}
	}
	
	return max_value;
}

int fifth() {
	int max_value = -1;
	
	// 2*3 크기 2가지
	for(int i=0; i<N-1; i++) {
		int sum1 = 0, sum2 = 0;
		for(int j=0; j<M-2; j++) {
			sum1 = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1];
			sum2 = board[i][j+1] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2];
			max_value = max(max_value, sum1, sum2);
		}
	}
	
	// 3*2 크기 2가지
	for(int i=0; i<N-2; i++) {
		int sum1 = 0, sum2 = 0;
		for(int j=0; j<M-1; j++) {
			sum1 = board[i+1][j] + board[i][j+1] + board[i+1][j+1] + board[i+2][j+1];
			sum2 = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+1][j+1];
			max_value = max(max_value, sum1, sum2);
		}
	}
	return max_value;
}

int solve() {
	int result = max(first(), second(), third(), fourth(), fifth());
	
	return result;
}

int main() {
	memset(board, 0, sizeof(board));
	
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
		int k; scanf("%d", &k); board[i][j] = k;
	}
	
	int result = solve();
	printf("%d\n", result);
	return 0;
}
