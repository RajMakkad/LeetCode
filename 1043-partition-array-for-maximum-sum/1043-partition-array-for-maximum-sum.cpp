class Solution {
    int memoization(int x, int k, vector<int> &dp, vector<int> &a){
        if(x == 0) return 0;
        if(dp[x] != -1) return dp[x];

        int sum = 0;
        int max_ = 0;

        for(int i = x;i >= max(x - k + 1, 1); i--){
            max_ = max(max_, a[i - 1]);
            sum = max_ * (x - i + 1) + memoization(i - 1, k, dp, a);

            dp[x] = max(dp[x], sum);
        }

        return dp[x];
    }
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(n + 1, -1);
        return memoization(n, k, dp, a);
    }
};