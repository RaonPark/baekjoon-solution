#include <bits/stdc++.h>
using namespace std;

string arr[4];
int K;

void solve(int n, int d) {
    int rotate[4]; memset(rotate, 0, sizeof(rotate));

    if(n == 0) {
        rotate[0] = d;
        rotate[1] = (arr[0][2] == arr[1][6]) ? 0 : -rotate[0];
        rotate[2] = (arr[1][2] == arr[2][6]) ? 0 : -rotate[1];
        rotate[3] = (arr[2][2] == arr[3][6]) ? 0 : -rotate[2]; 
    } else if(n == 1) {
        rotate[1] = d;
        rotate[0] = (arr[0][2] == arr[1][6]) ? 0 : -rotate[1];
        rotate[2] = (arr[1][2] == arr[2][6]) ? 0 : -rotate[1];
        rotate[3] = (arr[2][2] == arr[3][6]) ? 0 : -rotate[2];
    } else if(n == 2) {
        rotate[2] = d;
        rotate[1] = (arr[1][2] == arr[2][6]) ? 0 : -rotate[2];
        rotate[3] = (arr[2][2] == arr[3][6]) ? 0 : -rotate[2];
        rotate[0] = (arr[0][2] == arr[1][6]) ? 0 : -rotate[1];
    } else {
        rotate[3] = d;
        rotate[2] = (arr[2][2] == arr[3][6]) ? 0 : -rotate[3];
        rotate[1] = (arr[1][2] == arr[2][6]) ? 0 : -rotate[2];
        rotate[0] = (arr[0][2] == arr[1][6]) ? 0 : -rotate[1];
    }

    for(int i=0; i<4; i++) {
        if(rotate[i] == -1) {
            string temp = arr[i].substr(1, 7);
            string result(1, arr[i][0]);
            temp += result;
            arr[i] = temp;
        }
        else if(rotate[i] == 1) {
            string temp = arr[i].substr(0, 7);
            string result(1, arr[i][7]);
            result += temp;
            arr[i] = result;
        }
    }
    return ;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<4; i++) cin >> arr[i];

    cin >> K;

    for(int i=0; i<K; i++) {
        int n, d; cin >> n >> d;
        solve(n - 1, d);
    }

    int ret = 0;
    for(int i=0; i<4; i++) {
        if(arr[i][0] == '1') {
            ret += pow(2, i);
        }
    } 
    
    cout << ret << '\n';

    return 0;
}
