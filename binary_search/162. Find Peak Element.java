class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int lo = 0, hi = n - 1;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            boolean leftSmaller = false, rightSmaller = false;
            
            if(mid == 0) {
                leftSmaller = true;
            } else if(nums[mid] > nums[mid - 1]) {
                leftSmaller = true;
            }

            if(mid == n - 1) {
                rightSmaller = true;
            } else if(nums[mid] > nums[mid + 1]) {
                rightSmaller = true;
            }
            
            if(rightSmaller && leftSmaller) {
                return mid;
            }

            if(rightSmaller) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return -1;
    }
}
