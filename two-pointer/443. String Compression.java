class Solution {
    public int compress(char[] chars) {
        int n = chars.length;

        int lo = 0, hi = 1, cnt = 1;
        while(hi < n) {
            if(chars[lo] != chars[hi]) {
                if(cnt != 1) {
                    String c = String.valueOf(cnt);
                    for(int i=0; i<c.length(); i++) {
                        chars[++lo] = c.charAt(i);
                    }
                }
                cnt = 1;
                chars[++lo] = chars[hi++];
            } else {
                cnt++;
                hi++;
            }
        }

        if(cnt != 1) {
            String c = String.valueOf(cnt);
            for(int i=0; i<c.length(); i++) {
                chars[++lo] = c.charAt(i);
            }
        }

        return lo + 1;
    }
}
