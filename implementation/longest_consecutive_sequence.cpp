class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());

        int lo = 0, hi = 0, dup = 0, max_length = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[hi]) {
                dup++;
                hi = i;
            }
            else if(nums[i] == nums[hi] + 1) {
                hi++;
            } else {
                if(hi - lo + 1 - dup > max_length) {
                    max_length = hi - lo + 1 - dup;
                    cout << max_length << " hi : " << hi << " lo : " << lo << " dup : " << dup << '\n';
                }
                lo = i;
                hi = i;
                dup = 0;
            }
        }

        if(hi - lo + 1 - dup > max_length) {
            max_length = hi - lo + 1 - dup;
        }

        return max_length;
    }
};
