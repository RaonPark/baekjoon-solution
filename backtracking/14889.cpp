#include <bits/stdc++.h>
using namespace std;

#define MAX 25

int N;
int arr[MAX][MAX];
bool check[MAX];
int ans = 987654321;

void backtracking(int idx, int cnt) {
        if(cnt == N / 2) {
                int start = 0, link = 0;
                for(int i=0; i<N; i++) {
                        for(int j=0; j<N; j++) {
                                if(check[i] && check[j]) start += arr[i][j];
                                if(!check[i] && !check[j]) link += arr[i][j];
                        }
                }

                ans = min(abs(start - link), ans);
                return ;
        }

        for(int i=idx; i<N; i++) {
                check[i] = true;
                backtracking(i + 1, cnt + 1);
                check[i] = false;
        }
}

int main(void) {
        scanf("%d", &N);

        for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                        scanf("%d", &arr[i][j]);
        
        backtracking(0, 0);

        printf("%d\n", ans);
}
