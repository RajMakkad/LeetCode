class Solution {
    bool memoization(int n,int m,vector<vector<int>> &dp,string &s1,string &s2,string &s3){
        if(n == 0 and m == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];

        bool optimal = false;
        int x = n + m - 1;
        if(n > 0 and s3[x] == s1[n - 1]) optimal |= memoization(n - 1,m,dp,s1,s2,s3);
        if(m > 0 and s3[x] == s2[m - 1]) optimal |= memoization(n,m - 1,dp,s1,s2,s3);

        return dp[n][m] = optimal;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,-1));
        return n + m == s3.length() and memoization(n,m,dp,s1,s2,s3);
    }
};