#include <bits/stdc++.h>
using namespace std;

int N, L;
int arr[101][101];
int check[101];

int solve(int idx) {
    int row_prev = arr[idx][0], column_prev = arr[0][idx];
    int in_row = 0, in_column = 0;
    bool row_flag = true, column_flag = true;
    bool row_lower = false, column_lower = false;

    for(int i=0; i<N; i++) {
        if(row_flag) {
            if(abs(row_prev - arr[idx][i]) >= 2) {
                row_flag = false;
            } else if(row_prev == arr[idx][i]) {
                in_row++;
            } else if(row_prev < arr[idx][i]) {
                if(in_row >= L) {
                    in_row = 1;
                    row_prev = arr[idx][i];
                }
                else {
                    row_flag = false;
                }
            } else { // 작아지는 경우
                // 작아졌는데 이미 row_lower가 열려있으면 false
                if(row_lower) {
                    row_flag = false;
                }
                in_row = 1;
                row_lower = true;
                row_prev = arr[idx][i];
            }

            // 끝날때 검사
            if(row_lower && in_row >= L) {
                in_row = 0;
                row_lower = false;
            }
        }

        if(column_flag) {
            if(abs(column_prev - arr[i][idx]) >= 2) {
                column_flag = false;
            } else if(column_prev == arr[i][idx]) {
                in_column++;
            } else if(column_prev < arr[i][idx]) {
                if(in_column >= L) {
                    in_column = 1;
                    column_prev = arr[i][idx];
                } else {
                    column_flag = false;
                }
            } else { // 큰 경우는 
                if(column_lower) {
                    column_flag = false;
                }
                in_column = 1;
                column_lower = true;
                column_prev = arr[i][idx];  
            }

            if(column_lower && in_column >= L) {
                in_column = 0;
                column_lower = false;
            }
        }
    }

    // 끝날때 다시 한 번 검사
    if(row_lower && in_row < L) {
        row_flag = false;
    }
    if(column_lower && in_column < L) {
        column_flag = false;
    }

    return (int)row_flag + (int)column_flag; 
}

int main(void) {
    scanf("%d %d", &N, &L);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int result = 0;
    for(int i=0; i<N; i++) {
        result += solve(i);
    }

    printf("%d\n", result);

    return 0;
}
