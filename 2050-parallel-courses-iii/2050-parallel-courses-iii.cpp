class Solution {
    int dfs(int node,vector<int> &dp,vector<int> g[],vector<int>& time){
        if(dp[node] != -1) return dp[node];

        int ans = 0;
        for(auto i:g[node]){
            ans = max(ans,dfs(i,dp,g,time));
        }

        return dp[node] = ans + time[node - 1];
    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> g[n + 1], d(n + 1,0), t(n + 1,0);
        for(auto i:relations){
            g[i[0]].push_back(i[1]);
            d[i[1]]++;
        }

        int ans = 0;
        
        vector<int> dp(n + 1,-1);
        for(int i = 1;i<=n;i++){
            if(d[i] == 0) ans = max(ans,dfs(i,dp,g,time));
        }

        return ans;
    }
};