class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k % n == 0)
            return;

        deque<int> q(nums.begin(), nums.end());

        k = k % n;
        for(int i=0; i<k; i++) {
            int last = q.back(); q.pop_back();
            q.push_front(last);
        }

        nums.clear();
        while(!q.empty()) {
            nums.push_back(q.front()); q.pop_front();
        }
    }
};
