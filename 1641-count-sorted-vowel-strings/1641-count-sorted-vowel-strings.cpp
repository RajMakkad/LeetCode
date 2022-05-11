// class Solution {
//     int memoization(int n,int x,vector<vector<int>> &dp){
//         if(n == 0) return 1;
//         if(dp[n][x] != -1) return dp[n][x];

//         int sum = 0;

//         for(int i = x;i<5;i++){
//             sum += memoization(n - 1,i,dp);
//         }

//         return dp[n][x] = sum;
//     }
// public:
//     int countVowelStrings(int n) {
//         vector<vector<int>> dp(n + 1,vector<int>(5,-1));
//         return memoization(n,0,dp);
//     }
// };

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1,vector<int>(6,0));

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=5;j++){
                if(i == 1) dp[i][j] = 1;
                else{
                    for(int k = 1;k<=j;k++){
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1;i<=5;i++) ans += dp[n][i];

        return ans;
        
    }
};