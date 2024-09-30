#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define mp make_pair

int arr[110][110];
int r, c, k;

class Compare {
public:
    bool operator() (ii lp, ii rp) {
        if(lp.second > rp.second)
            return true;
        else if(lp.second == rp.second && lp.first > rp.first)
            return true;
        return false;
    }
};

int R(int sr, int sc) {
    int max_size = -1;
    // 행을 기준으로
    for(int i=0; i<sr; i++) {
        // init
        priority_queue<ii, vector<ii >, Compare> pq;
        vector<ii> v;
        
        for(int j=0; j<sc; j++) {
            if(arr[i][j] == 0) continue;
            bool flag = false;
            for(int m=0; m<(int)v.size(); m++) {
                if(v[m].first == arr[i][j]) {
                    v[m].second++;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                v.emplace_back(mp(arr[i][j], 1));
            }
        }
        
        // 만약 100개를 넘으면 잘라준다.
        int size = min((int)v.size() * 2, 100);
        max_size = max(max_size, size);
        
        for(int m=0; m<(int)v.size(); m++) {
            pq.push(v[m]);
        }
        
        // 실제 배열에 채워준다.
        int j = 0;
        while(!pq.empty()) {
            ii next = pq.top(); pq.pop();
            arr[i][j] = next.first;
            arr[i][j + 1] = next.second;
            j += 2;
        }
        
        // 그 나머지는 0으로 채워준다.
        for(int m=size; m<=100; m++) {
            arr[i][m] = 0;
        }
    }
    
    // 열의 개수를 반환해서 업데이트할 수 있도록 한다. 
    return max_size;
}

int C(int sr, int sc) {
    int max_size = -1;

    for(int j=0; j<sc; j++) {
        priority_queue<ii, vector<ii >, Compare> pq;
        vector<ii> v;
        
        for(int i=0; i<sr; i++) {
            if(arr[i][j] == 0) continue;
            bool flag = false;
            for(int m=0; m<(int)v.size(); m++) {
                if(v[m].first == arr[i][j]) {
                    v[m].second++;
                    flag = true;
                    break;
                }
            }
            if(!flag)
                v.emplace_back(mp(arr[i][j], 1));
        }
        
        int size = min((int)v.size() * 2, 100);
        max_size = max(max_size, size);
        for(int m=0; m<(int)v.size(); m++) {
            pq.push(v[m]);
        }
        
        int i=0;
        while(!pq.empty()) {
            ii next = pq.top(); pq.pop();
            arr[i][j] = next.first;
            arr[i + 1][j] = next.second;
            i += 2;
        }
        
        for(int m=size; m<=100; m++) {
            arr[m][j] = 0;
        }
    }
    
    return max_size;
}

int solution(int sr, int sc) {
    int t = 0; 
    while(t <= 100) {
        if(arr[r-1][c-1] == k) {
            return t;
        }
        if(sr >= sc) {
            sc = R(sr, sc);
            r_c++;
        } else {
            sr = C(sr, sc);
            c_c++;
        }
        
        t++;
    }
    
    return -1;
}

int main(void) {
    scanf("%d %d %d", &r, &c, &k);
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int result = solution(3, 3);
    printf("%d\n", result);
}
