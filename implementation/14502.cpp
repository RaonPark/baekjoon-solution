#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

// ........................macro.......................... //
// [i, n)
#define FOR(i, f, n) for(int (i) = (f); (i) < (int)(n); ++(i))
// [i, n]
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (int)(n); --(i))
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define pf pop_front
#define fi first
#define se second
#define ENDL '\n'
#define sz(A) (int)(A).size()
#define ALL(A) A.begin(), A.end()	
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define next next9876
#define prev prev1234
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;
typedef pair<int, int> ii;
typedef pair<long long, long long> i64i64;
typedef pair<int, pair<int, int> > iii;
typedef long long i64;
typedef unsigned long long ui64;

//#define WILL_USE_CIN

int V, U;
int adjMat[101][101];
int copy_adjMat[101][101];
int answer[101][101];
bool visit[101][101];
vii position;
vii zeros;
vi perm;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void virus_bfs(int u, int v) {
	vvi visit(V + 1, vector<int>(U+1 , 0)); visit[u][v] = 1;
	queue< ii > q; q.push({u, v});
	
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for(int i=0; i<4; ++i) {
			int xdx = x + dx[i], ydy = y + dy[i];
			if(xdx >= 0 && ydy >= 0 && xdx < V && ydy < U && !visit[xdx][ydy] && !copy_adjMat[xdx][ydy]) {
				visit[xdx][ydy] = 1;
				copy_adjMat[xdx][ydy] = 2;
				q.push({xdx, ydy});
			}
		}
	}
}

int main() {
	#ifdef WILL_USE_CIN
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
	#endif
	
	scanf("%d %d", &V, &U);
	int n;
	for(int i=0; i<V; ++i) {
		for(int j=0; j<U; ++j) {
			scanf("%d", &n);
			adjMat[i][j] = n; copy_adjMat[i][j] = n;
			if(adjMat[i][j] == 2) position.eb(make_pair(i, j));
			else if(adjMat[i][j] == 0) zeros.eb(make_pair(i, j));
		}
	}
	
	perm.assign(zeros.size(), 0);
	perm[perm.size() - 1] = 1; perm[perm.size() - 2] = 1; perm[perm.size() - 3] = 1;
	int max = 0;
	do {
		for(int i=0; i<V; ++i) for(int j=0; j<U; ++j) copy_adjMat[i][j] = adjMat[i][j];
		int cnt = 0;
		for(int i=0; i<perm.size(); ++i) {
			if(perm[i] == 1) { copy_adjMat[zeros[i].first][zeros[i].second] = 1; }
		}
		for(int i=0; i<position.size(); ++i) {
			virus_bfs(position[i].first, position[i].second);
		}
		for(int i=0; i<V; ++i) {
			for(int j=0; j<U; ++j) {
				if(!copy_adjMat[i][j]) cnt++;
			}
		}
		if(cnt > max) max = cnt;
	} while(next_permutation(perm.begin(), perm.end()));
	printf("%d\n", max);

	return 0;
}
