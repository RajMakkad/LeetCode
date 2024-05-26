class Solution {
    const int mod = 1e9 + 7;
    // int memoize(int n, int absent, int late, vector<vector<vector<int>>> &dp){
    //     if(n == 0)
    //         return 1;
    //     if(dp[n][absent][late] > 0)
    //         return dp[n][absent][late];
    //     int ans = 0;
    //     ans += memoize(n - 1, absent, 0, dp);
    //     if(absent == 0)
    //         ans = (ans + memoize(n - 1, absent + 1, 0, dp)) % mod;
    //     if(late <= 1)
    //         ans = (ans + memoize(n - 1, absent, late + 1, dp)) % mod;
    //     return dp[n][absent][late] = ans;
    // }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2 + 1, vector<int>(3 + 1, 0)));
        // return memoize(n, 0, 0, dp);
        
        for(int ab = 0; ab <= 1; ab++){
            for(int lt = 0; lt <= 2; lt++){
                dp[0][ab][lt] = 1;
            }
        }
        
        for(int d = 1; d <= n; d++) {
            for(int ab = 0; ab <= 1; ab++) {
                for(int lt = 0; lt <= 2; lt++) {
                    dp[d][ab][lt] = dp[d - 1][ab][0];
                    dp[d][ab][lt] = (dp[d][ab][lt] + dp[d - 1][ab + 1][0]) % mod;
                    dp[d][ab][lt] = (dp[d][ab][lt] + dp[d - 1][ab][lt + 1]) % mod;
                }
            }
        }
        
        return dp[n][0][0];
    }
};