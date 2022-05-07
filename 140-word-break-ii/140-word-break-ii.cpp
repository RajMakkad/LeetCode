class Solution {
    vector<int> vis;
    vector<string> memoization(int x,string str,vector<string> dp[],vector<string> &w){
        int n = str.length();
        if(vis[x]) return dp[x];

        vector<string> sub;
        string s = "";

        for(int i = x;i<n;i++){
            s += str[i];
            for(int j = 0;j<w.size();j++){
                if(w[j] == s){
                    if(i == n - 1){
                        sub.push_back(s);
                        break;
                    }
                    vector<string> v = memoization(i + 1,str,dp,w);
                    for(int p = 0;p<v.size();p++){
                        sub.push_back(s + " " + v[p]);
                    }
                }
            }
        }

        vis[x] = 1;
        return dp[x] = sub;
    }
public:
    vector<string> wordBreak(string s, vector<string>& w) {
        int n = s.length();
        vector<string> dp[n + 1];
        vis.resize(n + 1);
        return memoization(0,s,dp,w);
    }
};