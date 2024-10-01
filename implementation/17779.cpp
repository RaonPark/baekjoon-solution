#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define mp make_pair

int N;
int area[25][25];
vector<ii > v;

int solution(int x, int y, int d1, int d2) {
    int divide[25][25];
    memset(divide, 0, sizeof(divide));
    
    for(int d=0; d<=d1; d++) {
        divide[x+d][y-d] = 5;
        divide[x+d2+d][y+d2-d] = 5;
    }
    
    for(int d=0; d<=d2; d++) {
        divide[x+d][y+d] = 5;
        divide[x+d1+d][y-d1+d] = 5;
    }
    
    for(int r=1; r<=N; r++) {
        bool flag = false;
        int lr[2] = {-1, -1};
        for(int c=1; c<=N; c++) {
            if(divide[r][c] == 5) {
                if(flag) {
                    lr[1] = c;
                    flag = false;
                } else {
                    lr[0] = c;
                    flag = true;
                }
            }
        }
        if(!flag) {
            for(int nc = lr[0]; nc <= lr[1]; nc++) {
                divide[r][nc] = 5;
            }
        }
    }
    
    // 1
    for(int r=1; r<x+d1; r++) {
        for(int c=1; c<=y; c++) {
            if(divide[r][c] == 0) {
                divide[r][c] = 1;
            }
        }
    }
    
    // 2
    for(int r=1; r<=x+d2; r++) {
        for(int c=y+1; c<=N; c++) {
            if(divide[r][c] == 0)
                divide[r][c] = 2;
        }
    }
    
    // 3
    for(int r=x+d1; r<=N; r++) {
        for(int c=1; c<y-d1+d2; c++)
            if(divide[r][c] == 0)
                divide[r][c] = 3;
    }
    
    // 4
    for(int r=x+d2+1; r<=N; r++) {
        for(int c=y-d1+d2; c<=N; c++) {
            if(divide[r][c] == 0)
                divide[r][c] = 4;
        }
    }
    
    int elec[6];
    memset(elec, 0, sizeof(elec));
    
    for(int r=1; r<=N; r++) {
        for(int c=1; c<=N; c++) {
            elec[divide[r][c]] += area[r][c];
        }
    }
    
    int max_val = -1, min_val = 987654321;
    for(int i=1; i<=5; i++) {
        min_val = min(min_val, elec[i]);
        max_val = max(max_val, elec[i]);
    }
    
    return max_val - min_val;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++)
            scanf("%d", &area[i][j]);
    }
    
    for(int x=1; x<=N-2; x++) {
        for(int y=2; y<=N-1; y++) {
            v.emplace_back(mp(x, y));
        }
    }
    
    int min_val = 987654321;
    for(int i=0; i<(int)v.size(); i++) {
        int x = v[i].first, y = v[i].second;
        
        for(int d1 = 1; d1 <= N-x; d1++) {
            if(y-d1 < 1) continue;
            for(int d2 = 1; d2 <= N-x; d2++) {
                if(y+d2 > N) continue;
                if(x + d1 + d2 > N) continue;
                int result = solution(x, y, d1, d2);
                min_val = min(min_val, result);
            }
        }
    }
    
    printf("%d\n", min_val);
}
