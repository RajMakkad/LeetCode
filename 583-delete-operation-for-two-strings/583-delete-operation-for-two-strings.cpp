class Solution {
public:
    int minDistance(string w1, string w2) {
        int n = w1.length();
        int m = w2.length();

        int dp[n + 1][m + 1];

        for(int i = 0;i <= n;i++){
            for(int j = 0;j <= m;j++){
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else if(w1[i - 1] == w2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
            }
        } 

        return dp[n][m];
    }
};