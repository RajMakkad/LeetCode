class Solution {
    const int mod = 1e9 + 7;
    int memoize(int n, int absent, int late, vector<vector<vector<int>>> &dp){
        if(n == 0)
            return 1;
        if(dp[n][absent][late] > 0)
            return dp[n][absent][late];
        int ans = 0;
        ans += memoize(n - 1, absent, 0, dp);
        if(absent == 0)
            ans = (ans + memoize(n - 1, absent + 1, 0, dp)) % mod;
        if(late <= 1)
            ans = (ans + memoize(n - 1, absent, late + 1, dp)) % mod;
        return dp[n][absent][late] = ans;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        return memoize(n, 0, 0, dp);
    }
};