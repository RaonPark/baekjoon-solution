class Solution {
public:
    #define eb emplace_back
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int> > ans;

        sort(nums.begin(), nums.end());

        for(int b = 0; b < n - 2; b++) {
            if(b > 0) {
                if(nums[b] == nums[b - 1])
                    continue;
            }
            int lo = b + 1, hi = n - 1;

            while(lo < hi) {
                if(nums[lo] + nums[hi] == -nums[b]) {
                    vector<int> v;
                    v.eb(nums[lo]);
                    v.eb(nums[hi]);
                    v.eb(nums[b]);
                    ans.emplace(v);
                    lo++;
                } else if(abs(nums[lo] + nums[hi]) < abs(nums[b])) {
                    lo++;
                } else
                    hi--;
            }
        }

        vector<vector<int> > ret(ans.begin(), ans.end());
        return ret;
    }
};
