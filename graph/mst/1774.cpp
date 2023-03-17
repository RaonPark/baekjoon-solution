#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
	vector<int> p;
public:
	UnionFind(int N) {
		p.assign(N + 1, 0); for(int i=0; i<=N; i++) p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			p[y] = x;
		}
	}
};

#define mp make_pair

typedef pair<double, pair<int, int> > Edge;
typedef vector<pair<int, int> > Coord;
typedef vector<Edge > EdgeList;

int N, M;
EdgeList edgelist;
Coord coord;

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		coord.emplace_back(mp(x, y));
	}
	
	UnionFind uf(N);
	
	for(int i=0; i<M; i++) {
		int x, y; scanf("%d %d", &x, &y);
		uf.unionSet(x - 1, y - 1);
	}
	
	for(int i=0; i<N; i++) {
		double x1 = coord[i].first * 1.0, y1 = coord[i].second * 1.0;
		for(int j=i+1; j<N; j++) {
			if(!uf.isSameSet(i, j)) {
				double x2 = coord[j].first * 1.0, y2 = coord[j].second * 1.0;
				double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
				edgelist.emplace_back(mp(dist, mp(i, j)));
			}
		}
	}
	
	sort(edgelist.begin(), edgelist.end());
	
	double result = 0.0;
	for(int i=0; i<edgelist.size(); i++) {
		Edge edge = edgelist[i];
		if(!uf.isSameSet(edge.second.first, edge.second.second)) {
			result += edge.first;
			uf.unionSet(edge.second.first, edge.second.second);
		}
	}
	
	printf("%.2lf\n", result);
	return 0;
}
