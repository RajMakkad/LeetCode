class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n = w.size();
        vector<vector<int>> dp(n,vector<int>(26,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<w[i].size();j++){
                int c = w[i][j] - 'a';
                dp[i][c]++;
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                bool pass = true;
                for(int k = 0;k<26;k++){
                    if(dp[i][k] > 0 and dp[j][k] > 0){
                        pass = false;
                        break;
                    }
                }

                if(pass) ans = max(ans,(int)(w[i].size() * w[j].size()));
            }
        }

        return ans;
    }
};