class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        // 조합을 사용한다.
        // 0 1 1 1
        // 1 0 1 1
        // 1 1 0 1
        // 1 1 1 0 => n C n-1 = n
        // n loop
        // 조합으로 푸는 방법 -> O(n^2)

        // prefixSum
        // 누적 곱을 사용해봅니다.
        // 1 2 6 24
        // 
        int[] prefixSum = new int[n];

        prefixSum[0] = 1;
        for(int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i - 1] * nums[i - 1];
        }

        int[] reverseSum = new int[n];

        reverseSum[n - 1] = 1;
        for(int i=n-2; i>=0; i--) {
            reverseSum[i] = reverseSum[i + 1] * nums[i + 1];
        }

        for(int i=0; i<n; i++) {
            ans[i] = prefixSum[i] * reverseSum[i];
        }

        return ans;
    }
}
