/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool border_checking(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(vector<vector<char> > &v, int x, int y, int n, int m) {
    queue<pair<int, int> > q;
    q.push({x, y});
    visited[x][y] = true;
    int counter = 0;
    
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if(border_checking(nx, ny, n, m) && !visited[nx][ny] && v[nx][ny] == '#') {
                visited[nx][ny] = true;
                counter++;
                q.push({nx, ny});
            }
        }
    }
    // cout << "x : " << x << " y : " << y << " counter : " << counter << '\n';
    return counter;
}

vector<int> solve(vector<vector<char> > &v, int n, int m) {
    vector<int> ans;
    ans.assign(3, 0);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && v[i][j] == '#') {
                int counter = bfs(v, i, j, n, m);
                ans[counter]++;
            }
        }
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    vector<vector<char> > v;
    
    cin >> n >> m;
    v.assign(n + 1, vector<char>());
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        // cout << s << '\n';
        for(int j=0; j<m; j++) {
            v[i].emplace_back(s[j]);
        }
    }
    
    memset(visited, false, sizeof(visited));
    vector<int> result = solve(v, n, m);
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
