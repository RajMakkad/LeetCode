class Solution {
    int memoization(int src,int dst,int k,vector<pair<int,int>> g[],vector<vector<int>> &dp){
        if(src == dst) return 0;
        if(k < 0) return 1e9;
        if(dp[src][k] != -1) return dp[src][k];
        int res = 1e9;

        for(auto &i:g[src]){
            int next = memoization(i.first,dst,k - 1,g,dp);
            if(next != 1e9) res = min(res,next + i.second);
        }

        return dp[src][k] = res;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<int>> dp(n,vector<int>(k + 1,-1));
        vector<pair<int,int>> g[n];

        for(auto &i:flights){
            g[i[0]].push_back({i[1],i[2]});
        }

        memoization(src,dst,k,g,dp);
        return dp[src][k] != 1e9 ? dp[src][k] : -1;
    }
};