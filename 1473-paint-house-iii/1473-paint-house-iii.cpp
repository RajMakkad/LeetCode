class Solution {
    int dp[100][21][101];
    int memoization(int x, int c, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(t > target) return 1e9;
        if(x == m){
            if(t == target) return 0;
            return 1e9;
        }
        
        if(dp[x][c][t] != -1) return dp[x][c][t];
        if(houses[x] != 0) return dp[x][c][t] = memoization(x + 1, houses[x], (c == houses[x] ? t : t + 1), houses, cost, m, n, target);
        
        int ans = 1e9;
        
        for(int i = 0;i < n;i++){
            int sum = cost[x][i] + memoization(x + 1, i + 1, (c == (i + 1) ? t: t + 1), houses, cost, m, n, target);
            ans = min(ans, sum);
        }
        
        return dp[x][c][t] = ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        memoization(0, 0, 0, houses, cost, m, n, target);
        
        return dp[0][0][0] >= 1e9 ? -1: dp[0][0][0];
    }
};