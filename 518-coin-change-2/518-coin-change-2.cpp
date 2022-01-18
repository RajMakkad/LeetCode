class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1,0);
        dp[0] = 1;
        
        for(auto &c:coins){
            for(int s = c;s <= amount;s++){
                dp[s] += dp[s - c];
            }
        }
        
        return dp[amount];
    }
};