#include <bits/stdc++.h>

#define MAX 20
int N;
int S;
int arr[MAX];
int result = 0;

void backtracking(int idx, int num) {
        if(idx == N) return;
        if(num + arr[idx] == S) result++;

	backtracking(idx+1, num);
	backtracking(idx+1, num + arr[idx]);
}

int main(void) {
        scanf("%d %d", &N, &S);

        for(int i=0; i<N; i++) {
                scanf("%d", &arr[i]);
        }

        backtracking(0, 0);

        printf("%d\n", result);

        return 0;
}
