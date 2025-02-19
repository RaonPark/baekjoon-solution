class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if(nums[0] <= nums[n - 1])
            return nums[0];
        
        int lo = 0, hi = n - 1;

        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            } else if(nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else {
                if(nums[mid] > nums[n - 1]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }

        return -1;
    }
}
