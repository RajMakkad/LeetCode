class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        vector<int> dp(k, 0);
        dp[0] = 1;
        
        for(int i = 0;i<nums.size();i++){
            sum = (sum + nums[i]%k + k) % k;
            ans += dp[sum];
            dp[sum]++;
        }
        
        return ans;
    }
};