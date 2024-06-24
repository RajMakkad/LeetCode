class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> dp(n, 0);
        
        for(int i = 0; i < n; i++){
            int flip = 0;
            if(i > 0)
                flip = dp[i - 1];
            if(i > 1)
                flip += dp[i - 2];
            if(((flip & 1) ^ nums[i]) == 0){
                if(i >= n - 2)
                    return -1;
                dp[i]++;
                ans++;
            }
        }
        
        return ans;
    }
};