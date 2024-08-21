class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = costs[0] + dp[i - 1];
            int j;
            for(j = i; j > 0; j--){
                int diff = days[i - 1] - days[j - 1];
                if(diff >= 7)
                    break;
            }
            dp[i] = min(dp[i], dp[j] + costs[1]);
            for(j = i; j > 0; j--){
                int diff = days[i - 1] - days[j - 1];
                if(diff >= 30)
                    break;
            }
            dp[i] = min(dp[i], dp[j] + costs[2]);
        }
        return dp[n];
    }
};