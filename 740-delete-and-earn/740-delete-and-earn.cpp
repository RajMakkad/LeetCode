class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int N = 1e4;
        vector<int> dp(N + 1,0);
        
        for(auto i:nums) dp[i] += i;
        for(int i = 2;i<=N;i++) dp[i] = max(dp[i - 2] + dp[i],dp[i - 1]);
        return dp[N];
    }
};