class Solution {
public:
    int maxProfit(int k, vector<int>& prices){
        if(prices.empty()) return 0;
        
        int n = prices.size();
        int ans = 0;
        int dp[k + 1][n];

        for(int i = 0;i<=k;i++){
            int max_p = -1e9;
            for(int d = 0;d<n;d++){
                if(i == 0 || d == 0) dp[i][d] = 0;
                else{
                    max_p = max(max_p,dp[i - 1][d - 1] - prices[d - 1]);
                    dp[i][d] = max(dp[i][d - 1],max_p + prices[d]);
                }
            }
            ans = max(ans,dp[i][n - 1]);
        }

        return ans;
    }
};