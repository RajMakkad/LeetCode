class Solution {
    int memoization(int n,int m,string &s1,string &s2,vector<vector<int>> &dp){
        if(n==0) return dp[n][m] = m;
        else if(m==0) return dp[n][m] = n;

        if(dp[n][m]!=-1) return dp[n][m];

        if(s1[n - 1]==s2[m - 1]) return dp[n][m] = memoization(n - 1,m - 1,s1,s2,dp); // same.
        
        int x = memoization(n,m - 1,s1,s2,dp) + 1; // insert.
        int y = memoization(n - 1,m,s1,s2,dp) + 1; // delete.
        int z = memoization(n - 1,m - 1,s1,s2,dp) + 1; // replace.
        
        return dp[n][m] = min({x,y,z});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,-1));
        
        memoization(n,m,word1,word2,dp);
        
        return dp[n][m];
    }
};