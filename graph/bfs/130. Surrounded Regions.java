class Solution {
    static class Point {
        public int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

    ArrayList<ArrayList<Point>> willDeleted = new ArrayList<>();

    public boolean isSurrounded(int x, int y, int m, int n, boolean[][] visited, char[][] board) {
        ArrayDeque<Point> q = new ArrayDeque<>();
        boolean ret = true;
        ArrayList<Point> points = new ArrayList<>();

        q.addLast(new Point(x, y));

        while(!q.isEmpty()) {
            Point p = q.poll();

            points.add(new Point(p.x, p.y));

            if(p.x == m - 1 || p.y == n - 1 || p.x == 0 || p.y == 0)
                ret = false;

            for(int i=0; i<4; i++) {
                int nextX = p.x + dx[i], nextY = p.y + dy[i];

                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && !visited[nextX][nextY] && board[nextX][nextY] == 'O') {
                    visited[nextX][nextY] = true;
                    q.addLast(new Point(nextX, nextY));
                }
            }
        }

        if(ret) {
            willDeleted.add(points);
        }

        return ret;
    }

    public void solve(char[][] board) {
        int m = board.length, n = board[0].length;
        boolean[][] visited = new boolean[m][n];

        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(board[x][y] == 'O' && !visited[x][y]) {
                    visited[x][y] = true;
                    isSurrounded(x, y, m, n, visited, board);
                }
            }
        }
        
        for(int i=0; i<willDeleted.size(); i++) {
            for(int j=0; j<willDeleted.get(i).size(); j++) {
                Point p = willDeleted.get(i).get(j);
                board[p.x][p.y] = 'X';
            }
        }
    }
}
