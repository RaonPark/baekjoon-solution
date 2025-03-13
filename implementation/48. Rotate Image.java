class Solution {
    public void rotate(int[][] matrix) {
        int row = matrix.length;
        for(int i=0; i<row; i++) {
            for(int j=0; j<=i; j++) {
                if(i == j) continue;
                matrix[i][j] ^= matrix[j][i];
                matrix[j][i] ^= matrix[i][j];
                matrix[i][j] ^= matrix[j][i];
            }
        }
        
        for(int i=0; i<row; i++) {
            int lo = 0, hi = row - 1;
            while(lo <= hi) {
                if(lo != hi) {
                    matrix[i][lo] ^= matrix[i][hi];
                    matrix[i][hi] ^= matrix[i][lo];
                    matrix[i][lo] ^= matrix[i][hi];
                }
                lo++;
                hi--;
            }
        }
    }
}
