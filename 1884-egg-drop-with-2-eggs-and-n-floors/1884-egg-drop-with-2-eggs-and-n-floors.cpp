class Solution {
    int memoization(int n, int eggs, vector<vector<int>> &dp){
        if(eggs == 1) return n;
        if(n <= 1) return n;

        if(dp[n][eggs] != -1) return dp[n][eggs];

        int ans = 1e9;
        for(int i = 1; i <= n;i++){
            int b = memoization(i - 1, eggs - 1, dp) + 1;
            int nb = memoization(n - i, eggs, dp) + 1;
            ans = min(ans, max(b, nb));
        }

        return dp[n][eggs] = ans;
    }
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(3, - 1));
        return memoization(n, 2, dp);
    }
};