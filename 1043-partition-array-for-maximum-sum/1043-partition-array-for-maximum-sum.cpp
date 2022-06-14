class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(n + 1, 0);

        for(int i = 1;i <= n;i++){
            int max_ = 0;
            for(int j = i;j >= max(i - k + 1, 1); j--){
                max_ = max(max_, a[j - 1]);
                int sum = max_ * (i - j + 1);

                dp[i] = max(dp[i], sum + dp[j - 1]);
            }
        }

        return dp[n];
    }
};