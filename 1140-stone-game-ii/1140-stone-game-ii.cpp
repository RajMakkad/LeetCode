class Solution {
public:
    int memoization(int idx, int m, vector<int> &suffix, vector<vector<int>> &dp){
        int n = suffix.size();
        if(idx >= n)
            return 0;
        if(idx + 2 * m >= n)
            return suffix[idx];
        if(dp[idx][m] != -1)
            return dp[idx][m];
        int res = INT_MAX;
        for(int i = 1; i <= 2 * m; i++)
            res = min(res, memoization(idx + i, max(m, i), suffix, dp));
        return dp[idx][m] = suffix[idx] - res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix = piles;
        for(int i = n - 2; i >= 0; i--)
            suffix[i] += suffix[i + 1];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(0, 1, suffix, dp);
    }
};