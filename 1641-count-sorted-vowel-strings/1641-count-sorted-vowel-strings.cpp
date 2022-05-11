class Solution {
    int memoization(int n,int x,vector<vector<int>> &dp){
        if(n == 0) return 1;
        if(dp[n][x] != -1) return dp[n][x];

        int sum = 0;

        for(int i = x;i<5;i++){
            sum += memoization(n - 1,i,dp);
        }

        return dp[n][x] = sum;
    }
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1,vector<int>(5,-1));
        return memoization(n,0,dp);
    }
};