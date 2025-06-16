class Solution {
    int rob(int lo, int hi, int[] nums) {
        int in = 0, ex = 0;
        for(int s = lo; s <= hi; s++) {
            int i = in, e = ex;
            in = e + nums[s];
            ex = Math.max(e, i);
        }

        return Math.max(in, ex);
    }
    public int rob(int[] nums) {
        if(nums.length == 1) return nums[0];
        return Math.max(rob(0, nums.length - 2, nums), rob(1, nums.length - 1, nums));
    }
}
