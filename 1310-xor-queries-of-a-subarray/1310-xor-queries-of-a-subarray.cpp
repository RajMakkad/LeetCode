class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        int n = a.size();
        int m = q.size();
        
        vector<long long> dp(n + 1,0);
        vector<int> ans(m);
        for(int i = 1;i<=n;i++){
            dp[i] = a[i - 1] ^ dp[i - 1];
        }

        for(int i = 0;i<m;i++){
            ans[i] = dp[q[i][1] + 1] ^ dp[q[i][0]];
        }

        return ans;
    }
};