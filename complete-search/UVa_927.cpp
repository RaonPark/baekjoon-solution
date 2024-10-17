#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int TC, k, d;

int arr[30];
int poly = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> TC;
    for(int t=0; t<TC; t++) {
        cin >> poly;
        for(int i=0; i<=poly; i++) {
            cin >> arr[i];
        }
        cin >> d >> k;
        
        ll result = 0;
        int prev_sum = 0;
        // K는 최대 100만 그런데 우리가 검사할 것은 d * i이기 때문에 k/d만 검사해도 됨.
        for(int i=1; i<=(k/d); i++) { 
            // 결국에는 최악의 경우 O(n(n+1)/2)의 알고리즘이다.
            // 이는 n(n+1)/2 = 100000이므로, n = 1414이고, 최대 차수가 20이므로 약 30000정도 걸리는 알고리즘이다.
            if(d * i + prev_sum >= k) {
                // 차수는 최대 20이지만 결국에 K를 넘을 때만 계산된다.
                for(int n = 0; n <= poly; n++) { 
                    result += (ll)pow(i, n) * (ll)arr[n];
                }
                break;
            }
            prev_sum += d * i;
        }
        
        cout << result << '\n';
    }
}
