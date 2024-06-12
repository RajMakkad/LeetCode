class Solution {
    int memoization(int &n, int mask, int session, int &sessionTime, vector<int> &tasks, vector<vector<int>> &dp){
        if(session > sessionTime)
            return INT_MAX;
        if(mask == 0)
            return 1;
        if(dp[session][mask] != -1)
            return dp[session][mask];
        int ans = INT_MAX;
        for(int i = 0;i < n; i++){
            if(((1 << i) & mask) > 0){
                int cursession = memoization(n, (mask ^ (1 << i)), session + tasks[i], sessionTime, tasks, dp);
                int newsession = memoization(n, (mask ^ (1 << i)), tasks[i], sessionTime, tasks, dp);
                newsession += newsession == INT_MAX ? 0 : 1;
                ans = min({ans, cursession, newsession});
            }
        }
        return dp[session][mask] = ans;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int mask = (1 << n) - 1;
        vector<vector<int>> dp(sessionTime + 1, vector<int>(mask + 1, -1));
        return memoization(n, mask, 0, sessionTime, tasks, dp);
    }
};