class Solution {
    public int removeElement(int[] nums, int val) {
        int n = nums.length, cnt = 0;
        if(n == 0) {
            return 0;
        }

        int i = 0;
        while(true) {  
            if(i == n - cnt) {
                break;
            }

            if(nums[i] == val) {
                int temp = nums[i];
                nums[i] = nums[n - 1 - cnt];
                nums[n - 1 - cnt] = temp;
                cnt++;
            }

            if(nums[i] != val) {
                i++;
            }
        }

        return n - cnt;
    }
}
