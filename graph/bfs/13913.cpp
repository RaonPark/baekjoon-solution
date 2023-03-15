#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100000
int N, K;
int cache[MAX + 1];

void solve() {
	vector<bool> visited(MAX + 1, 0); visited[N] = true;
	
	queue<int> q; q.push(N); 
	
	while(!q.empty()) {
		int now = q.front(); q.pop();
		
		if(now == K) {
			return;
		}
		
		int next1 = now + 1, next2 = now - 1, next3 = 2 * now;
		if(next1 >= 0 && next1 <= MAX && !visited[next1]) {
			visited[next1] = true;
			q.push(next1);
			cache[next1] = now;
		}
		if(next2 >= 0 && next2 <= MAX && !visited[next2]) {
			visited[next2] = true;
			q.push(next2);
			cache[next2] = now;
		}
		if(next3 >= 0 && next3 <= MAX && !visited[next3]) {
			visited[next3] = true;
			q.push(next3);
			cache[next3] = now;
		}
	}
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	
	cin >> N >> K;
	
	solve();
	vector<int> path;
	
	int now = K;
	while(now != N) {
		path.emplace_back(now);
		now = cache[now];
	}
	
	path.emplace_back(N);
	
	cout << (path.size() - 1) << '\n';
	for(int i=path.size() - 1; i>=0; i--) {
		cout << path[i] << " ";
	}
	cout << '\n';
}
​
