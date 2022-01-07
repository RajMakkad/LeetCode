class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<m;j++){
                int ws = wordDict[j].size();
                if(i >= ws and dp[i - ws] and s.substr(i - ws,ws) == wordDict[j]) dp[i] = 1;
            }
        }
        
        return dp[n];
    }
};