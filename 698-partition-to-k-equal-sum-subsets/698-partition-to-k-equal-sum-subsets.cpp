class Solution {
    bool memoization(int mask,int sum,int target,int k,vector<int> &nums,vector<int> &dp){
        if(k == 1) return true;
        if(sum > target) return false;
        if(dp[mask] != -1) return dp[mask];

        if(sum == target)
            return dp[mask] = memoization(mask,0,target,k - 1,nums,dp);

        for(int i = 0;i<nums.size();i++){
            int p = 1<<i;
            if((p & mask) == 0) continue;
            if(memoization(mask - p,sum + nums[i],target,k,nums,dp)) return dp[mask] = true;
        }

        return dp[mask] = false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(auto i:nums) sum += i;

        if(k > n || sum%k) return false;
        int mask = (1<<n) - 1;

        vector<int> dp(mask + 1,-1);
        return memoization(mask,0,sum/k,k,nums,dp);
    }
};