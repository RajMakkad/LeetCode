class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> p(n,vector<bool>(n,false));
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int gap = 0;gap<n;gap++){
            for(int i = 0;i + gap<n;i++){
                int e = i + gap;
                if(gap == 0){
                    p[i][e] = true;
                    dp[i][e] = 1;
                }
                else if(gap == 1){
                    dp[i][e] = 2;
                    if(s[i] == s[e]){
                        p[i][e] = true;
                        dp[i][e]++;
                    }
                }
                else{
                    dp[i][e] = dp[i][e - 1] + dp[i + 1][e] - dp[i + 1][e - 1];
                    if(s[i] == s[e] and p[i + 1][e - 1]){
                        p[i][e] = true;
                        dp[i][e]++;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};