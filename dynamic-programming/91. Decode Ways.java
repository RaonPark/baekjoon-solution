class Solution {
    int[] cache;
    public int numDecodings(int i, String s) {
        if(i == s.length()) {
            return 1;
        }
        if(s.charAt(i) == '0') {
            return 0;
        }

        if(cache[i] != -1) {
            return cache[i];
        }

        cache[i] = numDecodings(i + 1, s);
        if(i < s.length() - 1) {
            int r = Integer.parseInt(s.substring(i, i + 2));
            if(r >= 1 && r <= 26) {
                cache[i] += numDecodings(i + 2, s);
            }
        }
        
        return cache[i];
    }
    public int numDecodings(String s) {
        cache = new int[s.length()];

        Arrays.fill(cache, -1);

        return numDecodings(0, s);
    }
}
