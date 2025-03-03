class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length() > t.length())
            return false;
        
        int sLen = s.length();
        int tLen = t.length();

        int sIdx = 0, tIdx = 0;

        while(tIdx < tLen) {
            if(sIdx == sLen)
                break;
            if(t.charAt(tIdx) == s.charAt(sIdx)) {
                sIdx++;
                tIdx++;
            } else {
                tIdx++;
            }
        }

        return sIdx == sLen;
    }
}
