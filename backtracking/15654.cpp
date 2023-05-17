#include <bits/stdc++.h>
using namespace std;

#define MAX 8

int N, M;
vector<int> arr;
vector<bool> check;
vector<int> temp;

void backtracking() {
        if(temp.size() == M) {
                for(int num: temp)
                        printf("%d ", num);
                printf("\n");
        }
        for(int i=0; i<N; i++) {
                if(check[i])
                        continue;
                check[i] = 1;
                temp.emplace_back(arr[i]);
                backtracking();
                check[i] = 0;
                temp.pop_back();
        }
}

int main(void) {
        scanf("%d %d", &N, &M);

        arr.assign(N, 0);
        for(int i=0; i<N; i++) {
                scanf("%d", &arr[i]);
        }

        check.assign(N, 0);
        sort(arr.begin(), arr.end());
        backtracking();
        return 0;
}
