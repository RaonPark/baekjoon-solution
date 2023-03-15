#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef vector<int> vi;
typedef vector<pair<double, double> > Coord;
typedef pair<double, pair<int, int> > Edge;
typedef vector<pair<double, pair<int, int> > > EdgeList;

class UnionFind {
private:
	vi p;
public:
	UnionFind(int N) {
		p.assign(N, 0); for(int i=0; i<N; i++) p[i] = i;
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

int n;
Coord coord;
EdgeList edgelist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout<<fixed;
	cout.precision(2);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		double x, y; cin >> x >> y;
		coord.emplace_back(mp(x, y));
	}
	
	for(int i=0; i<n; i++) {
		double x1 = coord[i].first, y1 = coord[i].second;
		for(int j=i+1; j<n; j++) {
			double x2 = coord[j].first, y2 = coord[j].second;
			double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			edgelist.emplace_back(mp(dist, mp(i, j)));
		}
	}
	
	sort(edgelist.begin(), edgelist.end());
	
	UnionFind uf(n);
	double result = 0.0;
	for(int i=0; i<edgelist.size(); i++) {
		Edge edge = edgelist[i];
		if(!uf.isSameSet(edge.second.first, edge.second.second)) {
			result += edge.first;
			uf.unionSet(edge.second.first, edge.second.second);
		}
	}
	
	cout << result << '\n';
	return 0;
}
