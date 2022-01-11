class Solution {
    int memoization(int x,int y,vector<vector<int>> &mat,vector<vector<int>> &dp){
        int n = dp.size();
        if(x == n) return 0;
        if(dp[x][y] != 1e9) return dp[x][y];
        
        int num = 1e9;
        for(int i = max(y - 1,0);i <= min(y + 1,n - 1);i++)
            num = min(num,memoization(x + 1,i,mat,dp));
        
        num += mat[x][y];
        return dp[x][y] = num;
    }
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        
        for(int i = 0;i<n;i++)
            ans = min(ans,memoization(0,i,mat,dp));
        
        return ans;
    }
};