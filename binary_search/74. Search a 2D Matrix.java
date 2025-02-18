class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;

        int lo = 0, hi = m * n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int newM = mid / n;
            int newN = mid % n;

            // System.out.println(newM + " , " + newN + " : " + matrix[newM][newN]);

            if(matrix[newM][newN] == target)
                return true;

            if(matrix[newM][newN] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return false;
    }
}
