class Solution {
    int memoization(int x,int mask,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(x == 0 and mask == 0) return 0;
        if(dp[x][mask] != -1) return dp[x][mask];

        int ans = 1e9;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            int y = 1<<i;
            if((mask & y)){
                ans = min(ans,(nums1[x - 1]^nums2[i]) + memoization(x - 1,mask - y,nums1,nums2,dp));
            }
        }

        return dp[x][mask] = ans;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mask = 1<<n;

        vector<vector<int>> dp(n + 1,vector<int>(mask,-1));
        return memoization(n,mask - 1,nums1,nums2,dp);
    }
};