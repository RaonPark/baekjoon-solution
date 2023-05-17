#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<vector<int> > result;

void backtracking(int idx, vector<int> v) {
        if((int)v.size() == M) {
                result.emplace_back(v);
                return;
        }
        if(idx == N)
                return;

        backtracking(idx + 1, v);
        v.emplace_back(arr[idx]);
        backtracking(idx + 1, v);
}

int main(void) {
        scanf("%d %d", &N, &M);

        for(int i=0; i<N; i++) {
                int k; scanf("%d", &k);
                arr.emplace_back(k);
        }

        sort(arr.begin(), arr.end());

        backtracking(0, vector<int>());

        sort(result.begin(), result.end());

        for(auto v: result) {
                for(int num: v) {
                        printf("%d ", num);
                }
                printf("\n");
        }

        return 0;
}
