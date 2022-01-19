class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1,0);
        dp[0] = 1;
        
        for(int i = 0;i<= target;i++){
            for(auto &c:nums){
                if(c > i) continue;
                dp[i] += dp[i - c];
            }
        }
        
        return dp[target];
    }
};