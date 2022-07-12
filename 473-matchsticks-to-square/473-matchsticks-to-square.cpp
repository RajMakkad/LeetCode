class Solution {
    bool memoization(int mask, int sub, int &sum, int &n, vector<int> &dp, vector<int> &m){
        if(mask == 0) return true;
        if(sub == sum) return dp[mask] = memoization(mask, 0, sum, n, dp, m);
        
        if(dp[mask] != -1) return dp[mask];
        
        for(int i = 0;i < n;i++){
            int p = 1 << i;
            if((mask & p) != 0 and sub + m[i] <= sum and memoization(mask ^ p, sub + m[i], sum, n, dp, m)){
                return dp[mask] = 1;
            }
        }
        
        return dp[mask] = 0;
    }
public:
    bool makesquare(vector<int>& m) {
        int n = m.size();
        int mask = 1<<n;
        
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += m[i];
        }
        
        if(sum % 4 != 0) return false;
        
        sum /= 4;
        
        vector<int> dp(mask, -1);
        
        return memoization(mask - 1, 0, sum, n, dp, m);
    }
};