class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        
        vector<vector<int>> g(26);
        for(int i = 0;i < n;i++){
            int c = s[i] - 'a';
            g[c].push_back(i);
        }
        
        int ans = 0;
        for(auto str: words){
            int idx = -1;
            int c = 0;
            for(int i = 0;i < str.length(); i++){
                int c = str[i] - 'a';
                
                if(g[c].empty()){
                    idx = -1;
                    break;
                }
                
                auto x = upper_bound(g[c].begin(), g[c].end(), idx) - g[c].begin();
                
                if(x == g[c].size()){
                    idx = -1;
                    break;
                }
                
                idx = g[c][x];
            }
            
            if(idx != -1) ans++;
        }
        
        return ans;
    }
};