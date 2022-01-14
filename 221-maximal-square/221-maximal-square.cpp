class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));

        for(int r = 1;r<=n;r++){
            for(int c = 1;c<=m;c++){
                if(mat[r - 1][c - 1] == '1'){
                    int l = 0;
                    int b = 0;

                    for(int i = r - 1;i>0;i--){
                        if(mat[i - 1][c - 1] == '1') l++;
                        else break;
                    }

                    for(int i = c - 1;i>0;i--){
                        if(mat[r - 1][i - 1] == '1') b++;
                        else break;
                    }

                    dp[r][c] = min({l,b,dp[r - 1][c - 1]}) + 1;
                    ans = max(ans,dp[r][c]*dp[r][c]);
                }
            }
        }

        return ans;
    }
};