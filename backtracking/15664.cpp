#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[8], result[8];
bool check[8] = { false };

void backtracking(int cnt, int prev) {
	if(cnt == M) {
		for(int i=0; i<M; i++)
			printf("%d ", result[i]);
		printf("\n");
		return;
	}

	int last = 0;
	for(int i=0; i<N; i++) {
		if(!check[i] && arr[i] != last && prev <= arr[i]) {
			result[cnt] = arr[i];
			last = result[cnt];
			check[i] = true;
			backtracking(cnt + 1, last);
			check[i] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+N);
	
	backtracking(0, 0);
	
	return 0;
}
