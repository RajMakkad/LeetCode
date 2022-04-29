class Solution {
    int memoization(int x,int k,vector<int> &h,vector<vector<int>> &cost,vector<vector<int>> &dp){
        if(x == 0 and k == 0) return 0;
        if(!x || !k) return 1e9;
        if(dp[x][k] != -1) return dp[x][k];

        int ans = 1e9;
        for(int i = x;i>=1;i--)
            ans = min(ans,cost[i - 1][x - 1] + memoization(i - 1,k - 1,h,cost,dp));

        return dp[x][k] = ans;
    }
public:
    int minDistance(vector<int>& h, int k) {
        int n = h.size();
        sort(h.begin(),h.end());
        vector<vector<int>> dp(n + 1,vector<int>(k + 1,-1));
        vector<vector<int>> cost(n,vector<int>(n,0));

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int mid = h[(i + j)/2];
                for(int x = i;x<=j;x++){
                    cost[i][j] += abs(h[x] - mid);
                }
            }
        }
        return memoization(n,k,h,cost,dp);
    }
};