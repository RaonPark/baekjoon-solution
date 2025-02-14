class Solution {
    static class Point {
        public int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int[] dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
    public void island(int x, int y, int m, int n, boolean[][] visited, char[][] grid) {
        ArrayDeque<Point> q = new ArrayDeque<>();
        q.push(new Point(x, y));

        while(!q.isEmpty()) {
            Point p = q.poll();

            for(int i=0; i<4; i++) {
                int nextX = p.x + dx[i], nextY = p.y + dy[i];

                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && !visited[nextX][nextY] && grid[nextX][nextY] == '1') {
                    visited[nextX][nextY] = true;
                    q.push(new Point(nextX, nextY));
                }
            }
        }
    }
    public int numIslands(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int cnt = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    island(i, j, m, n, visited, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
}
