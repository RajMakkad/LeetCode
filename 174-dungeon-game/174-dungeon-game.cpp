class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dung) {
        int n = dung.size(), m = dung[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
        dp[n][m - 1] = dp[n - 1][m] = 1;
        
        for(int r = n - 1; r >= 0;r--){
            for(int c = m - 1; c >= 0;c--){
                int need = min(dp[r][c + 1], dp[r + 1][c]) - dung[r][c];
                dp[r][c] = (need <= 0 ? 1: need);
            }
        }
        
        return dp[0][0];
    }
};