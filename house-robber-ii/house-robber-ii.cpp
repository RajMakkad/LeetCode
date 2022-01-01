class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        

        for(int s = 0;s<n;s++){
            for(int e = 0;e<n;e++){
                if(s>e) dp[s][e] = 0;
                else if(s==e) dp[s][e] = nums[s];
                else if(s + 1 == e) dp[s][e] = max(nums[s],nums[e]);
                else dp[s][e] = max(dp[s][e - 1],dp[s][e - 2] + nums[e]);
            }
        }

        if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]); 

        int ans = max(dp[0][n - 2],dp[1][n - 3] + nums[n - 1]);
        return ans;
    }
};