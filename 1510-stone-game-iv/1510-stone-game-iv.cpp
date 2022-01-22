class Solution{
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1,false);
        dp[1] = true;

        for(int i = 2;i<=n;i++){
            for(int s = 1;s*s <= i;s++){
                dp[i] = dp[i] |(!dp[i - s*s]);
            }
        }

        return dp[n];
    }
}; 