class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(m == 0) {
            for(int i=0; i<n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        } else if(n == 0) {
            return;
        }

        for(int i=m+n-1; i>=n; i--) {
            nums1[i] = nums1[i - n];
        }

        int one = n, two = 0;
        for(int i=0; i<m+n; i++) {
            if(one < m + n && two < n) {
                if(nums1[one] < nums2[two]) {
                    nums1[i] = nums1[one++];
                } else nums1[i] = nums2[two++];
            } else if(one < m + n) {
                nums1[i] = nums1[one++];
            } else {
                nums1[i] = nums2[two++];
            }
        }
    }
}
