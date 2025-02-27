class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);

        for(int i=0; i<strs[0].length(); i++) {
            char p = strs[0].charAt(i);
            for(int j=1; j<strs.length; j++) {
                if(strs[j].charAt(i) != p) {
                    return strs[0].substring(0, i);
                }
            }
        }
        return strs[0];
    }
}
