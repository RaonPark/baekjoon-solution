#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr;
vector<int> result;

void backtracking(int cnt) {
        if(M == cnt) {
                for(int i=0; i<M; i++)
                        printf("%d ", result[i]);
                printf("\n");
        } else {
                for(int i=0; i<N; i++) {
                        if(!result.empty()) {
                                if(arr[i] >= result.back())
                                        result.emplace_back(arr[i]);
                                else continue;
                        } else {
                                result.emplace_back(arr[i]);
                        }

                        backtracking(cnt + 1);
                        result.pop_back();
                }
        }
}

int main(void) {
        scanf("%d %d", &N, &M);

        for(int i=0; i<N; i++) {
                int k; scanf("%d", &k); arr.emplace_back(k);
        }

        sort(arr.begin(), arr.end());
        backtracking(0);

        return 0;
}
