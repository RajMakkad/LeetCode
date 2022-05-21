class Solution {
    int memoization(int x,int mask,int sum,int k,vector<int> &dp,vector<int> &a){
        int n = a.size();
        if(mask == 0) return 1;
        if(sum == k){
            return memoization(0,mask,0,k,dp,a);
        }

        if(sum > k || x >= n) return dp[mask] = 0;
        if(dp[mask] != -1) return dp[mask];

        int optimal = 0;

        for(int i = x;i<n;i++){
            int p = 1<<i;
            if((p & mask) and sum + a[i] <= k and memoization(i + 1,mask - p,sum + a[i],k,dp,a)) optimal |= 1;
            if(memoization(i + 1,mask,sum,k,dp,a)) optimal |= 1;
        }

        return dp[mask] = optimal;
    }
public:
    bool makesquare(vector<int>& a) {
        int n = a.size();
        long long sum = 0;
        for(int i = 0;i<n;i++) sum += a[i];
        
        if(sum % 4) return false;
        sum /= 4;
        
        int mask = 1<<n;
        vector<int> dp(mask,-1);

        return memoization(0,mask - 1,0,sum,dp,a);
    }
};