#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[7], result[7];
bool check[7] = { false };

void backtracking(int cnt) {
	if(cnt == M) {
		for(int i=0; i<M; i++)
			printf("%d ", result[i]);
		printf("\n");
		return;
	}
	
	int last = 0;
	for(int i=0; i<N; i++) {
		if(last != arr[i]) {
			result[cnt] = arr[i];
			last = result[cnt];
			backtracking(cnt + 1);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+N);
	
	backtracking(0);
	
	return 0;
}
