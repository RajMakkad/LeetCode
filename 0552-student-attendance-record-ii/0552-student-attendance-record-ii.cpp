class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        if (n == 0) return 0;
        
        // dp[i][j][k] 
        // i: length of sequence
        // j: number of 'A's in sequence (0 or 1)
        // k: length of consecutive 'L's at the end (0, 1, or 2)
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        dp[0][0][0] = 1; // Base case: An empty record is valid
        
        for (int i = 1; i <= n; ++i) {
            // Ending with 'P'
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 2; ++k) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
            
            // Ending with 'L'
            for (int j = 0; j <= 1; ++j) {
                for (int k = 1; k <= 2; ++k) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
            
            // Ending with 'A'
            for (int k = 0; k <= 2; ++k) {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
        }

        int result = 0;
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 2; ++k) {
                result = (result + dp[n][j][k]) % MOD;
            }
        }

        return result;
    }
};
