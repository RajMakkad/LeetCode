#define mod 1000000007
class Solution {
    int memoization(int n,int mask,vector<int> h[],vector<vector<int>> &dp){
        if(mask == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][mask] != -1) return dp[n][mask];

        dp[n][mask] = memoization(n - 1,mask,h,dp)%mod;
        for(auto &i:h[n]){
            int p = 1<<i;
            if((p&mask) == 0) continue;

            dp[n][mask] = (dp[n][mask] + memoization(n - 1,mask - p,h,dp)%mod)%mod;
        }
        return dp[n][mask];
    }
public:
    int numberWays(vector<vector<int>>& hats){
        int n = hats.size();
        vector<int> h[41];
        vector<vector<int>> dp(41,vector<int>((1<<n),-1));

        for(int i = 0;i<n;i++){
            for(auto &p:hats[i]){
                h[p].push_back(i);
            }
        }

        return memoization(40,(1<<n) - 1,h,dp);
    }
};