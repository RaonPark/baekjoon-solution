class Solution {
private:
    const int MOD = (int)pow(10, 9) + 7;
    int cache[100010][3];
    int stirling(int n, int k) {
        if(n == 0 && k == 0) return 1;
        else if(n == 0 || k == 0) return 0;

        int& ret = cache[n][k];
        if(ret != -1)
            return ret;

        return ret = (((k * stirling(n - 1, k)) % MOD) + (stirling(n - 1, k - 1) % MOD)) % MOD;
    }
public:
    int countWays(vector<vector<int>>& ranges) {
        typedef vector<int> vi;

        sort(ranges.begin(), ranges.end());
        
        int count = 1;
        int right = ranges[0][1];
        for(int i=1; i<ranges.size(); i++) {
            int left = ranges[i][0], next_right = ranges[i][1];

            if(right >= left) {
                right = max(right, next_right);
            } else {
                right = next_right;
                count++;
            }
        }
        cout << "stirling : " << count << '\n';
        if(count == 1)
            return 2;

        memset(cache, -1, sizeof(cache));
        int result = (stirling(count, 2) + 1) % MOD;
        return (result * 2) % MOD;
    }
};
