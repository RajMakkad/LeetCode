class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1,1e9);
        dp[0] = 0;
        
        for(int i = 0;i<n;i++){
            for(int s = coins[i];s<=amount;s++){
                if(dp[s - coins[i]] == 1e9) continue;
                dp[s] = min(dp[s],dp[s - coins[i]] + 1);
            }
        }
        if(dp[amount] == 1e9) dp[amount] = -1;
        return dp[amount];
    }
};