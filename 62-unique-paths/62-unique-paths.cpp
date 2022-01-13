class Solution {
public:
    int uniquePaths(int n, int m) {
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = 1;
        
        
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(c > 0) dp[r][c] += dp[r][c - 1];
                if(r > 0) dp[r][c] += dp[r - 1][c];
            }
        }
        
        return dp[n - 1][m - 1];
    }
};