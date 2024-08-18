class Solution {
public:
    int nthUglyNumber(int n) {
        int x = 1, y = 1, z = 1;
        int dp[n + 1];
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int min_ = min({2 * dp[x], 3 * dp[y], 5 * dp[z]});
            if(min_ == 2 * dp[x]) x++;
            if(min_ == 3 * dp[y]) y++;
            if(min_ == 5 * dp[z]) z++;
            dp[i] = min_;
        }
        return dp[n];
    }
};