#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
ll C, K;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll x, y;
// 확장 유클리드 알고리즘
void ext_euclid(ll a, ll b) {
	if(b == 0) { x = 1; y = 0; return; }
	ext_euclid(b, a%b);
	ll x1 = y;
	ll y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> K >> C;

        if(K == 1) {
            if(C == 1) cout<<"2\n";
            else cout << "1\n"; }
        else (C == 1) {
            if(K+1 <= 1e9) cout << K+1 << '\n';
            else cout << "IMPOSSIBLE\n"; }
        else if(gcd(K, C) != 1) cout << "IMPOSSIBLE\n";
        else {
            ext_euclid(K, C);
            // 역원은 음수가 나올 수도 있으므로 양수가 나올 때까지 K를 더해준다.
            while(y < 0) y += K;
            if(y > 1e9)
                cout << "IMPOSSIBLE\n";
            else cout << y << '\n';
        }
    }
    return 0;
}
