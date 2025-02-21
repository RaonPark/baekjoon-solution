class Solution {
    public int maxArea(int[] height) {
        int lo = 0, hi = height.length - 1;
        int answer = -1;

        while(lo < hi) {
            int area = (hi - lo) * Math.min(height[lo], height[hi]);

            answer = Math.max(answer, area);

            if(height[lo] < height[hi]) {
                int now = height[lo];
                while(lo < hi) {
                    if(now < height[lo])
                        break;
                    lo++;
                }
            } else {
                hi--;
            }
        }

        return answer;
    }
}
