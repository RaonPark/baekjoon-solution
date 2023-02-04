#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define mp make_pair

int N;
ii shark;
int shark_weight = 2, max_fish_weight = 0;
int board[21][21];
vector<vector<ii > > fishes;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

bool is_boundary(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < N);
}

int bfs(ii fish) {
	queue<ii > q; q.push(mp(shark.first, shark.second));
	int visited[21][21]; memset(visited, 0, sizeof(visited));
	visited[shark.first][shark.second] = 0;
	
	while(!q.empty()) {
		int ny = q.front().first, nx = q.front().second; q.pop();
		
		if(ny == fish.first && nx == fish.second) {
			//printf("%d %d %d\n", ny, nx, visited[nx][ny]);
			return visited[ny][nx];
		}
		
		for(int i=0; i<4; i++) {
			int newy = ny + dy[i], newx = nx + dx[i];
			if(is_boundary(newy, newx) && visited[newy][newx] == 0 && board[newy][newx] <= shark_weight) {
				q.push(mp(newy, newx));
				visited[newy][newx] = visited[ny][nx] + 1;
			}
		}
	}
	
	return -1;
}

int main() {
	fishes.assign(7, vector<ii >());
	
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &board[i][j]);
			if(board[i][j] == 9) {
				shark.first = i; shark.second = j;
				board[i][j] = 0;
			} else {
				fishes[board[i][j]].emplace_back(mp(i, j));
				if(board[i][j] > max_fish_weight) {
					max_fish_weight = board[i][j];
				}
			}
		}
	}
	
	int ans = 0, eaten_fish = 0;
	while(true) {
		int dist = 987654321;
		int fishy = 0, fishx = 0;
		int weight = 0, jdx = 0;
		bool end_flag = true;
		for(int w=1; w<shark_weight; w++) {
			if(w > max_fish_weight) break;
			for(int j=0; j<fishes[w].size(); j++) {
				int temp_dist = bfs(fishes[w][j]);
				//printf("%d %d temp_dist : %d\n", fishes[w][j].first, fishes[w][j].second, temp_dist);
				if(temp_dist != -1) {
					end_flag = false;
					if(temp_dist < dist) {
						dist = temp_dist;
						fishy = fishes[w][j].first;
						fishx = fishes[w][j].second;
						weight = w;
						jdx = j;
					}
					else if(temp_dist == dist) {
						if(fishes[w][j].first < fishy) {
							fishy = fishes[w][j].first;
							fishx = fishes[w][j].second;
							weight = w;
							jdx = j;
						} else if(fishes[w][j].first == fishy) {
							if(fishes[w][j].second < fishx) {
								fishy = fishes[w][j].first;
								fishx = fishes[w][j].second;
								weight = w;
								jdx = j;
							}
						}
					}
				}
			}
		}
		
		if(end_flag) {
			break;
		}
		
		ans += dist;
		shark.first = fishy; shark.second = fishx;
		eaten_fish += 1;
		if(eaten_fish == shark_weight) {
			shark_weight += 1;
			eaten_fish = 0;
		}
		board[fishy][fishx] = 0;
		fishes[weight].erase(fishes[weight].begin() + jdx);
		//printf("dist : %d sy: %d sx : %d weight : %d\n", dist, shark.first, shark.second, shark_weight);
	}
	
	printf("%d\n", ans);
	
	
	return 0;
}
