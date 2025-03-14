class Solution {
    boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    public int maxVowels(String s, int k) {
        int n = s.length();
        int lo = 0, hi = k - 1;
        int cnt = 0;
        int answer = 0;

        for(int i=0; i<k; i++) {
            if(isVowel(s.charAt(i)))
                cnt++;
        }
        answer = cnt;
        hi++;

        while(hi < n) {
            if(isVowel(s.charAt(hi))) {
                if(!isVowel(s.charAt(lo)))
                    cnt++;
                answer = Math.max(answer, cnt);
                lo++;
                hi++;
            } else {
                if(isVowel(s.charAt(lo)))
                    cnt--;
                lo++;
                hi++;
            }
        }

        return answer;
    }
}
