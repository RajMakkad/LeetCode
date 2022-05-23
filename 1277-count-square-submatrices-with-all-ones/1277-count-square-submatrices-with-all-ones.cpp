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

                    dp[r][c] = min({dp[r - 1][c - 1], dp[r - 1][c], dp[r][c - 1]}) + 1;
                    ans += dp[r][c];
                }
            }
        }

        return ans;
    }
};