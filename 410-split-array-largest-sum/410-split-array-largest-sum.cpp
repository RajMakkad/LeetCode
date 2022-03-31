class Solution{
    int memoization(int n,int m,vector<vector<int>> &dp,vector<int> &nums){
        if(n == 0 and m == 0) return 0;
        if(n == 0 || m == 0) return 1e9;
        if(dp[n][m] != -1) return dp[n][m];

        int sum = 0;
        int op = 1e9;
        for(int i = n;i>0;i--){
            sum += nums[i - 1];
            op = min(op,max(sum,memoization(i - 1,m - 1,dp,nums)));
        }

        return dp[n][m] = op;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,-1));
        return memoization(n,m,dp,nums);
    }
};