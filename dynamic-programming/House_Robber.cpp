class Solution {
private:
    int cache[101];
public:
    int rob(vector<int>& nums) {
        memset(cache, -1, sizeof(cache));
        return rob(nums, 0);
    }

    int rob(vector<int>& nums, int now) {
        if(now >= (int)nums.size())
            return 0;
        
        int& ret = cache[now];
        if(ret != -1)
            return ret;
        
        ret = max(rob(nums, now + 1), nums[now] + rob(nums, now + 2));

        return ret;
    }
};
