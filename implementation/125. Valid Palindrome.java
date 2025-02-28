class Solution {
    private boolean isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    public boolean isPalindrome(String s) {
        int lo = 0, hi = s.length() - 1;
        while(lo < hi) {
            char left = Character.toLowerCase(s.charAt(lo)), right = Character.toLowerCase(s.charAt(hi));
            if(isAlphaNumeric(left) && isAlphaNumeric(right)) {
                if(left != right) {
                    return false;
                } else {
                    lo++;
                    hi--;
                }
            } else if(isAlphaNumeric(left)) {
                hi--;
            } else if(isAlphaNumeric(right)) {
                lo++;
            } else {
                hi--;
                lo++;
            }
        }

        return true;
    }
}
