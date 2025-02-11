class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k % n == 0)
            return;

        k = k % n;
        vector<int> first(nums.begin(), nums.begin() + n - k);
        vector<int> last(nums.begin() + n - k, nums.end());

        nums.clear();
        for(int i=0; i<last.size(); i++) {
            nums.emplace_back(last[i]);
        }
        for(int i=0; i<first.size(); i++) {
            nums.emplace_back(first[i]);
        }
    }
};
