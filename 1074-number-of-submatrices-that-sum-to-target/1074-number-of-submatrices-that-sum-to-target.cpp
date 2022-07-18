class Solution {
    int solve(vector<int> &v, int n, int &sum){
        unordered_map<int, int> mp;
        int sub = 0, ans = 0;
        
        for(int i = 0; i < n;i++){
            sub += v[i];
            int need = sub - sum;
            ans += mp[need];
            mp[sub]++;
        }
        
        return ans;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        
        vector<vector<int>> dp(n + 1,vector<int>(m + 1, 0));
        for(int r = 1;r <= n;r++){
            for(int c = 1;c <= m;c++){
                dp[r][c] = dp[r][c - 1] + mat[r - 1][c - 1];
            }
        }
        
        for(int c1 = 1;c1 <= m;c1++){
            for(int c2 = c1;c2 <= m;c2++){
                
                vector<int> v(n + 1);
                for(int r = 1;r <= n;r++){
                    v[r] = dp[r][c2] - dp[r][c1 - 1];
                }
                
                ans += solve(v, n + 1, t);
            }
        }
        return ans;
    }
};