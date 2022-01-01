class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n + 2][n + 2];
        memset(dp,0,sizeof(dp));
        
        for(int gap = 0;gap<n;gap++){
            for(int start = 1;start + gap<=n;start++){
                int end = start + gap;
                for(int i = start;i<=end;i++){
                    int x = nums[i - 1];
                    if(start > 1) x *= nums[start - 2];
                    if(end < n) x *= nums[end];
                    dp[start][end] = max(dp[start][end],dp[start][i - 1] + x + dp[i + 1][end]);
                }
            }
        }
        
        return dp[1][n];
    }
};