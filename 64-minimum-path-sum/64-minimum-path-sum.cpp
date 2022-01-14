class Solution {
public:
    int minPathSum(vector<vector<int>>& g){
        int n = g.size();
        int m = g[0].size();

        vector<vector<int>> dp(n,vector<int>(m));

        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(r == 0 and c == 0) dp[r][c] = g[r][c];
                else{
                    int up = 1e9;
                    int left = 1e9;

                    if(r > 0) up = dp[r - 1][c];
                    if(c > 0) left = dp[r][c - 1];
                    dp[r][c] = min(up,left)  + g[r][c];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};