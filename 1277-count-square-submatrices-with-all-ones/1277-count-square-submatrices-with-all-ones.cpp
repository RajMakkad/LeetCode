class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));

        int ans = 0;

        for(int r = 1;r<=n;r++){
            for(int c = 1;c<=m;c++){

                if(mat[r - 1][c - 1] == 1){
                    int p1 = 0, p2 = 0;

                    for(int k = c - 1;k>0;k--){
                        if(mat[r - 1][k - 1] == 1) p1++;
                        else break;
                    }

                    for(int k = r - 1;k>0;k--){
                        if(mat[k - 1][c - 1] == 1) p2++;
                        else break;
                    }

                    dp[r][c] = min({dp[r - 1][c - 1], p1, p2}) + 1;
                    ans += dp[r][c];
                }
            }
        }

        return ans;
    }
};