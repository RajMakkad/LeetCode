class Solution {
    vector<string> memoization(int idx, string &s, vector<string> &wordDict, vector<string> dp[], vector<int> &vis){
        if(vis[idx])
            return dp[idx];
        int n = s.length();
        vector<string> ans;
        
        string sub = "";
        for(int i = idx; i <= n; i++){
            sub += s[i];
            for(auto w: wordDict){
                if(sub == w) {
                    if(i == n - 1)
                        ans.push_back(sub);
                    else {
                        vector<string> mem = memoization(i + 1, s, wordDict, dp, vis);
                        for(auto m: mem)
                            ans.push_back(sub + " " + m);
                    }
                }
            }
        }
        
        vis[idx] = 1;
        return dp[idx] = ans;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<string> dp[n + 1];
        vector<int> vis(n, 0);
        return memoization(0, s, wordDict, dp, vis);
    }
};