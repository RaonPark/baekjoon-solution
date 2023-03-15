#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321
#define MAX 1000
typedef long long ll;
typedef pair<ll, int> lli;

int n, m;
vector<vector<lli > > adjList;
int cache[MAX + 1];

ll dijkstra(int start, int end) {
	priority_queue<lli, vector<lli >, greater<lli > > pq; pq.push({0LL, start});
	vector<ll> visited(n + 1, INF); visited[start] = 0;
	
	while(!pq.empty()) {
		ll cost = pq.top().first; int now = pq.top().second; pq.pop();
		
		if(now == end) {
			return visited[now];
		}
		
		if(cost > visited[now]) continue;
		
		for(int j=0; j<(int)adjList[now].size(); j++) {
			lli node = adjList[now][j];
			int next = node.second; ll cnt = node.first;
			
			if(visited[now] + cnt < visited[next]) {
				cache[next] = now;
				visited[next] = visited[now] + cnt;
				pq.push({visited[next], next});
			}
		}
	}
	
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	
	adjList.assign(n + 1, vector<lli >());
	for(int i=0; i<m; i++) {
		int a, b; long c; scanf("%d %d %lld", &a, &b, &c);
		adjList[a].push_back({c, b});
	}
	
	int start, end;
	scanf("%d %d", &start, &end);
	
	ll result = dijkstra(start, end);
	printf("%lld\n", result);
	
	vector<int> path;
	
	int idx = end;
	while(idx != start) {
		path.emplace_back(idx);
		idx = cache[idx];
	}
	path.emplace_back(start);
	
	printf("%d\n", path.size());
	
	for(int i=path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("\n");

	return 0;
}
