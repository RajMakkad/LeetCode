class Solution {
    int memoization(int i, int c, int n, vector<vector<int>> &dp){
        if(i >= n)
            return 0;
        if(dp[i][c] != -1)
            return dp[i][c];
        int res_1 = INT_MAX, res_2 = INT_MAX;
        if(c > 0 and i + c <= n){
            res_1 = memoization(i + c, c, n, dp);
            res_1 += res_1 != INT_MAX ? 1 : 0;
        }
        if(i + i <= n){
            res_2 = memoization(i + i, i, n, dp);
            res_2 += res_2 != INT_MAX ? 2 : 0;
        }
        return dp[i][c] = min(res_1, res_2);
    }
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(1, 0, n, dp);
    }
};