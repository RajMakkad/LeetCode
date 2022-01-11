class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> dp(n + 1,0);
        
        for(int r = n - 1;r>=0;r--){
            int m = t[r].size();
            
            for(int c = 0;c<m;c++) dp[c] = min(dp[c],dp[c + 1]) + t[r][c];
        }
        
        return dp[0];
    }
};