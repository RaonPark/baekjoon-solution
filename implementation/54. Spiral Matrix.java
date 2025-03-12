class Solution {
    final int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3;
    int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    boolean isAllSearched(int i, int j, int m, int n, boolean[][] visited) {
        for(int idx=0; idx<4; idx++) {
            int nextI = i + dx[idx], nextJ = j + dy[idx];
            if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n)
                if(!visited[nextI][nextJ])
                    return false;
        }

        return true;
    }
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length == 0)
            return new ArrayList<>();
        List<Integer> answer = new ArrayList<>();
        int m = matrix.length, n = matrix[0].length;

        boolean[][] visited = new boolean[m][n];

        int i = 0, j = 0;
        int toward = RIGHT;
        while(true) {
            answer.add(matrix[i][j]);
            visited[i][j] = true;

            if(isAllSearched(i, j, m, n, visited))
                break;

            if(toward == RIGHT) {
                if(j + 1 >= n || visited[i][j + 1]) {
                    toward = DOWN;
                    i++;
                } else {
                    j++;
                }
            } else if(toward == DOWN) {
                if(i + 1 >= m || visited[i + 1][j]) {
                    toward = LEFT;
                    j--;
                } else {
                    i++;
                }
            } else if(toward == LEFT) {
                if(j - 1 < 0 || visited[i][j - 1]) {
                    toward = UP;
                    i--;
                } else {
                    j--;
                }
            } else {
                if(i - 1 < 0 || visited[i - 1][j]) {
                    toward = RIGHT;
                    j++;
                } else {
                    i--;
                }
            }
        }

        return answer;
    }
}
