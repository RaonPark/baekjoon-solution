class Solution {
public:
    const int INF = 12293;
    int cache[10001];
    int coinChange(vector<int>& coins, int amount) {
        memset(cache, -1, sizeof(cache));
        int ret = solve(coins, amount);
        return ret >= INF ? -1 : ret;
    }

    int solve(vector<int>& coins, int amount) {
        if(amount < 0)
            return INF;
        if(amount == 0)
            return 0;
        
        int& ret = cache[amount];
        if(ret != -1)
            return ret;

        ret = INF;
        
        for(int i=0; i<coins.size(); i++) {
            ret = min(1 + solve(coins, amount - coins[i]), solve(coins, amount));
        }

        return ret;
    }
};
