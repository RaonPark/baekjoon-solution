class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int lo = 0, hi = 0, sums = nums[lo];
        int range = 100010; 
        boolean hits = false;
        int n = nums.length;
        while(lo <= hi) {
            if(sums >= target) {
                hits = true;
                range = Math.min(range, hi - lo + 1);
            }
            
            if(hi == n - 1 && target > sums)
                break;

            if(sums < target) {
                hi++;
                sums += nums[hi];
            } else {
                sums -= nums[lo];
                lo++;
            }

            if(hi == n) {
                lo++;
                sums = nums[lo];
                hi = lo;
            }
        }

        return hits ? range : 0;
    }
}
