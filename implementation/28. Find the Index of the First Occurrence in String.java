class Solution {
    public int strStr(String haystack, String needle) {
        int hIdx = 0, nIdx = 0, startHIdx = 0;
        boolean found = false;
        int hLen = haystack.length(), nLen = needle.length();

        while(hIdx < hLen) {
            if(haystack.charAt(hIdx) != needle.charAt(nIdx)) {
                startHIdx++;
                hIdx = startHIdx;
                nIdx = 0;
            } else {
                hIdx++;
                nIdx++;
            }

            if(nIdx == nLen) {
                found = true;
                break;
            }
        }

        return found ? startHIdx : -1;
    }
}
