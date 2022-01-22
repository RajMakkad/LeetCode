class Solution {
public:
    string removeKdigits(string num, int k){
        int n = num.length();
        vector<vector<int>> dp(n,vector<int>(10,-1));

        dp[n - 1][num[n - 1] - '0'] = n - 1;
        for(int i = n - 2;i>=0;i--){
            dp[i] = dp[i + 1];
            dp[i][num[i] - '0'] = i;
        }

        string s = "";
        for(int i = 0;i<n;i++){
            int e = num[i] - '0';
            for(int d = 0;d<e;d++){
                if(dp[i][d] != -1 and k >= dp[i][d] - i){
                    k = k - (dp[i][d] - i);
                    i = dp[i][d];
                    break;
                }
            }

            if(s.empty() and num[i] == '0') continue;
            s += num[i];
        }

        while(k and s.length()){
            k--;
            s.pop_back();
        }
        if(s.empty()) s += '0';
        return s; 
    }
};

