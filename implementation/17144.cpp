#include <bits/stdc++.h>
using namespace std;

typedef struct purify {
    int r, c;  
} purify;

int R, C, T;
int arr[51][51];
purify u, l;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dust() {
    int result = 0;
    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            if(arr[r][c] != -1) {
                result += arr[r][c];
            }
        }
    }
    
    return result;
}

bool border_checking(int r, int c) {
    return (r < R && r >= 0 && c < C && c >= 0);
}

void upper();
void lower();

void print_arr() {
    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            printf("%d ",arr[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int cnt_arr[51][51];
int add_arr[51][51];

void solution() {
    int t = 0;
    while(t < T) {
        memset(add_arr, 0, sizeof(add_arr));
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                cnt_arr[r][c] = 0;
                for(int i=0; i<4; i++) {
                    if(border_checking(r + dr[i], c + dc[i])) {
                        int nr = r + dr[i], nc = c + dc[i];
                        // 개수를 카운팅한다.
                        if(arr[nr][nc] != -1) {
                            add_arr[nr][nc] += (int)(arr[r][c] / 5);
                            cnt_arr[r][c]++;
                        }
                    }
                }
            }
        }
        
        for(int r=0; r<R; r++) {
            for(int c=0; c<C; c++) {
                if(arr[r][c] == -1)
                    continue;
                
                arr[r][c] = add_arr[r][c] + arr[r][c] - (arr[r][c] / 5) * cnt_arr[r][c];
            }
        }
        
        upper();
        lower();

        t++;
    }
}

void upper() {
    
    //left
    for(int r = u.r - 1; r > 0; r--) {
        arr[r][0] = arr[r-1][0];
    }
    
    arr[0][0] = arr[0][1];
    
    // up
    for(int c = 1; c < C-1; c++) {
        arr[0][c] = arr[0][c+1];
    }
    
    arr[0][C-1] = arr[1][C-1];
    
    // right
    for(int r=1; r < u.r; r++) {
        arr[r][C-1] = arr[r+1][C-1];
    }
    
    arr[u.r][C-1] = arr[u.r][C-2];
    
    // bottom
    for(int c=C-2; c>0; c--) {
        if(arr[u.r][c-1] == -1) arr[u.r][c] = 0;
        else arr[u.r][c] = arr[u.r][c-1];
    }
}

void lower() {
    // left
    for(int r=l.r+1; r<R; r++) {
        arr[r][l.c] = arr[r+1][l.c];
    }
    
    arr[R-1][l.c] = arr[R-1][l.c+1];
    
    // bottom
    for(int c=l.c; c<C; c++) {
        arr[R-1][c] = arr[R-1][c+1];
    }
    
    arr[R-1][C-1] = arr[R-2][C-1];
    
    // right
    for(int r=R-2; r>l.r; r--) {
        arr[r][C-1] = arr[r-1][C-1];
    }
    
    arr[l.r][C-1] = arr[l.r][C-2];
    
    // up
    for(int c=C-2; c>l.c; c--) {
        if(arr[l.r][c-1] == -1) arr[l.r][c] = 0;
        else arr[l.r][c] = arr[l.r][c-1];
    }
}

int main() {
    scanf("%d %d %d", &R, &C, &T);
    
    bool flag = false;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == -1) {
                if(!flag) {
                    u.r = i;
                    u.c = j;
                    flag = true;
                } else {
                    l.r = i;
                    l.c = j;
                }
            }
        }
    }
    
    solution();
    int result = dust();
    printf("%d\n", result);
}
