#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define mp make_pair

int N, M;
vector<ii> chicken, home;

int main() {
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			int k; scanf("%d", &k);
			if(k == 2) {
				chicken.emplace_back(mp(i, j));
			} else if(k == 1) {
				home.emplace_back(mp(i, j));
			}
		}
	}
	
	int perm_size = max(M, (int)chicken.size());
	int total_size = M > (int)chicken.size() ? 0 : chicken.size() - M;
	vector<int> perm(perm_size, 0);
	for(int i=chicken.size() - 1; i >= total_size; i--) {
		perm[i] = 1;
	}
	
	int ans = 987654321;
	do {
		int dist_by_perm = 0;
		for(int h=0; h<home.size(); h++) {
			int hy = home[h].first, hx = home[h].second;
			
			int dist_by_home = 987654321;
			for(int c=0; c<chicken.size(); c++) {
				if(perm[c] == 1) {
					int cy = chicken[c].first, cx = chicken[c].second;
					int dist = abs(cy - hy) + abs(cx - hx);
					dist_by_home = min(dist, dist_by_home);
				}
			}
			dist_by_perm += dist_by_home;
		}
		ans = min(dist_by_perm, ans);
		
	} while(next_permutation(perm.begin(), perm.end()));
	
	printf("%d\n", ans);
	
	return 0;
}
