class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e8);
        dp[0] = 0;

        for(int s = 0;s < n - 1;s++){
            for(int e = s + 1;e <= min(n - 1,s + nums[s]);e++){
                dp[e] = min(dp[e],dp[s] + 1);
            }
        }

        return dp[n - 1];
    }
};