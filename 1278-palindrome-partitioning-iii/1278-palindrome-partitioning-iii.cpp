class Solution {
    int memoization(int x,int k,int n,vector<vector<int>> &dp,vector<vector<int>> &memo){
        if(x > n and k == 0) return 0;
        if(x == n + 1 || !k) return 1e9;
        if(memo[x][k] != -1) return memo[x][k];

        int optimal = 1e9;

        for(int i = x;i<=n;i++){
            int sum = dp[x][i] + memoization(i + 1,k - 1,n,dp,memo);
            optimal = min(optimal,sum);
        }

        return memo[x][k] = optimal;
    }
public:
    int palindromePartition(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0)), memo(n + 1,vector<int>(k + 1,-1));

        for(int gap = 0;gap<n;gap++){
            for(int x = 1;x + gap <= n;x++){
                int y = x + gap;

                if(gap == 0) dp[x][y] = 0;
                else if(gap == 1 || gap == 2) dp[x][y] = s[x - 1] != s[y - 1];
                else dp[x][y] = dp[x + 1][y - 1] + (s[x - 1] != s[y - 1]);
            }
        }

        return memoization(1,k,n,dp,memo);
    }
};