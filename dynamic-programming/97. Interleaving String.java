class Solution {
    int[][] cache;
    public int isInterleave(int i, int j, String s1, String s2, String s3) {
        if(s1.length() == i && s2.length() == j) {
            return 1;
        }

        if(cache[i][j] != -1) {
            return cache[i][j];
        }

        int first = 0;
        if(i < s1.length() && s1.charAt(i) == s3.charAt(i + j)) {
            first = isInterleave(i + 1, j, s1, s2, s3);
        }

        int second = 0;
        if(j < s2.length() && s2.charAt(j) == s3.charAt(i + j)) {
            second = isInterleave(i, j + 1, s1, s2, s3);
        }

        cache[i][j] = (first == 1 || second == 1) ? 1 : 0;
        return cache[i][j];
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length() + s2.length() != s3.length()) {
            return false;
        }
        cache = new int[s1.length() + 1][s2.length() + 1];
        for(int[] c : cache) {
            Arrays.fill(c, -1);
        }
        return isInterleave(0, 0, s1, s2, s3) == 1 ? true : false;
    }
}
