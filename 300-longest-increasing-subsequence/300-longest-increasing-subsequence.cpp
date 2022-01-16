class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        
        // Dp
//         int ans = 1;
        
//         vector<int> dp(n,1);
        
//         for(int i = 1;i<n;i++){
//             for(int s = 0;s<i;s++){
//                 if(nums[i]>nums[s]) dp[i] = max(dp[i],dp[s] + 1);
//             }
//             ans = max(ans,dp[i]);
//         }
        
//         return ans;
        
        vector<int> s = {nums[0]};
        int ans = 1;
        
        for(int i = 1;i<n;i++){
            if(nums[i]>s.back()) s.push_back(nums[i]);
            else{
                auto index = lower_bound(s.begin(),s.end(),nums[i]) - s.begin();
                s[index] = nums[i];
            }
            
            ans = max(ans,(int)s.size());
        }
        return ans;
    }
};