class Solution {
public:
    int checkRecord(int n) {
        if (n == 0) return 0; // Handle edge case

        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(6, 0));

        dp[0][0] = 1; // Base case: An empty record is valid

        for (int i = 1; i <= n; ++i) {
            // Ending with 'P'
            dp[i][0] = ((dp[i-1][0] + dp[i-1][1]) % MOD + dp[i-1][2]) % MOD;
            dp[i][3] = ((dp[i-1][3] + dp[i-1][4]) % MOD + dp[i-1][5]) % MOD;
            
            // Ending with 'L'
            dp[i][1] = dp[i-1][0];
            dp[i][2] = dp[i-1][1];
            dp[i][4] = dp[i-1][3];
            dp[i][5] = dp[i-1][4];
            
            // Ending with 'A'
            dp[i][3] = (dp[i][3] + ((dp[i-1][0] + dp[i-1][1]) % MOD + dp[i-1][2]) % MOD) % MOD;
        }

        int result = 0;
        for (int j = 0; j < 6; ++j) {
            result = (result + dp[n][j]) % MOD;
        }

        return result;
    }
};
